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

        virtual void calculIndice()=0;
        virtual double normalisation()=0;
        virtual void afficher()=0;
        virtual void sauvegarder(std::ofstream &ofs) {ofs << " " << m_critere << " " << normalisation() << " -"; } ;

    protected:

    double m_critere;

    Graphe* m_graphe;
    Sommet* m_sommet;

};

#endif // INDICE_H
