#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#include <string>

#include "Skill.hpp"

class Engimon {
   protected:
    string name;
    string* parentName;
    string species;
    Skill* skill;
    string* elements;
    int level;
    int experience;
    int cumulativeExperience;
    string nature;
    string ability;

   public:
    Engimon();
    virtual ~Engimon();
    void levelUp();
    int increaseXP();
    //void interact();

    virtual void displayDetail() = 0;  //berisi semua informasi atribut engimon

    //Getter and setter
    string getName();
    void setName(string);

    string getParentName();
    void setParentName(string);

    string getSpecies();
    void setSpecies(string);

    int getLevel();
    void setLevel(int);

    int getExperience();
    void setExperience(int);

    int getCumulativeExperience();
    void setCumulativeExperience();

    string getNature();
    void setNature(string);

    string getAbility();
    void setAbility(string);

    void setSkill(Skill);
    Skill* getSkill();

    string* getElements();
    void setElements(string*);
};

#endif
