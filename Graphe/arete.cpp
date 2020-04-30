#include "arete.h"
#include <sstream>
#define N 75

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
}

void Arete::dessin(Svgfile& svgout) const
{
    int x1=0, x2=0, y1=0, y2=0;
    x1=m_s1->getAspect().getX()*N+100;
    y1=m_s1->getAspect().getY()*N+100;
    x2=m_s2->getAspect().getX()*N+100;
    y2=m_s2->getAspect().getY()*N+100;
    svgout.addLine(x1, y1, x2, y2, "black");
    if (fordfulkerson)
    {
        std::ostringstream oss;
        oss << m_flux << " / " << m_poids;
        svgout.addText((x1+x2)/2, (y1+y2)/2, oss.str(), "DarkRed", "DarkRed", 1);
        svgout.addText((x1+x2)/2, (y1+y2)/2, oss.str(), "Black", "Black", 0);
    }
    else
    {
        svgout.addText((x1+x2)/2, (y1+y2)/2, m_poids, "DarkRed", "DarkRed", 1);
        svgout.addText((x1+x2)/2, (y1+y2)/2, m_poids, "Black", "Black", 0);
    }
}
