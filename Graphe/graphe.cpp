#include "graphe.h"
#include "indice.h"


Graphe::Graphe()
{
}

Graphe::~Graphe()
{

}

//Permet de lire un fichier topologique afin de charger un graphe
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

//test pour savoir si le graphe est vide ou non
bool Graphe::grapheVide()
{
            if(m_vectS.size() == 0 )
                return false ;
            else
                return true ;
}

//test pour savoir si deux graphes sont identiques
bool Graphe::grapheIdentique(Graphe* Copie)
 {
            if(Copie->getVectA().size() != m_vectA.size())
                return true ;
            else return false ;
}

//renvoie un sommet du graphe correspondant à l'id
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

//Supprime une arête du graphe et donc les sommets adjacents
void Graphe::deleteArete(int id)
{
    if (m_vectA.size())
        for (size_t i = 0 ; i<m_vectA.size() ; ++i)
            if (id==m_vectA[i]->getIndice()) /** penser � changer le nom d'indice **/
            {
                m_vectA[i]->getS1()->deleteAdj(m_vectA[i]->getS2());
                m_vectA[i]->getS2()->deleteAdj(m_vectA[i]->getS1());
                m_vectA.erase(m_vectA.begin()+i);
                m_taille-=1;
                break;
            }

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

//affiche tous les sommets d'un graphe
void Graphe::affichageSommets()
{
    for (auto s : m_vectS)
    {
        std::cout << "Sommets : " << s->getIndice() << " | Nom : " << s->getNom() << " | Adjacents : ";
        for (auto a : s->getVectAdj())
            std::cout << " "  << a->getNom();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//affiche toutes les aretes d'un graphe
void Graphe::affichageAretes()
{
    for (auto a : m_vectA)
        std::cout << "Arete : " << a->getIndice() << " | S1 : " << a->getS1()->getNom() << " | S2 : " << a->getS2()->getNom() << std::endl;
    std::cout << std::endl;
}

//affiche arêtes & sommets
void Graphe::affichageTextuel()
{
    std::cout << "__________Affichage du Graphe___________\n" << std::endl;
    std::cout << "Orientation : " << m_orientation << std::endl;
    std::cout << "Ordre : " << m_ordre << std::endl;
    std::cout << std::endl;
    affichageSommets();
    affichageAretes();
}

///sauvegarde de tous les indices dans un fichier texte
void Graphe::sauvegardeIndice()
{
    std::ofstream ofs{"Indice.txt"};
    ofs.precision(3);
    if (!ofs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture indice.txt" );

    for(auto s : m_vectS)
        s->sauvegardeIndice(ofs);
}

///affichage de tous les indices après calcul
 void Graphe::afficherIndice()
 {
     for(auto s : m_vectS)
        s->afficherIndice();
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
        marquage += 1;

        ///recherche des distances des sommets adjacent et remplacement dans le tableau si leur distance avec d�but est plus petite
        for(const auto elt : m_vectS[parcours]->getVectAdj())
        {

            if (seekArete(parcours,elt->getIndice())!=nullptr)
                if(! ( elt->getMarquage() ) && ( AscendantDistance[elt->getIndice()].second > AscendantDistance[parcours].second+seekArete(parcours,elt->getIndice())->getPoids()) )
                {
                    AscendantDistance[elt->getIndice()].first=m_vectS[parcours];
                    AscendantDistance[elt->getIndice()].second=AscendantDistance[parcours].second+seekArete(parcours,elt->getIndice())->getPoids();
                }
        }



    }
return AscendantDistance;
}

///Permet de retrouver la valeur pour le critère
Valeur* trouverValeur(std::vector<Valeur*> &valeurS, Sommet* atrouver)
{
    for(size_t i = 0 ; i < valeurS.size() ; i++)
    {
        if(valeurS[i]->s_ref == atrouver)
            return valeurS[i] ;
    }
    return nullptr ;
}

                      /**Dijksra pour Brandes**/

std::stack<Valeur*> Graphe::BFSmodif(std::vector<Valeur*> & valeurS, Sommet * base)
{
    std::stack<Valeur*> parcours ;
    std::queue<Valeur *> file ;
    Valeur * refer = trouverValeur(valeurS, base);
    Valeur * suivant = nullptr ;
    Arete * lien_refer_suivant = nullptr ;

    file.push(refer);

    while(! file.empty())
    {
        //on récupère la première valeur dans la file
        refer = file.front();
        file.pop();
        //si on l'a déjà checker on a déjà trouvé le plus court chemin
        if(refer->s_ref->getMarquage() != 1)
            parcours.push(refer);
        //on regarde tous les adjacents
        for(auto s : refer->s_ref->getVectAdj())
        {
            suivant = trouverValeur(valeurS, s);
            //on récupère la valeur de l'arrete entre les deux
            lien_refer_suivant = seekArete(refer->s_ref->getIndice(), suivant->s_ref->getIndice());
            //on regarde si le sommet n'a jamais été ajouter, on initialise sa distance à la base
            if(suivant->s_distance == INT_MAX)
            {
                suivant->s_distance = refer->s_distance + lien_refer_suivant->getPoids() ;
                file.push(suivant);
            }
            //si la distance est la plus petite alors c'est bon c'est un prédecesseur
            if(suivant->s_distance == refer->s_distance + lien_refer_suivant->getPoids() )
            {
                suivant->s_nbpluscourt = refer->s_nbpluscourt + suivant->s_nbpluscourt;
                suivant->s_predecesseur.push_back(refer);
            }
            if(suivant->s_distance < refer->s_distance + lien_refer_suivant->getPoids())
            {
                suivant->s_nbpluscourt = refer->s_nbpluscourt ;
                suivant->s_distance = refer->s_distance + lien_refer_suivant->getPoids();
                suivant->s_predecesseur.clear();
                suivant->s_predecesseur.push_back(refer);
            }
        }
    }
    //on retourne le parcours pour analyse
    return parcours ;
}

//Si le sommet est dans le vecteur, on retourne 0 sinon on retourne 1
bool testVecteur(Sommet* s, std::vector<Sommet*> colored)
{
    for(auto c : colored)
        if (s->getIndice()==c->getIndice())
            return 0;

    return 1;
}

//Parcours bfs
void Graphe::bfs(Sommet* initial, std::vector<Sommet*>& colored)
{
    std::queue<Sommet*> file;
    //On remplit la file
    file.push(initial);
    colored.push_back(initial);
    while (file.size())
    {
        for (auto it : file.front()->getVectAdj())
            if (testVecteur(it, colored)) //Si le sommet n'a pas déjà été pris
            {
                file.push(it);
                colored.push_back(it);
            }
        file.pop();
    }
}

//renvoie un sommet non présent dans le vecteur de sommet
Sommet* Graphe::PasFait(const std::vector<Sommet*> faits)
{
    bool existe=0;
    for (auto t : m_vectS)
    {
        for (auto f : faits)
        {
            if (t->getIndice()==f->getIndice())
            {
                existe=1;
                break;
            }
        }
        if (!existe)
            return t;
        else
            existe=0;
    }
    return 0;
}

//teste la connexité d'un graphe (composantes connexes)
void Graphe::connexite()
{
    std::vector<Sommet*> colored;
    int i=0;
    Sommet* Si=m_vectS[0];
    do
    {
        std::vector<Sommet*> temp;
        ++i;
        bfs(Si, temp);
        std::cout << "Composante connexe " << i <<std::endl;
        std::cout << "Sommets composites : ";
        for (auto c : temp)
        {
            colored.push_back(c);
            std::cout << c->getNom() << " ";
        }
        std::cout<<std::endl;
        Si=PasFait(colored);

    }
    while(colored.size()!=m_vectS.size());

}

//Calcul des indices
void Graphe::calculIndice()
{
    for (auto s : m_vectS)
    {
        s->getVectI()[0]->calculIndice();
        s->getVectI()[2]->calculIndice();
    }

    ResetMarquage();
    for(auto s : m_vectS)
        s->getVectI()[3]->setCritere(0);

    for (auto s : m_vectS)
        s->getVectI()[3]->calculIndice();

    m_vectS[0]->getVectI()[1]->calculIndice();
}

