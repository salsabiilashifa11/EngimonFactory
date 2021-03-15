#ifndef POSITION_HPP
#define POSITION_HPP

#include <stdio.h>
#include <iostream>

using namespace std;

class Position {
    private:
        int x; //x coordinate
        int y; //y coordinate

    public:
        Position();
        Position(int _x, int _y);
        ~Position();

        // Operator Overloading
        Position& operator=(const Position&);

        //Getter
        int getX();
        int getY();

        //Setter
        void setX(int _x);
        void setY(int _y);

};

#endif
