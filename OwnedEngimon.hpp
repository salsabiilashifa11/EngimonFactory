#ifndef _OWNED_ENGIMON_HPP_
#define _OWNED_ENGIMON_HPP_

#include <string>
#include <iterator>
#include <map>
#include "Position.hpp"
#include "Engimon.hpp"
#include "ElementAdvantage.hpp"

// == ACTIVE ENGIMON
class OwnedEngimon : public Engimon {
   private:
    string *parentName;
    string status;
    Position position;
    //mapping species dengan message unik pake stl
    // static map<int, string> percakapan;
    float getStrongestEl(string enemyEl);
    

   public:
    OwnedEngimon();
    OwnedEngimon(string name, string species);
    ~OwnedEngimon();

    string* getParentName();
    void setParentName(string,string);

    string getStatus();
    void setStatus(string);

    Position getPosition();
    void setPosition(int, int);

    void interact();
    void moveActive(int x, int y);

    void displayDetail();

    bool fight(Engimon& enemy);
};

#endif