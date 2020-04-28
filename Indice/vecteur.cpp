#include "vecteur.h"

Vecteur::Vecteur()
{
    //ctor
}

Vecteur::Vecteur(Graphe* G, Sommet* S) : Indice(G, S)
{
    //ctor
}

Vecteur::~Vecteur()
{
    //dtor
}

/*void Vecteur::calculIndice()
{
    int somme=0:
    double A=0;

    //Initialisation
    for (auto s : m_graphe->getVectS())
        s->getVectI()[1]->setCritere(1);
    //Boucle principale
    do
    {
        for (auto s : m_graphe->getVectS())

    }
    while();
}*/
