#include "sommet.h"
#include "indice.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"
#include "graphe.h"

Sommet::Sommet()
{
    //ctor
}

Sommet::Sommet(int identifiant, std::string nom, int x, int y, Graphe* mongraph) : m_indice{identifiant}, m_nom{nom}, m_aspect{x,y}
{
    m_vectI.push_back(new Centralite());
    m_vectI.push_back(new Vecteur());
    m_vectI.push_back(new Proximite());
    m_vectI.push_back(new Intermediarite());
}

Sommet::~Sommet()
{
    for (auto i : m_vectI)
        delete i;
}

void Sommet::sauvegardeIndice(std::ofstream &ofs)
{
    ofs << m_nom << " " ;
    for(int i = 0 ; i < 4 ; i++)
        m_vectI[i]->sauvegarder(ofs);
    ofs << std::endl;
}

