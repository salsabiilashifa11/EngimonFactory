#include "Player.hpp"

Player::Player(){
    name = "";
    setPosition(0,0);
    // Engimon active;
    // Inventory playerInventory;
    activeIndex = -1;
}
Player::Player(string _name){
    this->name = _name;
    setPosition(0,0);
    // Engimon active;
    // Inventory playerInventory;
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
    } else if (_direction == 'd'and validMove(_direction)) {
        setPosition(temp.getX(), temp.getX()+1);
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
        return temp.getX()+1 < 30;
    } else {
        throw _direction;
    }
}

// void Player::changeEngimon(){

// }

OwnedEngimon Player::Breed(Engimon& father, Engimon& mother){
    
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
        // Species
        int random = rand() % 1;
        if (random == 1){
            child.setSpecies(father.getSpecies());
        } else {
            child.setSpecies(mother.getSpecies());
        }
        child.setNSkill(0);
        // Inherit skill
        
        // int nSkill
        // udah diset sama addElement
        // Elements
        
        // Level 
        child.setLevel(0);
        // Experience
        child.setExperience(0);
        // CumulativeExperience;
        child.setCumulativeExperience(0);
        // reduce the level of parent
        father.setLevel(fatherLevelBefore-30);
        mother.setLevel(motherLevelBefore-30);
        return child;
    } else {
        // throw message 
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

// void Player::addToInventory(OwnedEngimon el) {
//     if (playerEngimons.n_elmt() + playerItems.n_elmt() > MAX_EL) {
//         throw "Inventory at max capacity";
//     }
//     playerEngimons.append(el);
// }

// void Player::addToInventory(SkillItems el) {
//     if (playerEngimons.n_elmt() + playerItems.n_elmt() > MAX_EL) {
//         throw "Inventory at max capacity";
//     }
//     playerItems.append(el);
// }