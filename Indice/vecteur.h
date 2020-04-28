#ifndef VECTEUR_H
#define VECTEUR_H

#include "indice.h"


class Vecteur : public Indice
{
    public:
        Vecteur();
        Vecteur(Graphe* G, Sommet* S);
        ~Vecteur();

    private:
};

#endif // VECTEUR_H
