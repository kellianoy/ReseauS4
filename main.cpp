#include "graphe.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"

int main()
{
    Svgfile svgout;
    Graphe* a=new Graphe();

    a->lecture_topo("graphe_cycle4_topo.txt");
    a->lecture_poids("graphe_cycle4_poid.txt");
    a->affichageTextuel();
    a->dessinGraphe(svgout);

    delete a;

    return 0;
}
