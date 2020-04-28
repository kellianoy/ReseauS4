#ifndef CENTRALITE_H
#define CENTRALITE_H
#include "indice.h"


class Centralite : public Indice
{
    public:
        Centralite();
        Centralite(double c);
        ~Centralite();

        void calculIndice();
        double normalisation();
        void sauvegarder(std::ofstream ofs){ofs << "Critère de degré : "<< m_critere<< " " << normalisation() << std::endl; } ;

    private:
};

#endif // CENTRALITE_H
