#ifndef _SKILL_HPP_
#define _SKILL_HPP_
#include <iostream>
#include <string>
using namespace std;

class Skill {
    private:
        string* element;
        int nElement;
        string skillName;
        int basePower;
        int masteryLevel;

    public:
        Skill();
        Skill(string skillName, int basePower,int masteryLevel);
        Skill(const Skill&);
        Skill& operator=(const Skill&);
        ~Skill();

        void addElement(string element);
        int getNElement();

        string* getElement();
        void setElement(string* e, int ne);
    
        string getSkillName();
        void setSkillName(string);

        int getBasePower();
        void setBasePower(int);

        int getMasteryLevel();
        void setMasteryLevel(int);

        Skill& getMaxMasteryLevel(Skill&);

        void displaySkill();

        bool isCompatibleSkill(string);
        
};

#endif