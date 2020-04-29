#include "aspect.h"

Aspect::Aspect()
{
    //ctor
}

Aspect::Aspect(int x, int y, std::string color) : m_x{x}, m_y{y}, m_color{color}
{

}

Aspect::~Aspect()
{
    //dtor
}

void Aspect::dessin(Svgfile& svgout, std::string nom) const
{
    svgout.addDisk(m_x*100+100 , m_y*100+100, 10, m_color);
    svgout.addCircle(m_x*100+100 , m_y*100+100, 10, 1, "Black");
    svgout.addText(m_x*100+100, m_y*100+130, nom, "Black", "Black", 0);
}
