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
    if (_direction == 'w'){
        setPosition(temp.getX(), temp.getY()-1);
    } else if (_direction == 'a') {
        setPosition(temp.getX()-1, temp.getY());
    } else if (_direction == 's') {
        setPosition(temp.getX(), temp.getY()+1);
    } else if (_direction == 'd') {
        setPosition(temp.getX()+1, temp.getY());
    } else {
        throw _direction;
    }
}

void Player::changeEngimon();
Engimon Player::Breed(Engimon father, Engimon mother){
    
    if (father.getLevel() >= 30 and mother.getLevel() >= 30){
        OwnedEngimon child();
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
        // Inherit skill
        
        // int nSkill
        
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
    } else {
        // throw message 
    }
}

void Player::Battle();
void Player::checkEngimon();
void Player::useItem(Item);
// Interact

// display
void Player::displayEngimon();
void Player::displaySkillItem();
void Player::detailEngimon();

// Getter Setter
// Engimon getActiveEngimon();
string Player::getName() {
    return name;
}

int Player::getActiveIndex(){
    return activeIndex;
}

Position Player::getPosition() const {
    return playerPos;
}

// void Player::setActiveEngimon();
void Player::setPosition(int _x, int _y) {
    playerPos.setX(_x);
    playerPos.setY(_y);
}

void Player::setActiveIndex(int i) {
    activeIndex = i;
}

void Player::addToInventory(OwnedEngimon el) {
    // if (playerEngimons.n_elmt() + playerItems.n_elmt() > MAX_EL) {
    //     throw error;
    // }
    playerEngimons.append(el);
}