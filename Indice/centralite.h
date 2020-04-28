#ifndef CENTRALITE_H
#define CENTRALITE_H
#include "indice.h"


class Centralite : public Indice
{
    public:
        Centralite();
        Centralite(Graphe* G, Sommet* S);
        ~Centralite();

        void calculIndice();
        double normalisation();
        void afficher();
        void sauvegarder(std::ofstream ofs){ofs << "Crit�re de degr� : "<< m_critere<< " " << normalisation() << std::endl; } ;

    private:
};

#endif // CENTRALITE_H
