#include "graphe.h"

#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"

int main()
{
    Graphe* a=new Graphe();
    a->lecture_topo("graphe_cycle4_topo.txt");
    a->lecture_poids("graphe_cycle4_poid.txt");
    delete a;
    Indice* V = new Vecteur(1500);
    std::cout << V->getCritere() << std::endl;
    delete V;
    return 0;
}
