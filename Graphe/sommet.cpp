#include "sommet.h"
#include "indice.h"

Sommet::Sommet()
{
    //ctor
}

Sommet::Sommet(int identifiant, std::string nom, int x, int y) : m_indice{identifiant}, m_nom{nom}, m_aspect{x,y}
{
    for(int i = 0 ; i < 4 ; i++)
        m_vectI.push_back(new Indice());
}

Sommet::~Sommet()
{
    for (auto i : m_vectI)
        delete i;
}
