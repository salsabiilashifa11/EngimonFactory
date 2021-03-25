#include "Engimon.hpp"
// namespace EngimonFactory {
Engimon::Engimon() {
    name = "XXX";
    species = "none";
    skill = new Skill[4];
    nSkill = 0;
    elements = new string[2];
    nElements = 0;
    level = 1;
    experience = 0;
    cumulativeExperience = 0;  
}

Engimon::Engimon(const Engimon& e) {
    name = e.name;
    species = e.species;
    skill = new Skill[4];
    elements = new string[2];
    level = e.level;
    experience = e.experience;
    cumulativeExperience = e.cumulativeExperience;

    for (int i = 0; i < e.nSkill; i++) {
        skill[i] = e.skill[i];
    }
    nSkill = e.nSkill;
    for (int i = 0; i < e.nElements; i++) {
        elements[i] = e.elements[i];
    }
    nElements = e.nElements;
}

Engimon& Engimon::operator=(const Engimon& e) {
    delete[] skill;
    delete[] elements;

    name = e.name;
    species = e.species;
    skill = new Skill[4];
    elements = new string[5];
    level = e.level;
    experience = e.experience;
    cumulativeExperience = e.cumulativeExperience;

    for (int i = 0; i < e.nSkill; i++) {
        skill[i] = e.skill[i];
    }
    nSkill = e.nSkill;
    for (int i = 0; i < e.nElements; i++) {
        elements[i] = e.elements[i];
    }
    nElements = e.nElements;

    return *this;
}

Engimon::~Engimon() {
    delete[] skill;
    delete[] elements;
}
void Engimon::levelUp() {
    while (this->experience >= 100) {
        this->experience -= 100;
        this->level += 1;
    }
}
void Engimon::increaseXP(int exp) {
    this->experience += exp;
    this->cumulativeExperience += exp;
    this->levelUp();
}

//Getter and setter
string Engimon::getName() {
    return this->name;
}
void Engimon::setName(string name) {
    this->name = name;
}

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
    this->experience = 0;
    this->cumulativeExperience = (level-1)*100;
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
    this->skill[nSkill] = s;
    this->nSkill +=1;

    quickSort(this->skill, 0, (this->nSkill)-1);
}
Skill* Engimon::getSkill(){
    return this->skill;
}

void Engimon::addElements(string element){
    this->elements[this->nElements] = element;
    this->nElements +=1;  
}

string* Engimon::getElements(){
    return this->elements;
}

int Engimon::getNSkill(){
    return nSkill;
}

void Engimon::setNSkill(int n){
    nSkill = n;
}

bool Engimon::isMemberSkill(string skill){
    bool status = false;
    int i = 0;
    while (!status and (i < nSkill)){
        if (this->skill[i].getSkillName() == skill) {
            status = true;
        } else {
            i++;
        }
    }
    return status;
}

int Engimon::findSkillIndex(string skill){
    bool status = false;
    int i = 0;
    while (!status and (i < nSkill)){
        if (this->skill[i].getSkillName() == skill) {
            status = true;
        } else {
            i++;
        }
    }
    if (i<nSkill){
        return i;
    } else {
        return -1;
    }
}

bool Engimon::isCorrectElement(string childElements){
    bool status = false;
    int i = 0;
    while (!status and (i < nElements)){
        if (this->elements[i] == childElements) {
            status = true;
        } else {
            i++;
        }
    }
    return status;
}

// Sorting and its addtional methods
void Engimon::swap(Skill* a, Skill* b)
{
    Skill t = *a;
    *a = *b;
    *b = t;
}

int Engimon::partition(Skill* arr, int low, int high)
{
    int pivot = arr[high].getMasteryLevel();    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].getMasteryLevel() >= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Engimon::quickSort(Skill* arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Engimon::getNElements(){
    return this->nElements;
}

void Engimon::setNElements(int n){
    this->nElements = n;
}

float Engimon::getStrongestEl(Engimon& enemy) {
    float strongest = ElementAdvantage::getAdv(this->getElements()[0], enemy.getElements()[0]);

    for (int i = 0; i < this->getNElements(); i++) {
        for (int j = 0; j < enemy.getNElements(); j++) {
            float temp = ElementAdvantage::getAdv(this->getElements()[i], enemy.getElements()[j]);
            if (temp > strongest) {
                strongest = temp;
            }
        }
    }

    return strongest;
}