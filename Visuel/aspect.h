#ifndef ASPECT_H
#define ASPECT_H
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <utility>

class Aspect
{
    public:
        Aspect();
        ~Aspect();

        //Get
        int getX() { return m_x; }
        int getY() { return m_y; }
        std::string getColor() { return m_color; }

        //Set
        void setX(int val) { m_x = val; }
        void setY(int val) { m_y = val; }
        void setColor(std::string val) { m_color = val; }

    private:
        int m_x;
        int m_y;
        std::string m_color;
};

#endif // ASPECT_H
