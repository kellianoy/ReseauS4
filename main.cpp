#include "menu.h"



int main()
{
    Graphe* Copie=new Graphe();
    Graphe* G=new Graphe();
    int choix=-1;
    while (choix!=0)
    {
        afficherMenu();
        do{
            std::cin>>choix;}
        while(choix<0||(choix>13));

        switchMenu(G, Copie, choix);

    }
    delete G;
    delete Copie;
    return 0;

}

