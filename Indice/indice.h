#ifndef INDICE_H
#define INDICE_H
#include "graphe.h"

class Indice
{
    public:

        Indice();
        Indice(double critere);
        virtual ~Indice();

        //Get
        double getCritere(){return m_critere;}

    protected:

    double m_critere;

};

#endif // INDICE_H
