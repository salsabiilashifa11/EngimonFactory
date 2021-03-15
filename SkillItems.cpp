#include <iostream>
#include "SkillItems.hpp"
using namespace std;

SkillItems::SkillItems(){
    Skill s;
    item_skill = s;
    quantity =1;
}

SkillItems::SkillItems(Skill s, int q){
    item_skill = s;
    quantity = q;
}

SkillItems::SkillItems(const SkillItems& si){
    item_skill = si.item_skill;
    quantity = si.quantity;
}

SkillItems& SkillItems::operator=(const SkillItems& si){
    item_skill = si.item_skill;
    quantity = si.quantity;
    return* this;
}

SkillItems::~SkillItems(){}