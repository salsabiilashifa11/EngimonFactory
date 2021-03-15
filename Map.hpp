#ifndef MAP_HPP
#define MAP_HPP

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Cell.hpp"
#include "Player.hpp"

using namespace std;

#define MAP_WIDTH 30
#define MAP_HEIGHT 30

class Map {
    private:
        Cell map[MAP_HEIGHT][MAP_WIDTH];
        int width;
        int height;
        string filename;
        Player player;

    public:
        Map();
        Map(string _filename, Player& _player);
        ~Map();

        //Getter
        Cell getCell(int x, int y);

        //Methods
        void drawMap();
        CellType getType(char c);
        void updateMap();
        // Engimon getOccupierE(char c);
        // void saveMap();
        

};

#endif