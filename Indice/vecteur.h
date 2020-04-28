#ifndef VECTEUR_H
#define VECTEUR_H

#include "indice.h"


class Vecteur : public Indice
{
    public:
        Vecteur();
        Vecteur(Graphe* G, Sommet* S);
        ~Vecteur();

        void calculIndice();

        double normalisation() {return 0.2 ; }
    private:
};

#endif // VECTEUR_H
