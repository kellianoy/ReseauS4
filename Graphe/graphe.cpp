#include "graphe.h"
#include "arete.h"

Graphe::Graphe()
{
    //ctor
}



Graphe::~Graphe()
{
    for (auto s : m_vectS)
        delete s;

    for (auto a : m_vectA)
        delete a;

}
