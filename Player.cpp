#include "Player.hpp"

Player::Player(){
    name = "";
    setPosition(0,0);
    this->makeEngimon();
    this->initiateSkill();
}

Player::Player(string _name){
    this->name = _name;
    setPosition(0,0);
    this->makeEngimon();
    this->initiateSkill();
}

// default constructor for player
Player::~Player(){

}

void Player::operator=(const Player& p) {
    name = p.name;
    setPosition(p.getPosition().getX(), p.getPosition().getY());
    // activeIndex = p.activeIndex;
}

// Commands
void Player::Move(char _direction){
    Position temp = getPosition();
    if (validMove(_direction)) {

        //Engimon follow
        active.setPosition(temp.getX(),temp.getY());

        if (_direction == 'w'){
            setPosition(temp.getX()-1, temp.getY());
        } else if (_direction == 'a') {
            setPosition(temp.getX(), temp.getY()-1);
        } else if (_direction == 's') {
            setPosition(temp.getX()+1, temp.getY());
        } else if (_direction == 'd') {
            setPosition(temp.getX(), temp.getY()+1);
        } 
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
    
    if (father.getLevel() > 30 and mother.getLevel() > 30){
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
        int i = 0;
        int j = 0;
        while (child.getNSkill() <= 4 && (i < father.getNSkill() || j < mother.getNSkill())){
            if (father.getSkill()[i].getMasteryLevel() >= mother.getSkill()[j].getMasteryLevel()){
                for (int l = 0; l < child.getNElements() && child.getNSkill() <= 4; l++){
                    cout << "ini l : " << l << endl;
                    if (!father.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(father.getSkill()[i].getSkillName())){
                        child.addSkill(father.getSkill()[i]);
                        if (!mother.isMemberSkill(father.getSkill()[i].getSkillName())){
                            int skillIdx = mother.findSkillIndex(father.getSkill()[i].getSkillName());
                            if (skillIdx != -1){
                                int idxAnak = child.findSkillIndex(father.getSkill()[i].getSkillName());
                                if (father.getSkill()[i].getMasteryLevel() == mother.getSkill()[skillIdx].getMasteryLevel()){   // Kalo levelnya sama
                                    child.getSkill()[idxAnak].setMasteryLevel(father.getSkill()[i].getMasteryLevel() + 1);
                                } else {    // Kalo levelnya beda
                                    child.getSkill()[idxAnak].setMasteryLevel(max(father.getSkill()[i].getMasteryLevel(), mother.getSkill()[skillIdx].getMasteryLevel()));
                                }
                            } 
                        }
                        i++;
                    } else if (!mother.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(mother.getSkill()[j].getSkillName())){
                        child.addSkill(mother.getSkill()[j]);
                        if (!father.isMemberSkill(mother.getSkill()[j].getSkillName())){
                            int skillIdx = father.findSkillIndex(mother.getSkill()[j].getSkillName());
                            if (skillIdx != -1){
                                int idxAnak = child.findSkillIndex(mother.getSkill()[j].getSkillName());
                                if (mother.getSkill()[j].getMasteryLevel() == father.getSkill()[skillIdx].getMasteryLevel()){
                                    child.getSkill()[idxAnak].setMasteryLevel(father.getSkill()[i].getMasteryLevel() + 1);
                                } else {
                                    child.getSkill()[idxAnak].setMasteryLevel((max(father.getSkill()[skillIdx].getMasteryLevel(), mother.getSkill()[j].getMasteryLevel())));
                                }
                            }
                        }
                        j++;
                    } else {
                        i++;
                        j++;
                    }
                }
            } else {
                for (int l = 0; l < child.getNElements() && child.getNSkill() <= 4; l++){
                    if (!mother.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(mother.getSkill()[j].getSkillName())){
                        child.addSkill(mother.getSkill()[j]);
                        if (!father.isMemberSkill(mother.getSkill()[j].getSkillName())){
                            int skillIdx = father.findSkillIndex(mother.getSkill()[j].getSkillName());
                            if (skillIdx != -1){
                                int idxAnak = child.findSkillIndex(mother.getSkill()[j].getSkillName());
                                if (mother.getSkill()[j].getMasteryLevel() == father.getSkill()[skillIdx].getMasteryLevel()){
                                    child.getSkill()[idxAnak].setMasteryLevel(father.getSkill()[i].getMasteryLevel() + 1);
                                } else {
                                    child.getSkill()[idxAnak].setMasteryLevel((max(father.getSkill()[skillIdx].getMasteryLevel(), mother.getSkill()[j].getMasteryLevel())));
                                }
                            }
                        }
                        j++;
                    } else if (!father.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(father.getSkill()[i].getSkillName())){
                        child.addSkill(father.getSkill()[i]);
                        if (!mother.isMemberSkill(father.getSkill()[i].getSkillName())){
                            int skillIdx = mother.findSkillIndex(father.getSkill()[i].getSkillName());
                            if (skillIdx != -1){
                                int idxAnak = child.findSkillIndex(father.getSkill()[i].getSkillName());
                                if (father.getSkill()[i].getMasteryLevel() == mother.getSkill()[skillIdx].getMasteryLevel()){   // Kalo levelnya sama
                                    child.getSkill()[idxAnak].setMasteryLevel(father.getSkill()[i].getMasteryLevel() + 1);
                                } else {    // Kalo levelnya beda
                                    child.getSkill()[idxAnak].setMasteryLevel(max(father.getSkill()[i].getMasteryLevel(), mother.getSkill()[skillIdx].getMasteryLevel()));
                                }
                            } 
                        }
                        i++;
                    } else {
                        i++;
                        j++;
                    }
                }
            }
            // cout << "ini i :" << i << endl;
            // i++; 
            //cout << "ini j :" << j << endl;
            j++;
        }
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
    } else {
        throw ("Gabisa breed.");
    }
}

void Player::Battle(Engimon& musuh){
    bool menang = active.fight(musuh);
    if (!menang){
        cout << "Kalah battle" << endl;
        playerEngimons.deleteAt(playerEngimons.indexByName(active.getName()));
        if (playerEngimons.n_elmt() == 0) {
            throw "Engimon abis, kamu kalah";
        }
        else{
            setActiveEngimon(0);
        }
    }
    else{
        cout << "Kamu memenangkan battle" << endl;
        musuh.setStatus("dead");
        if (playerEngimons.n_elmt() + playerItems.n_elmt() >= MAX_EL) {
            cout << "Inventory penuh" << endl;
            return;
        }
        //Nambahin engimon
        OwnedEngimon baru;
        baru.setParentName("", "");
        baru.setName(musuh.getName());
        baru.setSpecies(musuh.getSpecies());
        baru.addElements(musuh.getElements()[0]);
        for (int i = 0; i < musuh.getNSkill(); i++) {
            baru.addSkill(musuh.getSkill()[i]);
        }
        baru.setLevel(musuh.getLevel());
        baru.setExperience(musuh.getExperience());
        baru.setCumulativeExperience(musuh.getCumulativeExperience());
        addToInventory(baru);
        //Nambahin skill items
        if (musuh.getNSkill() > 0){
            cout<<"Hai"<<endl;
            cout << "nama skill : " << musuh.getSkill()[0].getSkillName() << endl;
            SkillItems skillItemBaru(musuh.getSkill()[0],1);
            this->addToInventory(skillItemBaru);
        }
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
OwnedEngimon& Player::getActiveEngimon(){
    return active;
}
string Player::getName() {
    return name;
}

// int Player::getActiveIndex(){
//     return activeIndex;
// }

Position Player::getPosition() const {
    return playerPos;
}

void Player::setActiveEngimon(int i){
    active = playerEngimons[i];
}

void Player::setPosition(int _x, int _y) {
    playerPos.setX(_x);
    playerPos.setY(_y);
}

// void Player::setActiveIndex(int i) {
//     activeIndex = i;
//     active = playerEngimons[activeIndex];
// }

void Player::addToInventory(OwnedEngimon el) {
    if (playerEngimons.n_elmt() + playerItems.n_elmt() < MAX_EL) {
        playerEngimons.append(el);
    }
}

void Player::addToInventory(SkillItems el) {
    if (playerEngimons.n_elmt() + playerItems.n_elmt() < MAX_EL) {
        playerItems.append(el);
    }
    
}

void Player::showInventory() {
    cout << "Engimon: " << endl;
    playerEngimons.displayAll();
    cout << "Skill items: " << endl;
    playerItems.displayAll();
}

void Player::makeEngimon() {
    //Engimon
    OwnedEngimon temp("pikachu","kadal");
    temp.addElements("ice");
    temp.setLevel(50);
    Skill s("libasan ekor keadilan",100,1);
    s.addElement("ice");
    temp.addSkill(s);
    this->addToInventory(temp);
    //Active Engimon
    active = temp;
    // activeIndex = 0;
    active.setPosition(this->playerPos.getX(),this->playerPos.getY()+1);
}

void Player::initiateSkill() {
    //Inventory Skill Item
    Skill s1("Pesanan es teh manis",100,1);
    s1.addElement("ice");
    Skill s2("Kekuatan kencing di dalam celana",100,1);
    s2.addElement("water");
    Skill s3("Seruputan rokok sampoerna",100,1);
    s3.addElement("fire");
    Skill s4("Stone Holder",100,1);
    s4.addElement("ground");
    Skill s5("PLN mati lampu",100,1);
    s5.addElement("electric");
    SkillItems sk1(s1,1);
    SkillItems sk2(s2,1);
    SkillItems sk3(s3,1);
    SkillItems sk4(s4,1);
    SkillItems sk5(s5,1);
    this->addToInventory(sk1);
    this->addToInventory(sk2);
    this->addToInventory(sk3);
    this->addToInventory(sk4);
    this->addToInventory(sk5);
}

