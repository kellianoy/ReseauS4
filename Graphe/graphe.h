#ifndef GRAPHE_H
#define GRAPHE_H
#include "arete.h"

class Graphe
{
    public:

        Graphe();
        ~Graphe();

        //Chargement du graphe
        void lecture_topo(std::string fichier);
        void lecture_poids(std::string fichier);
        void chargerGraphe(std::string s1, std::string s2="") {lecture_topo(s1); lecture_poids(s2);}

        //Get
        int getTaille() { return m_taille; }
        int getOrdre() { return m_ordre; }
        bool getOrientation() { return m_orientation; }
        std::vector<Sommet*> getVectS() { return m_vectS; }
        std::vector<Arete*> getVectA() { return m_vectA; }

        //Set
        void setTaille(int val) { m_taille = val; }
        void setOrdre(int val) { m_ordre = val; }
        void setOrientation(bool val) { m_orientation = val; }

        //Recherche
        Sommet* seekSommet(int id);
        Arete* seekArete(int id1, int id2);
        Arete* seekAreteId(int id);

        //Dessin
        void affichageTextuel();
        void dessinGraphe(Svgfile& svgout) const {for (auto a : m_vectA) a->dessin(svgout); for (auto s : m_vectS) s->dessin(svgout);}

        void sauvegardeIndice();

        void deleteGraphe()
        {
            m_vectS.clear();
            m_vectA.clear();
        }

    private:

        int m_taille;
        int m_ordre;
        bool m_orientation; //false : non orienté - true : orienté
        std::vector<Sommet*> m_vectS;
        std::vector<Arete*> m_vectA;
};

#endif // GRAPHE_H
