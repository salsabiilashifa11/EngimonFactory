#ifndef _OWNED_ENGIMON_HPP_
#define _OWNED_ENGIMON_HPP_

#include <string>

#include "Cell.hpp"
#include "Engimon.hpp"

// == ACTIVE ENGIMON
class OwnedEngimon : public Engimon {
   private:
    string status;
    Cell position;

   public:
    OwnedEngimon();
    ~OwnedEngimon();

    string getStatus();
    void setStatus(string);

    Cell getPosition();
    void setPosition(int, int);

    void interact();
    void moveOwned(string);
};

#endif