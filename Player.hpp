#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Position.hpp"
#include "OwnedEngimon.hpp"
#include "ElementAdvantage.hpp"
#include "Inventory.hpp"
#include "SkillItems.hpp"

#define MAX_EL 15
#define MAX_EXP 20150
using namespace std;
class Player {
    private :
        string name;
        Position playerPos;
        OwnedEngimon active;
        Inventory<OwnedEngimon> playerEngimons;
        Inventory<SkillItems> playerItems;
        void makeEngimon();
        void initiateSkill();   

    public :
        // Ctor, dtor Player
        Player();
        Player(string _name);
        ~Player();
        void operator=(const Player& p);

        // Commands
        void Move(char _direction);
        bool validMove(char _direction);
        void changeActiveEngimon();
        void Breed(Engimon& father, Engimon& mother);
        void Battle(Engimon& musuh);
        void teach(string skillName, string eName);

        // Display
        void displayEngimon(string _name);
        void executeBreed();

        // Getter Setter
        OwnedEngimon& getActiveEngimon();
        string getName();
        Position getPosition() const;
        void setActiveEngimon(int i);
        void activeMati();
        void setPosition(int _x, int _y);

        //In function
        void addToInventory(OwnedEngimon el);
        void addToInventory(SkillItems el);
        void showInventory();
        void showItems();
        void showEngimons();
        void useSkillItems();
        SkillItems generateSkillItem(string);
};

#endif