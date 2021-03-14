#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <iostream>

using namespace std;

class Player {
    private :
        string name;
        // Position playerPos;
        // Engimon active;
        // Inventory playerInventory;
        int activeIndex;

    public :
        Player();
        // default constructor for player
        ~Player();
        // dtor

        // Commands
        void Move();
        void changeEngimon();
        // Engimon Breed();
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
        int getActiveIndex();
        void setActiveEngimon();
        void setPosition();
        void setActiveIndex();

};

#endif