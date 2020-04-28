#include "menu.h"

int main()
{
    Graphe* Copie=new Graphe();
    Graphe* G=new Graphe();
    int choix=0;
    while (choix!=9)
    {
        afficherMenu();
        do{
            std::cin>>choix;}
        while(choix<1||(choix>6&&choix!=9));

        switchMenu(G, Copie, choix);

    }
    delete G;
    delete Copie;
    return 0;

}

