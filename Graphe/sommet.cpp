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

Sommet::Sommet(int identifiant, std::string nom, int x, int y, Graphe* G) : m_indice{identifiant}, m_nom{nom}, m_aspect{x,y}
{
    m_vectI.push_back(new Centralite(G, this));
    m_vectI.push_back(new Vecteur(G, this));
    m_vectI.push_back(new Proximite(G, this));
    m_vectI.push_back(new Intermediarite(G, this));
}

Sommet::~Sommet()
{

}

void Sommet::sauvegardeIndice(std::ofstream &ofs)
{
    ofs << m_indice << " " ;
    for(int i = 0 ; i < 4 ; i++)
        m_vectI[i]->sauvegarder(ofs);
    ofs << std::endl;
}

//affichage les indices en console
void Sommet::afficherIndice()
{
    std::cout << "Sommet n" << m_indice << ", nom : " << m_nom<< std::endl;
    for(auto i : m_vectI)
        i->afficher();
    std::cout << "\n" ;
}

void Sommet::deleteAdj(Sommet* s1)
{
    if (m_vectAdj.size())
        for (size_t i = 0 ; i<m_vectAdj.size() ; ++i)
            if (s1->getIndice()==m_vectAdj[i]->getIndice())
            {
                m_vectAdj.erase(m_vectAdj.begin()+i);
                break;
            }
}

void Sommet::colorerCritere(int num)
{
    if (num>=0&&num<4)
        m_aspect.setColor(Svgfile::makeRGB(255*(m_vectI[num]->normalisation()),0,255*(1-m_vectI[num]->normalisation())));
}

void Sommet::dessinFulkerson(Svgfile& svgout, Sommet* a, Sommet* b, double flux) const
{
            if (a->getIndice()==m_indice)
                m_aspect.dessinFulkerson(svgout, m_nom, 1, 0, flux);
            else if (b->getIndice()==m_indice)
                m_aspect.dessinFulkerson(svgout, m_nom, 0, 1);
            else
                m_aspect.dessinFulkerson(svgout, m_nom, 0, 0);
}
