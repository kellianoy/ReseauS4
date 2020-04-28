#include "indice.h"

Indice::Indice()
{
    //ctor
}

Indice::Indice(double critere) : m_critere{critere}
{
    //ctor
}

Indice::Indice(Graphe * mongraphe) : m_graph{mongraphe}
{
}

Indice::~Indice()
{
    //dtor
}
