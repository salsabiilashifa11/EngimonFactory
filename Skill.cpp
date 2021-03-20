#include "Skill.hpp"
#include<string>
using namespace std;

#include <iostream>

Skill::Skill() {
    this->element = new string[5];
    this->nElement= 0;
    this->skillName = "XXX";
    this->basePower = 0;
    this->masteryLevel = 0;
}

Skill::Skill(string skillName, int basePower,int masteryLevel)  {
    this->element = new string[5];
    this->nElement= 0;
    this->skillName = skillName;
    this->basePower = basePower;
    this->masteryLevel = masteryLevel;
}

Skill::Skill(const Skill& s){
    this->nElement= s.nElement;
    this->skillName = s.skillName;
    this->basePower = s.basePower;
    this->masteryLevel = s.masteryLevel;
    this->element = new string[5];
    for (int i=0; i<s.nElement; i++){
        this->element[i] = s.element[i];
    }
}

Skill& Skill::operator=(const Skill& s){
    delete[] element;
    this->nElement= s.nElement;
    this->skillName = s.skillName;
    this->basePower = s.basePower;
    this->masteryLevel = s.masteryLevel;
    this->element = new string[5];
    for (int i=0; i<s.nElement; i++){
        this->element[i] = s.element[i];
    }
    return *this;
}

Skill::~Skill(){
    delete[] element;
}

void Skill::addElement(string element){
    this->nElement +=1;
    this->element[this->nElement] = element;
}

string* Skill::getElement(){
    return this->element;
}

void Skill::setElement(string* e, int ne){
    nElement = ne;
    for (int i=0; i<ne; i++){
        element[i] = e[i]; 
    }
}
   
string Skill::getSkillName(){
    return this->skillName;
}
void Skill::setSkillName(string skillName){
    this->skillName = skillName;
}

int Skill::getBasePower(){
    return this->basePower;
}
void Skill::setBasePower(int power){
    this->basePower = power;
}

int Skill::getMasteryLevel(){
    return this->masteryLevel;
}
void Skill::setMasteryLevel(int masteryLevel){
    this->masteryLevel = masteryLevel;
}

Skill& Skill::getMaxMasteryLevel(Skill& other){
    if (this->getMasteryLevel() > other.getMasteryLevel()){
        return *this;
    } else {
        return other;
    }
}