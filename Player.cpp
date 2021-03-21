#include "Player.hpp"

Player::Player(){
    name = "";
    setPosition(0,0);
    OwnedEngimon temp("pikachu","kadal");
    active = temp;
    Inventory<OwnedEngimon> playerEngimons;
    Inventory<SkillItems> playerItems;
    activeIndex = -1;
}
Player::Player(string _name){
    this->name = _name;
    setPosition(0,0);
    OwnedEngimon temp("pikachu","kadal");
    active = temp;
    Inventory<OwnedEngimon> playerEngimons;
    Inventory<SkillItems> playerItems;
    activeIndex = -1;
}

// default constructor for player
Player::~Player(){

}

void Player::operator=(const Player& p) {
    name = p.name;
    setPosition(p.getPosition().getX(), p.getPosition().getY());
    activeIndex = p.activeIndex;
}

// Commands
void Player::Move(char _direction){
    Position temp = getPosition();
    if (_direction == 'w' and validMove(_direction)){
        setPosition(temp.getX()-1, temp.getY());
    } else if (_direction == 'a' and validMove(_direction)) {
        setPosition(temp.getX(), temp.getY()-1);
    } else if (_direction == 's' and validMove(_direction)) {
        setPosition(temp.getX()+1, temp.getY());
    } else if (_direction == 'd' and validMove(_direction)) {
        setPosition(temp.getX(), temp.getY()+1);
    } else {
        throw ("Nabrak broo");
    }
}

bool Player::validMove(char _direction) {
    Position temp = getPosition();
    if (_direction == 'w'){
        return temp.getX()-1 >= 0;
    } else if (_direction == 'a') {
        return temp.getY()-1 >= 0;
    } else if (_direction == 's') {
        return temp.getX()+1 < 30; //Harus dibikin jadi variabel nanti
    } else if (_direction == 'd') {
        return temp.getY()+1 < 30;
    } else {
        throw _direction;
    }
}

// void Player::changeEngimon(){

// }

void Player::Breed(Engimon& father, Engimon& mother){
    
    if (father.getLevel() >= 30 and mother.getLevel() >= 30){
        OwnedEngimon child;
        int fatherLevelBefore = father.getLevel();
        int motherLevelBefore = mother.getLevel();
        // Memberi nama anak
        string name;
        cout << "Give your child a name :";
        cin >> name;
        child.setName(name);
        // Parent Name
        child.setParentName(father.getName(), mother.getName());
        child.setNSkill(0);
        
        
        // int nSkill
        // udah diset sama addElement
        // Elements
        float fatherAdvantage = ElementAdvantage::getAdv(father.getElements()[0], mother.getElements()[0]);
        float motherAdvantage = ElementAdvantage::getAdv(mother.getElements()[0], father.getElements()[0]);
        if (father.getElements()[0] == mother.getElements()[0]){
            child.addElements(father.getElements()[0]);
            child.setSpecies(father.getSpecies());
            
        } else if (fatherAdvantage > motherAdvantage) {
            child.addElements(father.getElements()[0]);
            child.setSpecies(father.getSpecies());
            
        } else if (fatherAdvantage < motherAdvantage) {
            child.addElements(mother.getElements()[0]);
            child.setSpecies(mother.getSpecies());
        } else {
            child.addElements(mother.getElements()[0]);
            child.addElements(father.getElements()[0]);
            child.setSpecies("KADAL"); //Masih salah
        }
        // Inherit Skill
        // int i = 0;
        // int j = 0;
        // while (child.getNSkill() <= 4 and (i < father.getNSkill() or j < mother.getNSkill())){
        //     if (father.getSkill()[i].getMasteryLevel() > mother.getSkill()[j].getMasteryLevel()){
                
        //         child.addSkill(father.getSkill()[i].getSkillName())
        //     }
        // }
        // Level 
        child.setLevel(0);
        // Experience
        child.setExperience(0);
        // CumulativeExperience;
        child.setCumulativeExperience(0);
        // reduce the level of parent
        father.setLevel(fatherLevelBefore-30);
        mother.setLevel(motherLevelBefore-30);
        child.displayDetail();
        playerEngimons.append(child);
    } 
    else {
        throw ("Gabisa breed. Butuh Nurdin brou");
    }
}


// void Player::checkEngimon(){

// }

// void Player::useItem(SkillItems item){

// }

// // display
// void Player::displayEngimon(){

// }

// void Player::displaySkillItem(){

// }

// void Player::detailEngimon(){

// }

// Getter Setter
OwnedEngimon Player::getActiveEngimon(){
    return active;
}
string Player::getName() {
    return name;
}

int Player::getActiveIndex(){
    return activeIndex;
}

Position Player::getPosition() const {
    return playerPos;
}

// void Player::setActiveEngimon(){}

void Player::setPosition(int _x, int _y) {
    playerPos.setX(_x);
    playerPos.setY(_y);
}

void Player::setActiveIndex(int i) {
    activeIndex = i;
}

void Player::addToInventory(OwnedEngimon el) {
    if (playerEngimons.n_elmt() + playerItems.n_elmt() > MAX_EL) {
        throw "Inventory penuh";
    }
    playerEngimons.append(el);
}

void Player::addToInventory(SkillItems el) {
    if (playerEngimons.n_elmt() + playerItems.n_elmt() > MAX_EL) {
        throw "Inventory penuh";
    }
    playerItems.append(el);
}

void Player::showInventory() {
    cout << "Engimon: " << endl;
    playerEngimons.displayAll();
    cout << "Skill items: " << endl;
    playerItems.displayAll();
}