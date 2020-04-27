#ifndef ARETE_H
#define ARETE_H
#include "sommet.h"

class Arete
{
    public:

        Arete();
        ~Arete();

        //Get
        int getIndice() { return m_indice; }
        int getPoids() { return m_poids; }
        Sommet* getS1() { return m_s1; }
        Sommet* getS2() { return m_s2; }

        //Set
        void setIndice(int val) { m_indice = val; }
        void setPoids(int val) { m_poids = val; }

    private:

        int m_indice;
        int m_poids;
        Sommet* m_s1;
        Sommet* m_s2;
};

#endif // ARETE_H
