#include "Engimon.hpp"
#include "Skill.hpp"

Engimon::Engimon() {
    name = "XXX";
    //masih bingung respresentsi kelas dan data nya
    species = "none";
    skill = new Skill[4];
    elements = new string[5];
    level = 0;
    experience = 0;
    cumulativeExperience = 1000;  //kalau mencapai 0, mati
}

// Engimon::Engimon(string name, const Engimon &mother, const Engimon &father){
//     this->name = name;
//     this->parentName[0] = mother.name;
//     this->parentName[1] = father.name;
// }

Engimon::~Engimon() {
    delete[] skill;
    delete[] elements;
}
void Engimon::levelUp() {
    int count;
    int temp = this->experience;
    count = 0;
    while (temp >= 100) {
        temp -= 100;
        count += 1;
    }
    this->level = count;
}
void Engimon::increaseXP(int exp) {
    this->experience += exp;
    this->cumulativeExperience -= exp;
}

//Getter and setter
string Engimon::getName() {
    return this->name;
}
void Engimon::setName(string name) {
    this->name = name;
}

// string* Engimon::getParentName() {
//     return this->parentName;
// }
// void Engimon::setParentName(string parentName1, string parentName2) {
//     this->parentName[0] = parentName1;
//     this->parentName[1] = parentName2;
// }

string Engimon::getSpecies(){
    return this->species;
}
void Engimon::setSpecies(string species){
    this->species = species;
}

int Engimon::getLevel() {
    return this->level;
}
void Engimon::setLevel(int level) {
    this->level = level;
}

int Engimon::getExperience() {
    return this->experience;
}
void Engimon::setExperience(int exp) {
    this->experience = exp;
}

int Engimon::getCumulativeExperience() {
    return this->cumulativeExperience;
}
void Engimon::setCumulativeExperience(int cumulativeXP) {
    this->cumulativeExperience = cumulativeXP;
}

void Engimon::addSkill(const Skill& s){
    this->nSkill +=1;
    this->skill[nSkill] = s;
}
Skill* Engimon::getSkill(){
    return this->skill;
}

void Engimon::addElements(string element){
    this->nElements +=1;  
    this->elements[this->nElements] = element;
}
string* Engimon::getElements(){
    return this->elements;
}
