#include "intermediarite.h"

Intermediarite::Intermediarite()
{
    //ctor
}

Intermediarite::Intermediarite(Graphe* G, Sommet* S) : Indice(G, S)
{
    //ctor
}


Intermediarite::~Intermediarite()
{
    //dtor
}

void Intermediarite::afficher()
{
    std::cout << "    -> Centralite d'intermediarite : " << m_critere << " | normalise : " << normalisation() << std::endl ;
}

void Intermediarite::initialisation(std::vector<Valeur*> &valeurS)
{
    for(auto it : valeurS)
    {
        it->s_predecesseur.clear();
        it->s_dependance = 0 ;
        if(it->s_ref == m_sommet)
        {
            it->s_distance = 0;
            it->s_nbpluscourt = 1;
        }
        else
        {
            it->s_distance = INT_MAX ;
            it->s_nbpluscourt = 0 ;
        }
    }
}

void Intermediarite::calculIndice()
{
    std::stack<Valeur*> S;
    std::vector<Valeur*> valeurS ;
    int ordre = m_graphe->getVectS().size();
    for(int i = 0 ; i < ordre; i++)
    {
        valeurS.push_back(new Valeur);
        valeurS[i]->s_ref = m_graphe->getVectS()[i];
    }
    initialisation(valeurS);
    m_graphe->dijkstraBrandes(S, valeurS,m_sommet);
    retro_propa(valeurS, S);
}

void Intermediarite::retro_propa(std::vector<Valeur*> & valeurS, std::stack<Valeur*> S)
{
    Valeur * w = nullptr ;
    while(!S.empty())
    {
        w = S.top();
        S.pop();
        for(auto it : w->s_predecesseur)
            it->s_dependance = it->s_dependance + (it->s_nbpluscourt/w->s_nbpluscourt)*(1 + w->s_dependance) ;
        if(w->s_ref != m_sommet)
        {
            w->s_ref->getVectI()[3]->setCritere(w->s_ref->getVectI()[3]->getCritere() + w->s_dependance);
            std::cout << w->s_ref->getNom()<< " : " << w->s_nbpluscourt << std::endl  ;
        }
    }
    std::cout << std::endl;
}

double Intermediarite::normalisation()
{
    int n = m_graphe->getOrdre();
    return m_critere*2 / (n*n -3*n +2);
}
