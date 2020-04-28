#include "centralite.h"

Centralite::Centralite()
{
    //ctor
}

Centralite::Centralite(double c) : Indice(c)
{
    //ctor
}

Centralite::~Centralite()
{
    //dtor
}

void Centralite::calculIndice()
{
    m_critere = m_sommet->getVectAdj().size();
}

double Centralite::normalisation()
{
    return m_critere/(m_graphe->getVectS().size() - 1 );
}
