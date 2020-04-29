#ifndef VECTEUR_H
#define VECTEUR_H

#include "indice.h"


class Vecteur : public Indice
{
    public:
        Vecteur();
        Vecteur(Graphe* G, Sommet* S);
        ~Vecteur();

        void calculIndice();
        void afficher();
        void sauvegarder(std::ofstream &ofs){ofs << " " << m_critere << " -" ; }

        double normalisation() {return m_critere ; }
    private:
};

#endif // VECTEUR_H
