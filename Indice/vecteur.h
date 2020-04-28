#ifndef VECTEUR_H
#define VECTEUR_H

#include "indice.h"


class Vecteur : public Indice
{
    public:
        Vecteur();
        Vecteur(double c);
        ~Vecteur();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
        void calculIndice() {m_critere = 4 ;}
        double normalisation() {return 0.2 ; }

>>>>>>> Stashed changes
    private:
};

#endif // VECTEUR_H
