#ifndef PROXIMITE_H
#define PROXIMITE_H

#include "indice.h"


class Proximite : public Indice
{
    public:
        Proximite();
        Proximite(double c);
        ~Proximite();
    void calculIndice() {m_critere = 5;}
    double normalisation() {return 0.2 ; }

    private:
};

#endif // PROXIMITE_H
