#include <iostream>
#include "SkillItems.hpp"
using namespace std;

SkillItems::SkillItems(){
    Skill temp;
    item_skill = temp;
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

int SkillItems::getQuantity() const {
    return this->quantity;
}

void SkillItems::addQuantity(int n) {
    this->quantity += n;
}

string SkillItems::getName() {
    return item_skill.getSkillName();
}

Skill SkillItems::getSkill() {
    return this->item_skill;
}