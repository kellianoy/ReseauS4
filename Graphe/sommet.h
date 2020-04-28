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
        int getMarquage()const {return m_marquage;}

        //Set
        void setIndice(int val) { m_indice = val; }
        void setNom(std::string val) { m_nom = val; }
        void setAspect(Aspect a) { m_aspect = a; }
        void pushAdjacent(Sommet* S) {m_vectAdj.push_back(S);}
        void setMarquage(int a) {m_marquage=a;}

        //Dessin
        void dessin(Svgfile& svgout) const { m_aspect.dessin(svgout, m_nom); }

        void sauvegardeIndice(std::ofstream &ofs);
        void afficherIndice() ;

        void deleteAdj(Sommet* s1);

    private:
        int m_indice;
        std::string m_nom;
        Aspect m_aspect;
        std::vector<Indice*> m_vectI;
        std::vector<Sommet*> m_vectAdj;
        int m_marquage;


};

#endif // SOMMET_H
