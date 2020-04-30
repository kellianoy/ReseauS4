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
        bool grapheVide();
        bool grapheIdentique(Graphe * Copie);


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
        void deleteArete(int id);

        //Dessin
        void affichageAretes();
        void affichageSommets();
        void affichageTextuel();
        void dessinGraphe(Svgfile& svgout) const {for (auto a : m_vectA) a->dessin(svgout); for (auto s : m_vectS) s->dessin(svgout);}
        void colorerCritere();

        //Indices
        void sauvegardeIndice();
        void afficherIndice() ;
        void calculIndice();

        //Supprimer le graphe
        void deleteGraphe(){ m_taille=0; m_ordre=0; m_orientation=0;  m_vectS.clear(); m_vectA.clear();     }

        //Dijkstra
        std::vector<std::pair<Sommet*,double>> dijkstra(Sommet* depart);

        //BFS
        void bfs(Sommet* initial, std::vector<Sommet*>& colored);

        //Connexité
        Sommet* PasFait(const std::vector<Sommet*> faits);
        void connexite();

        double maxX()
        {std::vector<double> X; for (auto s : m_vectS) X.push_back(s->getAspect().getX()); return *std::max_element(X.begin(), X.end())*100+100;}

        double maxY()
        {std::vector<double> Y; for (auto s : m_vectS) Y.push_back(s->getAspect().getY()); return *std::max_element(Y.begin(), Y.end())*100+100;}


    private:

        int m_taille;
        int m_ordre;
        bool m_orientation; //false : non orient� - true : orient�
        std::vector<Sommet*> m_vectS;
        std::vector<Arete*> m_vectA;
};

#endif // GRAPHE_H
