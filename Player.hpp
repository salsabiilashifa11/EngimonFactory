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
        Player();
        // default constructor for player
        Player(string _name);
        ~Player();
        // dtor
        void operator=(const Player& p);

        // Commands
        void Move(char _direction);
        bool validMove(char _direction);
        void changeActiveEngimon();
        void Breed(Engimon& father, Engimon& mother);
        void Battle(Engimon& musuh);
        // void checkEngimon();
        // void useItem(SkillItems);

        // // display
        void displayEngimon(string _name);
        void MBA();
        // void detailEngimon();

        // Getter Setter
        OwnedEngimon& getActiveEngimon();
        string getName();
        Position getPosition() const;
        void setActiveEngimon(int i);
        void activeMati();
        void setPosition(int _x, int _y);

        void addToInventory(OwnedEngimon el);
        void addToInventory(SkillItems el);
        void showInventory();
        void showItems();
        void showEngimons();
        void useSkillItems();

        void teach(string skillName, string eName);
        
};

#endif