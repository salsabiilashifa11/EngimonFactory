#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Position.hpp"
#include "Engimon.hpp"
#include "OwnedEngimon.hpp"
#include "Inventory.hpp"

using namespace std;

class Player {
    private :
        string name;
        Position playerPos;
        // Engimon active;
        // Inventory playerInventory;
        int activeIndex;
        Inventory<OwnedEngimon> playerEngimons;
        // Inventory<SkillItems> playerItems;

    public :
        Player();
        // default constructor for player
        Player(string _name);
        ~Player();
        // dtor
        void operator=(const Player& p);

        // Commands
        void Move(char _direction);
        void changeEngimon();
        Engimon Breed(Engimon father, Engimon mother);
        void Battle();
        // void checkEngimon();
        // void useItem(Item);
        // Interact

        // display
        void displayEngimon();
        void displaySkillItem();
        void detailEngimon();

        // Getter Setter
        // Engimon getActiveEngimon();
        // Position getPosition();
        string getName();
        int getActiveIndex();
        Position getPosition() const;
        // void setActiveEngimon();
        void setPosition(int _x, int _y);
        void setActiveIndex(int i);

        void addToInventory(OwnedEngimon el);
        // void addToInventory(SkillItems el);
};

#endif