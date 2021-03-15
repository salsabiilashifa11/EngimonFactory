#ifndef _SKILL_HPP_
#define _SKILL_HPP_

#include <string>

//list of species dengan skillnya
class Skill {
   private:
    //sebuah skill dimiliki oleh species dan elemen tertentu
    //string elements;
    //string species;
    string skillName;
    int basePower;
    int masteryLevel;

   public:
    Skill(/* args */);
    //Skill(string species, string elements);
    ~Skill();

    string getSkillName();
    void setSkillName(string);

    int getBasePower();
    void setBasePower(int);

    int getMasteryLevel();
    void setMasteryLevel(int);
};

#endif