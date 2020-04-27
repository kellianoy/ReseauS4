#ifndef GRAPHE_H
#define GRAPHE_H
#include "arete.h"

class Graphe
{
    public:

        Graphe();
        ~Graphe();

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


    private:

        int m_taille;
        int m_ordre;
        bool m_orientation;
        std::vector<Sommet*> m_vectS;
        std::vector<Arete*> m_vectA;
};

#endif // GRAPHE_H
