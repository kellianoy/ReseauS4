#include "vecteur.h"
#include <math.h>
Vecteur::Vecteur()
{
    //ctor
}

Vecteur::Vecteur(Graphe* G, Sommet* S) : Indice(G, S)
{
    //ctor
}

Vecteur::~Vecteur()
{
    //dtor
}

void Vecteur::calculIndice()
{
    std::vector<double> somme;
    double temp=0;
    double lastA=0;
    double A=0;

    //Initialisation
    for (auto s : m_graphe->getVectS())
        s->getVectI()[1]->setCritere(1);

    //Boucle principale
    do
    {
        lastA=A;
        for (auto s : m_graphe->getVectS())
        {
            for (auto a : s->getVectAdj())
                temp+=a->getVectI()[1]->getCritere();
            somme.push_back(temp);
            temp=0;
        }
        for (auto s : somme)
        {
            A+=s*s;
        }
        A=sqrt(A);
        for (size_t i=0 ; i<somme.size() ; ++i)
            m_graphe->getVectS()[i]->getVectI()[1]->setCritere(somme[i]/A);
    }
    while(A>lastA+10 || A<lastA-10);
}

void Vecteur::afficher()
{
    std::cout << "    -> Centralite de vecteur : " << m_critere << std::endl ;
}
