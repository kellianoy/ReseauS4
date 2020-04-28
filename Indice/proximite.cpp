#include "proximite.h"

Proximite::Proximite()
{
    //ctor
}

Proximite::Proximite(Graphe* G, Sommet* S) : Indice(G, S)
{
    //ctor
}

Proximite::~Proximite()
{
    //dtor
}

void Proximite::calculIndice()
{
    std::vector<std::pair<Sommet*,double>> tab=m_graphe->dijkstra(m_sommet);
    double i=0;
    for(const auto it : tab)
    {
        i+=it.second;
    }
    m_critere=1/i;
}

double Proximite::normalisation()
{
    return (m_graphe->getOrdre()-1)*m_critere;
}
