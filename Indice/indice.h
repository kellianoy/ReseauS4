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

<<<<<<< Updated upstream
=======
        //Set
        void setCritere(double c) {m_critere=c;}

        virtual void calculIndice()=0;
        virtual double normalisation()=0;
        void sauvegarder(std::ofstream &ofs) {ofs << m_critere << " " << normalisation(); } ;

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
    protected:

    double m_critere;

    Graphe* m_graphe;
    Sommet* m_sommet;

};

#endif // INDICE_H
