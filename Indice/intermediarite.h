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
        std::stack<Valeur*> BFSmodif(std::vector<Valeur*> & valeurS);
        void recurChemin(Valeur* refer, Valeur* top);

    private:
};



#endif // INTERMEDIARITE_H
