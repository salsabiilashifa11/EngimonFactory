#include "Engimon.hpp"

Engimon::Engimon() {
    name = "XXX";
    parentName = new string[2];
    //masih bingung respresentsi kelas dan data nya
    species;
    string* skill;
    string* elements;
    level = 0;
    experience = 0;
    cumulativeExperience = 1000;  //kalau mencapai 0, mati
    nature = "NNN";
    ability = "AAA";
}

Engimon::~Engimon() {
    delete[] skill;
    delete[] elements;
}
void levelUp() {
    int count;
    int temp = this->experience;
    count = 0;
    while (temp >= 100) {
        temp -= 100;
        count += 1;
    }
    this->level = count;
}
void increaseXP(int exp) {
    this->experience += exp;
    this->cumulativeExperience -= exp;
}
//void interact();

virtual void displayDetail() = 0;  //berisi semua informasi atribut engimon

//Getter and setter
string Engimon::getName() {
    return this->name;
}
void setName(string name) {
    this->name = name;
}

string getParentName() {
    return this->parentName;
}
void setParentName(string parentName) {
    this->ParentName = parentName;
}

string getSpecies();
void setSpecies(string);

int getLevel() {
    return this->level;
}
void setLevel(int level) {
    this->level = level;
}

int getExperience() {
    return this->experience;
}
void setExperience(int exp) {
    this->experienc = exp;
}

int getCumulativeExperience() {
    return this->cumulativeExperience;
}
void setCumulativeExperience(int cumulativeXP) {
    this->cumulativeExperience = cumulativeXP;
}

string getNature() {
    return this->nature;
}
void setNature(string nature) {
    this->nature = nature;
}

string getAbility() {
    return this->ability;
}
void setAbility(string) {
    this->ability = ability;
}

void setSkill(string*);
string* getSkill();

void setElements(string*);
string* getElements();
