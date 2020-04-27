#ifndef SOMMET_H
#define SOMMET_H
#include "aspect.h"

class Indice; //OUI JE SAIS C'EST UN FORWARD MAIS ON VA Y REREFLECHIR #triste

class Sommet
{
    public:
        Sommet();
        ~Sommet();

        //Get
        int getIndice() { return m_indice; }
        std::string getNom() { return m_nom; }
        std::vector<Indice*> getVectI() { return m_vectI; }
        Aspect getAspect() { return m_aspect; }

        //Set
        void setIndice(int val) { m_indice = val; }
        void setNom(std::string val) { m_nom = val; }
        void setAspect(Aspect a) { m_aspect = a; }

    private:

        int m_indice;
        std::string m_nom;
        std::vector<Indice*> m_vectI;
        Aspect m_aspect;
};

#endif // SOMMET_H
