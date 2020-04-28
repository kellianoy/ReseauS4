#include "graphe.h"


Graphe::Graphe()
{
    //ctor
}



Graphe::~Graphe()/** le destructeur est cassé**/
{
    /*
    for (auto s : m_vectS)
        delete s;

    for (auto a : m_vectA)
        delete a;*/

}


void Graphe::lecture_topo(std::string fichier)
{
    int ordre = 0 , orientation = 0, id = 0 ;

    //vérifier que le fichier est bien un fichiier topo
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
            throw std::runtime_error("Probleme avec les coordonnées.");

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


/** renvoie arête affilier à deux sommets**/
Arete* Graphe::seekArete(int id1, int id2)
{
    if (m_vectA.size())
        for (auto it : m_vectA)
            if ((id1==it->getS1()->getIndice()) && (id2==it->getS2()->getIndice()))
                return it;
    return nullptr;
}

/** renvoie arête avec l'ID correspondant**/
Arete* Graphe::seekAreteId(int id)
{
    if (m_vectA.size())
        for (auto it : m_vectA)
            if (id==it->getIndice()) /** penser à changer le nom d'indice **/
                return it;
    return nullptr;
}


/** charge les poids des arête**/
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
        std::cout << "Sommets : " << s->getIndice() << " | Nom : " << s->getNom() << std::endl;
    std::cout << std::endl;
    std::cout << "Liste des aretes : " << std::endl;
    for (auto a : m_vectA)
        std::cout << "Arete : " << a->getIndice() << " | S1 : " << a->getS1()->getNom() << " | S2 : " << a->getS2()->getNom() << std::endl;
}
