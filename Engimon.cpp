#include "Engimon.hpp"

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

    quickSort(this->skill, 0, (this->nSkill)-1);
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

int Engimon::getNSkill(){
    return nSkill;
}

void Engimon::setNSkill(int n){
    nSkill = n;
}

bool Engimon::isMemberSkill(string skill){
    bool status = false;
    int i = 0;
    while (status and (i < nSkill)){
        if (this->skill[i].getSkillName() == skill) {
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