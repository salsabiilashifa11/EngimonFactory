#ifndef CELl_HPP
#define CELl_HPP

#include <stdio.h>
#include <iostream>
#include "Player.hpp"
using namespace std;

enum CellType {Grassland, Sea};

class Cell {
    private:
        int x; //x coordinate
        int y; //y coordinate
        CellType type; //Grassland or sea
        //Engimon occupierE
        Player occupierP;

    public:
        Cell();
        Cell(int _x, int _y, CellType _type);

        //Getter
        int getX();
        int getY();
        CellType getType();

        //Setter
        void setPlayer(Player& p);

        //Method
        void drawCell();
        void printInfo();

};

#endif