#ifndef PROXIMITE_H
#define PROXIMITE_H

#include "indice.h"


class Proximite : public Indice
{
    public:
        Proximite();
        Proximite(Graphe* G, Sommet* S);
        ~Proximite();
        void calculIndice();
        double normalisation();

    private:
};

#endif // PROXIMITE_H
