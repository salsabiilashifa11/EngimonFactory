#ifndef _SKILLITEMS_HPP_
#define _SKILLITEMS_HPP_
#include "Skill.hpp"
#include <iostream>
//using namespace Skill;
class SkillItems{
    private:
        Skill item_skill;
        int quantity;
    public:
        SkillItems();
        SkillItems(Skill s, int q);
        SkillItems(const SkillItems& si);
        SkillItems& operator=(const SkillItems& si);
        ~SkillItems();
        int getQuantity() const;
        string getName();
        void addQuantity(int n);
        Skill getSkill();

};

#endif