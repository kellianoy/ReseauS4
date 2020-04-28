#include "graphe.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"

int main()
{
    Svgfile svgout;
    Graphe* a=new Graphe();
    a->chargerGraphe("graphe_cycle4_topo.txt", "graphe_cycle4_poids.txt" );
    a->affichageTextuel();
    a->dessinGraphe(svgout);

    delete a;

    return 0;
}
