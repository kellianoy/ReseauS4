#ifndef ARETE_H
#define ARETE_H
#include "sommet.h"

class Arete
{
    public:

        Arete();
        Arete(int id, Sommet* s1, Sommet* s2);
        ~Arete();

        //Get
        int getIndice() { return m_indice; }
        double getPoids() { return m_poids; }
        Sommet* getS1() { return m_s1; }
        Sommet* getS2() { return m_s2; }
        double getFlux() { return m_flux; }

        //Set
        void setIndice(int val) { m_indice = val; }
        void setPoids(double val) { m_poids = val; }
        void setFlux(double flux) {m_flux=flux;}

        //Dessin
        void dessin(Svgfile& svgout, bool orientation, bool fordfulkerson=0) const;

    private:

        double m_flux;
        int m_indice;
        double m_poids;
        Sommet* m_s1;
        Sommet* m_s2;
};

#endif // ARETE_H
