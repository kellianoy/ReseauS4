#include "graphe.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"


int main()
{
    Indice* V = new Vecteur(1500);
    std::cout << V->getCritere() << std::endl;
    return 0;
}
