#ifndef CELl_HPP
#define CELl_HPP

#include <stdio.h>
#include <iostream>
#include "Player.hpp"
#include "Engimon.hpp"

using namespace std;

enum CellType {Grassland, Sea};

class Cell {
    private:
        int x; //x coordinate
        int y; //y coordinate
        CellType type; //Grassland or sea
        Player occupierP;
        Engimon* occupierE;

    public:
        //4 Sekawan
        Cell();
        Cell(int _x, int _y, CellType _type);
        Cell(const Cell& c);
        void operator=(const Cell& c);
        ~Cell();

        //Getter dan Setter
        int getX();
        int getY();
        CellType getType();
        Player& getOccupierP();
        Engimon* getOccupierE();

        //Setter
        void setPlayer(Player& p);
        void setEngimon(Engimon* e);

        //Method
        //void drawRandom(int input);
        void drawCell();
        void drawEngimon(int level_min);
        void printInfo();
        void setOccupierE();

};

#endif