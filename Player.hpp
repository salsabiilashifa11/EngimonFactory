#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#include "Position.hpp"
#include "OwnedEngimon.hpp"
#include "ElementAdvantage.hpp"
#include "Inventory.hpp"
// #include "SkillItems.hpp"

#define MAX_EL 15
using namespace std;
class Player {
    private :
        string name;
        Position playerPos;
        OwnedEngimon active;
        int activeIndex;
        Inventory<OwnedEngimon> playerEngimons;
        Inventory<SkillItems> playerItems;

    public :
        Player();
        // default constructor for player
        Player(string _name);
        ~Player();
        // dtor
        void operator=(const Player& p);

        // Commands
        void Move(char _direction);
        bool validMove(char _direction);
        // void changeEngimon();
        void Breed(Engimon& father, Engimon& mother);
        // void checkEngimon();
        // void useItem(SkillItems);

        // // display
        // void displayEngimon();
        // void displaySkillItem();
        // void detailEngimon();

        // Getter Setter
        OwnedEngimon& getActiveEngimon();
        string getName();
        int getActiveIndex();
        Position getPosition() const;
        // void setActiveEngimon();
        void setPosition(int _x, int _y);
        void setActiveIndex(int i);

        void addToInventory(OwnedEngimon el);
        void addToInventory(SkillItems el);
        void showInventory();
};

#endif