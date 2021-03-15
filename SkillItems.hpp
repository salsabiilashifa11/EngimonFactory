#ifndef _SKILLITEMS_HPP_
#define _SKILLITEMS_HPP_
#include "Skill.hpp"

class SkillItems{
    public:
        SkillItems();
        SkillItems(Skill s, int q);
        SkillItems(const SkillItems& si);
        SkillItems& operator=(const SkillItems& si);
        ~SkillItems();

    private:
        Skill item_skill;
        int quantity;
};

#endif