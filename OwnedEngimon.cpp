#include "OwnedEngimon.hpp"


map<string, string> OwnedEngimon::percakapan = {{"ikan","halo saya api"}, {"kambing","halo saya air"}, {"beruang","halo saya listrik"}, {"kelelawar","halo saya tanah"}, {"kadal","halo saya es"}, {"siamang","halo saya kebakaran"}, {"mammoth", "halo saya LDR"}, {"kecoa", "halo saya subur"}};

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
    cout << "[" << this->name << "]: " << percakapan.find(this->species)->second << endl;
}

void OwnedEngimon::displayDetail(){
    cout << "=====================Info Engimon=====================" << endl;
    cout << "Nama                   : " << this->name << endl;
    cout << "Species                : " << this->species << endl;
    cout << "Skill                  : " << endl;
    for (int i = 0; i< this->nSkill; i++){
        cout << "    " << i+1 << ". ";
        this->skill[i].displaySkill();
        cout << endl;
    }
    cout << "Element                : ";
    for (int i = 0; i< this->nElements; i++){
        cout << i+1 << ". "; 
        cout << this->elements[i];
        if (i != this->nElements - 1){
            cout << " | ";
        }
    }
    cout << endl;
    cout << "Level                  : " << this->level << endl;
    cout << "Experience             : " << this->experience << endl;
    cout << "Cumulative Experience  : " << this->cumulativeExperience << endl;
    cout << "Abi                    : " << this->getParentName()[0] << endl;
    cout << "Mami                   : " << this->getParentName()[1] << endl;
    cout << "Status                 : " << this->status << endl;
    cout << "=======================================================" << endl;
    
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
    cout << "======================Info Battle======================" << endl;
    cout << "My Power       : " << myPower << endl;
    cout << "Enemy Power    : " << enemyPower << endl;

    return myPower > enemyPower;
}