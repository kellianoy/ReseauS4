#ifndef INTERMEDIARITE_H
#define INTERMEDIARITE_H
#include "indice.h"
#include "Valeur.h"

class Intermediarite : public Indice
{
    public:
        Intermediarite();
        Intermediarite(Graphe* G, Sommet* S);
        ~Intermediarite();
        void calculIndice();
        double normalisation();
        void afficher() ;
        void initialisation(std::vector<Valeur*> &valeurS);
        void retro_propa(std::vector<Valeur*> & valeurS, std::stack<Valeur*> S);

    private:
};



#endif // INTERMEDIARITE_H
