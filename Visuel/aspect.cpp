#include "aspect.h"
#define N 100

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
    svgout.addDisk(m_x*N+100 , m_y*N+100, 10, m_color);
    svgout.addCircle(m_x*N+100 , m_y*N+100, 10, 1, "Black");
    svgout.addText(m_x*N+100, m_y*N+130, nom, "Black", "Black", 0);
}

void Aspect::dessinFulkerson(Svgfile& svgout, std::string nom, bool debut, bool fin, double flux) const
{
    if (!debut && !fin)
        svgout.addDisk(m_x*N+100 , m_y*N+100, 10, m_color);
    else if (debut)
    {
        std::ostringstream oss;
        oss << "Flux max : " << flux;
        svgout.addText(m_x*N+100, m_y*N+70, oss.str(), "Pink", "Pink", 1);
        svgout.addText(m_x*N+100, m_y*N+70, oss.str(), "Black", "Black", 0);
        svgout.addDisk(m_x*N+100 , m_y*N+100, 10, "Green");
    }

    else if (fin)
        svgout.addDisk(m_x*N+100 , m_y*N+100, 10, "DarkRed");

    svgout.addCircle(m_x*N+100 , m_y*N+100, 10, 1, "Black");
    svgout.addText(m_x*N+100, m_y*N+130, nom, "Black", "Black", 0);

}

