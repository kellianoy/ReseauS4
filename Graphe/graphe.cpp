#include "graphe.h"
#include "arete.h"

Graphe::Graphe()
{
    //ctor
}



Graphe::~Graphe()
{
    for (auto s : m_vectS)
        delete s;

    for (auto a : m_vectA)
        delete a;

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

         m_vectS.push_back(new Sommet(id, nom, x, y));

    }

    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme avec la taille");

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

