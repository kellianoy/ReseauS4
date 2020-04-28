#ifndef SOMMET_H
#define SOMMET_H
#include "aspect.h"

class Indice; //OUI JE SAIS C'EST UN FORWARD MAIS ON VA Y REREFLECHIR #triste
class Graphe;

class Sommet
{
    public:
        Sommet();
        Sommet(int identifiant, std::string nom, int x, int y, Graphe* G);
        ~Sommet();

        //Get
        int getIndice() const { return m_indice; }
        std::string getNom() const { return m_nom; }
        std::vector<Indice*> getVectI() const { return m_vectI; }
        Aspect getAspect() const { return m_aspect; }
        std::vector<Sommet*> getVectAdj() const { return m_vectAdj; }

        //Set
        void setIndice(int val) { m_indice = val; }
        void setNom(std::string val) { m_nom = val; }
        void setAspect(Aspect a) { m_aspect = a; }
        void pushAdjacent(Sommet* S) {m_vectAdj.push_back(S);}

        //Dessin
        void dessin(Svgfile& svgout) const { m_aspect.dessin(svgout, m_nom); }

        void sauvegardeIndice(std::ofstream &ofs);

    private:
        int m_indice;
        std::string m_nom;
        Aspect m_aspect;
        std::vector<Indice*> m_vectI;
        std::vector<Sommet*> m_vectAdj;
};

#endif // SOMMET_H
