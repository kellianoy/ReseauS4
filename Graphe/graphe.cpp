#include "graphe.h"


Graphe::Graphe()
{
    //ctor
}



Graphe::~Graphe()/** le destructeur est cass�**/
{
    for (auto s : m_vectS)
        delete s;

    for (auto a : m_vectA)
        delete a;
}


void Graphe::lecture_topo(std::string fichier)
{
    int ordre = 0 , orientation = 0, id = 0 ;

    //v�rifier que le fichier est bien un fichiier topo
    if(fichier.compare(fichier.size()- 8, 8, "topo.txt") != 0 )
        throw std::runtime_error("Il ne s'agit pas d'un fichier topologie.");

    std::ifstream ifs{fichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );

    ifs >> orientation ;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme avec l'orientation.");
    if(orientation == 1)
        m_orientation = true ;
    else m_orientation = false ;

    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme avec l'ordre.");
    m_ordre=ordre;

    for(int i=0;i<ordre;i++)
    {
        ifs >> id;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme avec l'id.");

        std::string nom ;
        ifs >> nom ;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme avec le nom.");

        int x = 0 , y = 0 ;
        ifs >> x >> y ;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme avec les coordonn�es.");

         m_vectS.push_back(new Sommet(id, nom, x, y, this));

    }

    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme avec la taille");

    m_taille=taille;
    for (int i=0; i<taille; ++i)
    {
        int id1, id2;
        ifs >> id ;
        ifs >> id1;
        ifs >> id2;
        m_vectA.push_back(new Arete(id, seekSommet(id1), seekSommet(id2)));
        seekSommet(id1)->pushAdjacent(seekSommet(id2));
        seekSommet(id2)->pushAdjacent(seekSommet(id1));
    }

}

Sommet* Graphe::seekSommet(int id)
{
    if (m_vectS.size())
        for (auto it : m_vectS)
            if (id==it->getIndice())
                return it;
    return nullptr;
}


/** renvoie ar�te affilier � deux sommets**/
Arete* Graphe::seekArete(int id1, int id2)
{
    if (m_vectA.size())
    {
        for (auto it : m_vectA)
        {
            if (((id1==it->getS1()->getIndice()) && (id2==it->getS2()->getIndice()))||((id1==it->getS2()->getIndice()) && (id2==it->getS1()->getIndice())))
            {
               return it;
            }
        }
    }
    return nullptr;
}

/** renvoie ar�te avec l'ID correspondant**/
Arete* Graphe::seekAreteId(int id)
{
    if (m_vectA.size())
        for (auto it : m_vectA)
            if (id==it->getIndice()) /** penser � changer le nom d'indice **/
                return it;
    return nullptr;
}


/** charge les poids des ar�te**/
void Graphe::lecture_poids(std::string fichier)
{
    if (fichier!="")
    {
        std::ifstream ifs{fichier};
        if (!ifs)
            throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );


        int taille;
        ifs >> taille;
        if ( ifs.fail() || taille!=m_taille)
        {
                throw std::runtime_error("Probleme avec la taille");
        }

        for (int i=0; i<taille; ++i)
        {
            int id, value;
            ifs >> id;
            ifs >> value;
        seekAreteId(id)->setPoids(value);
        }
    }
}

void Graphe::affichageTextuel()
{
    std::cout << "__________Affichage du Graphe___________\n" << std::endl;
    std::cout << "Orientation : " << m_orientation << std::endl;
    std::cout << "Ordre : " << m_ordre << std::endl;
    std::cout << std::endl;
    std::cout << "Liste des sommets : " << std::endl;
    for (auto s : m_vectS)
    {
        std::cout << "Sommets : " << s->getIndice() << " | Nom : " << s->getNom() << " | Adjacents : ";
        for (auto a : s->getVectAdj())
            std::cout << " "  << a->getNom();
        std::cout << std::endl;
    }


    std::cout << std::endl;
    std::cout << "Liste des aretes : " << std::endl;
    for (auto a : m_vectA)
        std::cout << "Arete : " << a->getIndice() << " | S1 : " << a->getS1()->getNom() << " | S2 : " << a->getS2()->getNom() << std::endl;
}

void Graphe::sauvegardeIndice()
{
    std::ofstream ofs{"Indice.txt"};
    ofs.precision(3);
    if (!ofs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture indice.txt" );

    for(auto s : m_vectS)
        s->sauvegardeIndice(ofs);
}





                             /**Dijkstra**/

std::vector<std::pair<Sommet*,double>> Graphe:: dijkstra(Sommet* depart)
{


    int parcours=-1;///variable buffer qui contient l'�lement avec le poid le plus faible
    int marquage=0;///nb de sommet marquer
    int cpt=0;



    /** reset des marquage de tout le monde et cr�ation du vecteur de pair qui associe � un ID un sommet ascendant et le poid de d�but jusqu'au sommet s**/
    std::vector<std::pair<Sommet*,double>> AscendantDistance;
    for(const auto it:m_vectS)
    {
        AscendantDistance.push_back(std::make_pair(nullptr,INT_MAX));///pour obtenir DOUBLE_MAX il faut rajouter une bilbioth�ques donc un int max sera suffisant
        it->setMarquage(0);
    }
    AscendantDistance[depart->getIndice()].second=0;///on met la distance du d�but � lui m�me � 0

    /** dijkstra pour de vrai **/
    while(marquage<m_ordre)
    {
         ///probl�me parcourss ne doit pas �tre d�j� marqu� sinon �a casse tout par cons�quent on doit choisir un parcours non marqu�
        cpt=0;
        parcours=-1;
        ///choix de l'indice parcours, on prend le premier qui n'est pas marqu�
        do
        {
            if( ! m_vectS[cpt]->getMarquage())
            {
                parcours=cpt;
            }
            cpt++;


        }while(parcours==-1);

       ///recherche de l'�l�ment avec la plus petite distance, parcours contient l'id de l'elt avec le plus petit poids
        for(int i=0;i<m_ordre;i++)
        {
            if(AscendantDistance[i].second<AscendantDistance[parcours].second && !m_vectS[i]->getMarquage())
            {
                parcours=i;
            }
        }

        ///marquage de l'�lement
        m_vectS[parcours]->setMarquage(1);
        marquage+=1;

        ///recherche des distances des sommets adjacent et remplacement dans le tableau si leur distance avec d�but est plus petite
        for(const auto elt : m_vectS[parcours]->getVectAdj())
        {


            if(! ( elt->getMarquage() ) && ( AscendantDistance[elt->getIndice()].second > AscendantDistance[parcours].second+seekArete(parcours,elt->getIndice())->getPoids()) )
            {
                AscendantDistance[elt->getIndice()].first=m_vectS[parcours];
                AscendantDistance[elt->getIndice()].second=AscendantDistance[parcours].second+seekArete(parcours,elt->getIndice())->getPoids();
            }
        }



    }

    /**for(size_t i =0;i<AscendantDistance.size();++i)
    {

        std::cout<<m_vectS[i]->getNom()<<" =>  "<<AscendantDistance[i].second<<std::endl;
    }**/

return AscendantDistance;
}
