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
