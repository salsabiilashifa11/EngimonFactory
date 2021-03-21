#ifndef _WILD_ENGIMON_HPP_
#define _WILD_ENGIMON_HPP_

#include <string>
#include <iostream>
#include "Cell.hpp"
#include "Engimon.hpp"
#include "Map.hpp"
using namespace std;
// using namespace EngimonFactory;
class WildEngimon : public Engimon {
   private:
    string status;
    Position position;
    int element2int(string element);

   public:
    WildEngimon();
    ~WildEngimon();

    string getStatus();
    void setStatus(string);

    Position getPosition();
    void setPosition(int, int);

    bool validPosition(Map m, int x, int y);
};


#endif
    