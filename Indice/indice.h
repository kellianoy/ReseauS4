#ifndef INDICE_H
#define INDICE_H
#include "graphe.h"

class Indice
{
    public:

        Indice();
        Indice(double critere);
        Indice(Graphe* G, Sommet* S);
        virtual ~Indice();

        //Get
        double getCritere(){return m_critere;}
        Graphe* getGraphe(){return m_graphe;}
        Sommet* getSommet(){return m_sommet;}

        //Set
        void setCritere(double c) {m_critere=c;}
    protected:

    double m_critere;

    Graphe* m_graphe;
    Sommet* m_sommet;

};

#endif // INDICE_H
