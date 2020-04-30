#include "menu.h"

void afficherMenu()
{
        std::cout<<"\n_____________________________________________\n";
        std::cout<<"\n\t\tMENU\n\n";
        std::cout << "1. Charger une topologie\n";
        std::cout << "2. Charger une ponderation\n\n";
        std::cout<<"_________Graphe\n\n";
        std::cout << "3. Afficher les sommets et les aretes du graphe dans la console\n";
        std::cout << "4. Calculer et exporter les indices du graphe\n";
        std::cout << "5. Tester la connexite du graphe\n";
        std::cout << "6. Colorer les sommets en fonction d'un critere\n";
        std::cout << "7. Appliquer l'algorithme de Ford-Fulkerson\n\n";
        std::cout<<"_________Sous-graphe\n\n";
        std::cout << "8. Supprimer une ou plusieurs aretes et former un sous-graphe\n";
        std::cout << "9. Afficher le sous-graphe\n";
        std::cout << "10. Calculer les indices du sous-graphe et comparer avec le graphe\n";
        std::cout << "11. Tester la connexite du sous-graphe\n";
        std::cout << "12. Colorer les sommets en fonction d'un critere\n\n";

        std::cout << "\n\n0. Quitter\n";
}

//permet de comparer les indices de deux graphes
void comparaison(Graphe* G1, Graphe* G2)
{
    if(G1->getOrdre()==G2->getOrdre())
    {
        for (int i = 0 ; i < G1->getOrdre() ; ++i)
        {
            std::cout << "Sommet " << G1->getVectS()[i]->getNom() <<" :\n";
            for(size_t j = 0 ; j < G1->getVectS()[i]->getVectI().size() ; ++j)
            {
                std::cout << "Avant : " << G1->getVectS()[i]->getVectI()[j]->normalisation();
                std::cout << " | Apres : " << G2->getVectS()[i]->getVectI()[j]->normalisation();
                std::cout << " | Comparaison : " << G2->getVectS()[i]->getVectI()[j]->normalisation() - G1->getVectS()[i]->getVectI()[j]->normalisation()<<std::endl ;
            }
            std::cout<<"\n\n";
        }
    }
}

void switchMenu(Graphe* G, Graphe* Copie, int choix)
{
    if(!G->grapheVide() && (choix!=1 && choix!=0))
    {
        std::cout << "Vous devez d'abord charger une topologie."<< std::endl ;
        return ;
    }
    switch(choix)
    {
            case 1:
            {
                //On remplace le graphe precedent par ce nouveau graphe

               G->deleteGraphe();
               Copie->deleteGraphe();

                std::string topo;
                std::cout << "Entrez le nom du fichier topologique"<<std::endl;
                std::cin >> topo;

                G->chargerGraphe(topo);
                Copie->chargerGraphe(topo);
                Svgfile svgout("Graphe actuel.svg", G->maxX(), G->maxY());
                G->dessinGraphe(svgout);
                break;
            }
            case 2 :
            {
                    std::string poids;
                    std::cout << "Entrez le nom du fichier de poids"<<std::endl;
                    std::cin >> poids;
                    G->lecture_poids(poids);
                    if(!G->grapheIdentique(Copie))
                        Copie->lecture_poids(poids);
                    Svgfile svgout("Graphe actuel.svg", G->maxX(), G->maxY());
                    G->dessinGraphe(svgout);

                break;
            }
            case 3 :
            {
                G->affichageTextuel();
                break;
            }
            case 4 :
            {
                G->calculIndice();
                G->sauvegardeIndice();
                G->afficherIndice();
                break;
            }
            case 5 :
            {
                std::cout<< "Connexite du graphe\n\n";
                G->connexite();
                std::cout<< "Le graphe est " << G->kedgeconnexity() << "-aretes-connexe\n";
                break;
            }
            case 6 :
            {
                G->calculIndice();
                G->colorerCritere();
                Svgfile svgout("Graphe actuel.svg", G->maxX(), G->maxY());
                G->dessinGraphe(svgout);
                break;
            }
            case 7 :
            {
                G->affichageSommets();
                std::cout<<"Selectionner le sommet source et le sommet puits\n";
                int a=0, b=0;
                do
                {
                    fflush(stdin);
                    std::cin>>a >> b;
                }
                while (!G->seekSommet(a)&&!G->seekSommet(b));
                double flux=G->FordFulkerson(a, b);
                std::cout << "Le flot maximum entre le sommet "<< G->seekSommet(a)->getNom() << " et " <<G->seekSommet(b)->getNom() << " est de " << flux<<std::endl;
                Svgfile svgout("Graphe actuel.svg", G->maxX(), G->maxY());
                G->dessinFulkerson(svgout, G->seekSommet(a), G->seekSommet(b), flux);
                break;
            }
            case 8 :
            {
                std::string numArete;
                std::cout<< "Selectionner le numero de l'arete a supprimer vous pouvez separer deux point a supprimer par un espace\n\n";
                Copie->affichageAretes();
                std::cin.ignore();/// la lecture bug � cause du std::cout du dessus, le '\n' emp�che la lecture. le cin.ignore supprime le '\n' du buffer
                std::getline(std::cin,numArete);
                std::istringstream iss(numArete);
                int value=-1;
                while(iss)
                {
                    iss>>value;
                    if(Copie->seekAreteId(value)!=nullptr)
                    {
                        Copie->deleteArete(value);
                    }
                }

                Svgfile svgcopie("Sous-graphe.svg", G->maxX(), G->maxY());
                Copie->dessinGraphe(svgcopie);

                break;
            }
            case 9 :
            {
                if(G->grapheIdentique(Copie))
                    Copie->affichageTextuel();
                else std::cout << "Vous devez d'abord effacer une arete." << std::endl;
                break ;
            }
            case 10 :
            {
                if(G->grapheIdentique(Copie))
                {
                    G->calculIndice();
                    Copie->calculIndice();
                    comparaison(G, Copie);
                }
                else std::cout << "Vous devez d'abord effacer une arete." << std::endl;

                break ;
            }
            case 11 :
            {
                if(G->grapheIdentique(Copie))
                {
                    std::cout<< "\n\nConnexite du sous-graphe\n\n";
                    Copie->connexite();
                    std::cout<<std::endl;
                    std::cout<< "Le sous-graphe est " << G->kedgeconnexity() << "-aretes-connexe\n";
                }
                else std::cout << "Vous devez d'abord effacer une arete." << std::endl;
                break;
            }
            case 12 :
            {
                if(G->grapheIdentique(Copie))
                {
                    Copie->calculIndice();
                    Copie->colorerCritere();
                    Svgfile svgcopie("Sous-graphe.svg", G->maxX(), G->maxY());
                    Copie->dessinGraphe(svgcopie);
                }
                else std::cout << "Vous devez d'abord effacer une arete." << std::endl;
                break;
            }
            case 0 :
                break;
            default :
            {
                std::cout << "Commande invalide." << std::endl ;
                break;
            }
    }
}

