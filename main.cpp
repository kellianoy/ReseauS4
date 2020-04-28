#include "graphe.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"

int main()
{
    Svgfile svgout;
    Graphe* G=new Graphe();
    G->chargerGraphe("graphe_cycle4_topo.txt", "graphe_cycle4_poids.txt" );
    G->affichageTextuel();
    G->dessinGraphe(svgout);

    std::cout<< "\n";

    G->getVectS()[0]->getVectI()[1]->calculIndice();

    delete G;

    return 0;
}
