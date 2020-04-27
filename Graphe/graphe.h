#ifndef GRAPHE_H
#define GRAPHE_H
#include "arete.h"

class Graphe
{
    public:

        Graphe();
        ~Graphe();

        void lecture_topo(std::string fichier);

        //Get
        int getTaille() { return m_taille; }
        int getOrdre() { return m_ordre; }
        bool getOrientation() { return m_orientation; }
        std::vector<Sommet*> getVectS() { return m_vectS; }
        std::vector<Arete*> getVectA() { return m_vectA; }

        //Set
        void setTaille(int val) { m_taille = val; }
        void setOrdre(int val) { m_ordre = val; }
        void setOrientation(bool val) { m_orientation = val; }

        Sommet* seekSommet(int id);
        Arete* seekArete(int id1, int id2);
        Arete* seekAreteId(int id);
        void lecture_poids(std::string fichier);

    private:

        int m_taille;
        int m_ordre;
        bool m_orientation; //false : non orienté - true : orienté
        std::vector<Sommet*> m_vectS;
        std::vector<Arete*> m_vectA;
};

#endif // GRAPHE_H
