#include "graphe.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"

int main()
{

    Graphe* G=new Graphe();
    int choix=0;
    std::cout<<"_________MENU_________\n\n";
    std::cout << "1. Charger le graphe\n";
    std::cout << "2. Afficher le graphe dans le texte\n";
    std::cout << "3. Dessiner le graphe en SVG\n";
    std::cout << "4. Calculer et exporter les indices\n";
    std::cout << "\n\n9. Quitter\n";
    while (choix!=9)
    {
        do
        {
        std::cin>>choix;
        }
        while(choix<1||(choix!=9&&choix>4));
        switch(choix)
        {
            case 1:
                G->chargerGraphe("graphe_cycle4_topo.txt", "graphe_cycle4_poids.txt" );
                break;
            case 2:
                G->affichageTextuel();
                break;
            case 3:
                {
                    Svgfile svgout;
                    G->dessinGraphe(svgout);
                    std::cout<< "Le dessin est effectue\n";
                    break;
                }
            case 4:
                for (auto s : G->getVectS())
                    s->getVectI()[0]->calculIndice();
                G->getVectS()[0]->getVectI()[1]->calculIndice();
                G->sauvegardeIndice();
                std::cout<< "Le calcul est effectue et exporte\n";
                break;
        }
    }
    delete G;

    return 0;
}
