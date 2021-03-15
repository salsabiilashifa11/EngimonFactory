#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#include <string>
#include <array>
#include "Skill.hpp"

class Engimon {
   protected:
    string name;
    string species;
    Skill* skill;
    int nSkill;
    string elements[5];
    int nElements;
    int level;
    int experience;
    int cumulativeExperience;
    //mapping species dengan skill unik pake stl

   public:
    Engimon();
    // Engimon(string name, const Engimon mother, const Engimon father);
    virtual ~Engimon();
    void levelUp();
    void increaseXP(int);
    //void interact();

    virtual void displayDetail() = 0;  //berisi semua informasi atribut engimon

    //Getter and setter
    string getName();
    void setName(string);

    string getSpecies();
    void setSpecies(string);

    int getLevel();
    void setLevel(int);

    int getExperience();
    void setExperience(int);

    int getCumulativeExperience();
    void setCumulativeExperience(int);

    void addSkill(const Skill&);
    Skill* getSkill();

    string* getElements();
    void addElements(string);
};

#endif
