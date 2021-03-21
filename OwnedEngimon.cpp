#include "OwnedEngimon.hpp"


map<string, string> OwnedEngimon::percakapan = {{"fire","halo saya api"}, {"water","halo saya air"}, {"kadal","halo saya listrik"}, {"ground","halo saya tanah"}, {"ice","halo saya es"}};

OwnedEngimon::OwnedEngimon() : Engimon() {
    this->status = "owned";
    this->parentName = new string[2];
    this->position = Position();
}

OwnedEngimon::OwnedEngimon(string name, string species) : Engimon() {
    this->name = name;
    this->species = species; 
    this->status = "owned";
    this->parentName = new string[2];
    this->position = Position();
}

OwnedEngimon::OwnedEngimon(const OwnedEngimon& oe) : Engimon(oe) {
    this->status = oe.status;
    this->parentName = new string[2];
    this->parentName[0] = oe.parentName[0];
    this->parentName[1] = oe.parentName[1];
}

OwnedEngimon& OwnedEngimon::operator=(const OwnedEngimon& oe) {
    Engimon::operator=(oe);
    delete[] parentName;
    this->status = oe.status;
    this->parentName = new string[2];
    this->parentName[0] = oe.parentName[0];
    this->parentName[1] = oe.parentName[1];

    
    return *this;
}

OwnedEngimon::~OwnedEngimon(){
    delete[] parentName;
}

// OwnedEngimon& OwnedEngimon::operator=(const OwnedEngimon& other){
//     delete[] parentName;
//     this->name = other.name;
//     this->species = other.species; 
//     this->status = other.status;
//     this->parentName = new string[2];
//     this->parentName[0] = other.getParentName()[0];
//     this->position = other.position;

// }

string* OwnedEngimon::getParentName(){
    return this->parentName;
}

void OwnedEngimon::setParentName(string parentName1, string parentName2)  {
    this->parentName[0] = parentName1;
    this->parentName[1] = parentName2;
}

string OwnedEngimon::getStatus(){
    return this->status;    
}

void OwnedEngimon::setStatus(string s){
    this->status = s;
}

Position OwnedEngimon::getPosition(){
    return this->position;
}

void OwnedEngimon::setPosition(int x, int y){
    this->position.setX(x);
    this->position.setY(y);
}

void OwnedEngimon::interact(){
    // map<string, string> percakapan;
    // percakapan.insert(pair<string, string> ("fire","halo saya api"));
    // percakapan.insert(pair<string, string> ("water","halo saya air"));
    // percakapan.insert(pair<string, string> ("lightning","halo saya listrik"));
    // percakapan.insert(pair<string, string> ("ground","halo saya tanah"));
    // percakapan.insert(pair<string, string> ("ice","halo saya es"));
    cout << percakapan.find(this->species)->second << endl;
}

void OwnedEngimon::displayDetail(){
    cout << "Nama : " << this->name << endl;
    cout << "Species : " << this->species << endl;
    cout << "Skill : ";
    for (int i = 0; i< this->nSkill; i++){
        cout << i+1 << ". "; 
        cout << " NamaSkill : " << this->skill[i].getSkillName();
        cout << " BasePower : " << this->skill[i].getBasePower();
        cout << " MasteryLevel : " << this->skill[i].getMasteryLevel() << " ";
    }
    cout << endl;
    cout << "Element : ";
    for (int i = 0; i< this->nElements; i++){
        cout << i+1 << ". "; 
        cout << this->elements[i];
    }
    cout << endl;
    cout << "Level : " << this->level << endl;
    cout << "Experience : " << this->experience << endl;
    cout << "CumulativeExperience : " << this->cumulativeExperience << endl;
    cout << "Parent 1 : " << this->getParentName()[0] << endl;
    cout << "Parent 2 : " << this->getParentName()[1] << endl;
    cout << "Status : " << this->status << endl;
}

void OwnedEngimon::moveActive(int x, int y){
    if (x!=29){
        this->position.setX(x+1);
        this->position.setY(y);
    }
    else if (y!=0){
        this->position.setX(x);
        this->position.setY(y-1);
    }
    else{
        this->position.setX(x);
        this->position.setY(y+1);
    }
}



bool OwnedEngimon::fight(Engimon& enemy) {
    float myPower = 0;
    myPower += getStrongestEl(enemy) * this->level;
    for (int i = 0; i < this->nSkill; i++) {
        myPower += this->skill[i].getBasePower() * this->skill[i].getMasteryLevel();
    }

    float enemyPower = 0;
    enemyPower += enemy.getStrongestEl(*this) * enemy.getLevel();
    for (int i = 0; i < enemy.getNSkill(); i++) {
        enemyPower += enemy.getSkill()[i].getBasePower() * enemy.getSkill()[i].getMasteryLevel();
    }

    cout << "My Power : " << myPower << endl;
    cout << "Enemy Power : " << enemyPower << endl;

    return myPower > enemyPower;
}


