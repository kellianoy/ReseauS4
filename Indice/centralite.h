#ifndef CENTRALITE_H
#define CENTRALITE_H
#include "indice.h"


class Centralite : public Indice
{
    public:
        Centralite();
        Centralite(Graphe* G, Sommet* S);
        ~Centralite();

    private:
};

#endif // CENTRALITE_H
