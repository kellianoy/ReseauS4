#include "arete.h"

Arete::Arete()
{
    //ctor
}

Arete::Arete(int id, Sommet* s1, Sommet* s2) : m_indice{id}, m_s1{s1}, m_s2{s2}
{
    m_poids = 1 ;
}

Arete::~Arete()
{
    delete m_s1;
    delete m_s2;
}
