#include "indice.h"

Indice::Indice()
{
    //ctor
}

Indice::Indice(double critere) : m_critere{critere}
{
    //ctor
}

Indice::Indice(Graphe* G, Sommet* S) : m_graphe{G}, m_sommet{S}
{

}

Indice::~Indice()
{
    //dtor
}
