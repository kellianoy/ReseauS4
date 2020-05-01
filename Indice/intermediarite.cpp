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


///Document source pour l'algo de Brandes
//https://www.cl.cam.ac.uk/teaching/1617/MLRD/handbook/brandes.pdf
//Surtout celui-ci
///http://thibautdemare.github.io/files/memoire_M2_Thibaut_Demare_Reseaux_viaires_et_evacuation.pdf
void Intermediarite::calculIndice()
{
    std::vector<Valeur*> valeurS;
    std::stack<Valeur*> parcours;
    Valeur * refer = nullptr ;

    //on initialise les valeurs de traitements pour chaque sommet
    for(size_t i = 0 ; i < m_graphe->getVectS().size(); i++)
    {
        valeurS.push_back(new Valeur);
        valeurS[i]->s_ref = m_graphe->getVectS()[i];
    }
    initialisation(valeurS);

    //lancement du plus court chemin
    if(m_sommet->getVectAdj().size() != 0)
        parcours = m_graphe->dijkstraModif(valeurS, m_sommet);

    //recursif pour retrouver toutes les inerm�diarit�s
    while( !parcours.empty())
    {
        refer = parcours.top();
        //std::cout << refer->s_ref->getNom() << std::endl ;
        recurChemin(refer, refer, 0);
        parcours.pop();
    }

    //On met � jour les crit�res
    for(auto s : valeurS)
        s->s_ref->getVectI()[3]->setCritere(s->s_ref->getVectI()[3]->getCritere() + s->s_dependance);

    m_sommet->setMarquage(1);
}

//permet de retrouver les valeurs � ajouter aux crit�res � partir d'un chemin
void Intermediarite::recurChemin(Valeur * refer, Valeur * top, int a)
{
    if(refer == top && a != 0)
        return ;
    for(auto v : refer->s_predecesseur)
    {
        //si l'interm�diarit� correspond on ajoute la valeur
        if(refer->s_ref != m_sommet && refer->s_ref != top->s_ref)
            refer->s_dependance += 1/top->s_nbpluscourt;
        recurChemin(v, top, 1);
    }
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
            it->s_nbpluscourt = 1 ;
        }
        else
        {
            it->s_distance = INT_MAX ;
            it->s_nbpluscourt = 0 ;
        }
    }
}

double Intermediarite::normalisation()
{
    int n = m_graphe->getOrdre();
    return m_critere*2 / (n*n -3*n +2);
}
