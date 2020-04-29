#include "menu.h"

void afficherMenu()
{
        std::cout<<"_________MENU_________\n\n";
        std::cout << "1. Charger une topologie\n";
        std::cout << "2. Charger une ponderation\n";
        std::cout << "3. Afficher le graphe dans le texte\n";
        std::cout << "4. Calculer et exporter les indices du graphe\n";
        std::cout << "5. Test de connexite\n";
        std::cout << "6. Supprimer une arete et former un sous-graphe\n";
        std::cout << "7. Calculer les indices du sous-graphe\n";
        std::cout << "\n\n9. Quitter\n";
}

void switchMenu(Graphe* G, Graphe* Copie, int choix)
{
    if(!G->grapheVide() && (choix!=1 && choix!=9))
    {
        std::cout << "Vous devez d'abord charger une topologie."<< std::endl ;
        return ;
    }
    switch(choix)
    {
            case 1:
            {
                //On remplace le graphe precedent par ce nouveau graphe
                if (G)
                    delete G;
                Graphe* G=new Graphe();
                if (Copie)
                    delete Copie;
                Graphe* Copie=new Graphe();

                std::string topo;
                std::cout << "Entrez le nom du fichier topologique"<<std::endl;
                std::cin >> topo;

                G->chargerGraphe(topo);
                Copie->chargerGraphe(topo);

                Svgfile svgout("Graphe actuel.svg", 1200, 1200);
                G->dessinGraphe(svgout);
                break;
            }
            case 2 :
            {
                    std::string poids;
                    std::cout << "Entrez le nom du fichier de poids"<<std::endl;
                    std::cin >> poids;
                    G->lecture_poids(poids);
                    Copie->lecture_poids(poids);
                break;
            }
            case 3:
            {
                G->affichageTextuel();
                break;
            }
            case 4:
            {
                std::cout<< "Indices du graphe\n\n";
                G->calculIndice();
                G->sauvegardeIndice();
                G->afficherIndice();
                break;
            }
            case 5:
            {
                std::cout<< "Connexite du graphe\n\n";
                G->connexite();

                std::cout<< "\n\nConnexite du sous-graphe\n\n";
                Copie->connexite();
                std::cout<<std::endl;

                break;
            }
            case 6 :
            {
                int numArete=0;
                std::cout<< "Selectionner le numero de l'arete a supprimer\n\n";
                Copie->affichageAretes();
                std::cin >> numArete;
                Copie->deleteArete(numArete);

                std::cout<< "Le nouveau sous-graphe genere est le suivant\n\n";
                Copie->affichageTextuel();

                Svgfile svgcopie("Sous-graphe.svg", 1200, 1200);
                Copie->dessinGraphe(svgcopie);

                break;
            }
            case 7 :
            {
                if(G->grapheIdentique(Copie))
                {
                    std::cout<< "Indices du sous-graphe\n\n";
                    Copie->calculIndice();
                    Copie->afficherIndice();
                }
                else std::cout << "Vous devez d'abord effacer une arete." << std::endl;

                break ;
            }
            case 9 :
                break;
            default :
            {
                std::cout << "Commande invalide." << std::endl ;
                break;
            }
    }
}

