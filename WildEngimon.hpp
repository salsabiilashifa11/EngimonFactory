#ifndef _WILD_ENGIMON_HPP_
#define _WILD_ENGIMON_HPP_

#include <string>
#include <iostream>
#include <map>
#include "Engimon.hpp"
#include "Skill.hpp"
#include "Map.hpp"

using namespace std;
// using namespace EngimonFactory;
class WildEngimon : public Engimon {
   private:
    string status;
    Position position;
    int element2int(string element);
    static map<string, string> spesiesSkill;

   public:
    WildEngimon();
    WildEngimon(string species, string element, int level, int x, int y, Map* m);
    ~WildEngimon();
    void operator=(const WildEngimon&);

    string getStatus();
    void setStatus(string);

    Position getPosition();
    void setPosition(int, int, Map* m);
    void assertPosition(Map* m);
    void Move(Map* m);

    bool validPosition(Map* m, int x, int y);
    void displayDetail();
};


#endif
    