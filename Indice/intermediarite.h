#ifndef INTERMEDIARITE_H
#define INTERMEDIARITE_H
#include "indice.h"


class Intermediarite : public Indice
{
    public:
        Intermediarite();
        Intermediarite(Graphe* G, Sommet* S);
        ~Intermediarite();
        void calculIndice(){std::cout << " calcul :)"; }
    private:
};

#endif // INTERMEDIARITE_H
