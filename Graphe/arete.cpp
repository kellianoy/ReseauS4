#include "arete.h"

Arete::Arete()
{
    //ctor
}

Arete::Arete(int id, Sommet* s1, Sommet* s2) : m_indice{id}, m_s1{s1}, m_s2{s2}
{
    m_poids = 1 ;
}

Arete::~Arete()
{
    delete m_s1;
    delete m_s2;
}

void Arete::dessin(Svgfile& svgout) const
{
    int x1=0, x2=0, y1=0, y2=0;
    x1=m_s1->getAspect().getX()*100+100;
    y1=m_s1->getAspect().getY()*100+100;
    x2=m_s2->getAspect().getX()*100+100;
    y2=m_s2->getAspect().getY()*100+100;
    svgout.addLine(x1, y1, x2, y2, "black");

    svgout.addText((x1+x2)/2, (y1+y2)/2+25, m_poids, "white", "FireBrick", 2.5);
    svgout.addText((x1+x2)/2, (y1+y2)/2+25, m_poids, "white", "FireBrick", 0);
}
