#include "intermediarite.h"

Intermediarite::Intermediarite()
{
    //ctor
}

Intermediarite::Intermediarite(Graphe* G, Sommet* S) : Indice(G, S)
{
    //ctor
}


Intermediarite::~Intermediarite()
{
    //dtor
}

void Intermediarite::afficher()
{
    std::cout << "    -> Centralite d'intermediarite : " << m_critere << " | normalise : " << normalisation() << std::endl ;
}
