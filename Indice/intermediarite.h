#ifndef INTERMEDIARITE_H
#define INTERMEDIARITE_H
#include "indice.h"


class Intermediarite : public Indice
{
    public:
        Intermediarite();
        Intermediarite(double c);
        ~Intermediarite();
        void calculIndice() {m_critere = 1 ;}
        double normalisation() {return 0.2 ; }

    private:
};

#endif // INTERMEDIARITE_H
