#include "centralite.h"

Centralite::Centralite()
{
    //ctor
}

Centralite::Centralite(Graphe* G, Sommet* S) : Indice(G,S)
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


void Centralite::afficher()
{
    std::cout << "    -> Centralite de degre : " << m_critere << " | normalise : " << normalisation() << std::endl ;
}
