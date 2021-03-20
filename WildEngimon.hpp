#ifndef _WILD_ENGIMON_HPP_
#define _WILD_ENGIMON_HPP_

#include <string>
#include "Cell.hpp"
#include "Engimon.hpp"

class WildEngimon : public Engimon {
   private:
    string status;
    Cell position;
   public:
    WildEngimon();
    ~WildEngimon();

    string getStatus();
    void setStatus(string);

    Cell getPosition();
    void setPosition(int, int);

};

WildEngimon::WildEngimon(/* args */) {
}

WildEngimon::~WildEngimon() {
}

#endif
    