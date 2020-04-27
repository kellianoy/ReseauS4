#include "sommet.h"

Sommet::Sommet()
{
    //ctor
}

Sommet::~Sommet()
{
    for (auto i : m_vectI)
        delete i;
}
