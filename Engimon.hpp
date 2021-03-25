#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#include <stdlib.h>
#include <string>
#include <array>
#include "Skill.hpp"
#include "ElementAdvantage.hpp"
using namespace std;

    class Engimon {
    protected:
        string name;
        string species;
        Skill* skill;
        int nSkill;
        string* elements;
        int nElements;
        int level;
        int experience;
        int cumulativeExperience;

    public:
        Engimon();
        Engimon(const Engimon& e);
        Engimon& operator=(const Engimon& e);
        virtual ~Engimon();
        void levelUp();
        void increaseXP(int);
        virtual void displayDetail() = 0;  
        virtual string getStatus() = 0;
        virtual void setStatus(string) = 0;
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

        int getNElements();
        void setNElements(int);

        int getNSkill();
        void setNSkill(int);

        bool isMemberSkill(string);
        bool isCorrectElement(string);
        int findSkillIndex(string);
        float getStrongestEl(Engimon& enemy);

        void swap(Skill* a, Skill* b);
        int partition(Skill* arr, int low, int high);
        void quickSort(Skill* arr, int low, int high);
    };

#endif