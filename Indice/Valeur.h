#ifndef VALEUR_H_INCLUDED
#define VALEUR_H_INCLUDED


struct Valeur
{
    Sommet* s_ref ;
    int s_distance = 0 ;
    std::vector<Valeur*> s_predecesseur ;
    double s_nbpluscourt = 0 ;
    double s_dependance = 0 ;
};


#endif // VALEUR_H_INCLUDED
