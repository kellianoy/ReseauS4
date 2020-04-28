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
    for (auto i : m_vectI)
        delete i;
}

void Sommet::sauvegardeIndice(std::ofstream &ofs)
{
    ofs << "Sommet " << m_nom << "  :" ;
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

