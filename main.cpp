#include "graphe.h"
#include "centralite.h"
#include "vecteur.h"
#include "proximite.h"
#include "intermediarite.h"


int main()
{

    Graphe* G=new Graphe();
    int choix=0;

    while (choix!=9)
    {

        std::cout<<"_________MENU_________\n\n";
        std::cout << "1. Charger le graphe\n";
        std::cout << "2. Dessiner le graphe en SVG\n";
        std::cout << "3. Afficher le graphe dans le texte\n";
        std::cout << "4. Calculer et exporter les indices\n";
        std::cout << "5. Test de connexite\n";
        std::cout << "6. Supprimer une arete\n";
        std::cout << "\n\n9. Quitter\n";

        do
        {
        std::cin>>choix;
        }
        while(choix<1||(choix!=9&&choix>6));

        switch(choix)
        {
            case 1:
            {
                delete G;
                Graphe* G=new Graphe();
                std::string topo, ponderation;
                std::cout << "Entrez le nom du fichier topologique puis du fichier de ponderation s'il y en a un"<<std::endl;
                std::cin >> topo;
                fflush(stdin);
                getline(std::cin, ponderation);
                G->chargerGraphe(topo, ponderation);
                std::cout<< "Le graphe est charge\n\n";
                break;
            }

            case 2:
                {
                    Svgfile svgout;
                    G->dessinGraphe(svgout);
                    std::cout<< "Le dessin est effectue\n\n";
                    break;
                }
            case 3:
                G->affichageTextuel();
                break;
            case 4:
                G->calculIndice();
                G->sauvegardeIndice();
                G->afficherIndice();
                break;
            case 5:
                G->connexite();
                break;
            case 6 :
                int numArete=0;
                std::cin >> numArete;
                G->deleteArete(numArete);
                G->affichageTextuel();
                Svgfile svgout;
                G->dessinGraphe(svgout);

                break;

        }
    }
    delete G;

    return 0;
}

