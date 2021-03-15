#ifndef _OWNED_ENGIMON_HPP_
#define _OWNED_ENGIMON_HPP_

#include <string>

#include "Cell.hpp"
#include "Engimon.hpp"

// == ACTIVE ENGIMON
class OwnedEngimon : public Engimon {
   private:
    string parentName[2];
    string status;
    Cell position;
    //mapping species dengan message unik pake stl

   public:
    OwnedEngimon(string name, string species);
    ~OwnedEngimon();

    string* getParentName();
    void setParentName(string,string);

    string getStatus();
    void setStatus(string);

    Cell getPosition();
    //void setPosition(int, int);

    void interact();
    void moveActive(int x, int y);

    void displayDetail();
};

#endif