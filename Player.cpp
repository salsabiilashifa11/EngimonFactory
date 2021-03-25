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

void Player::changeActiveEngimon(){
    int i;
    cout << "Pilih Nomor Engimon yang Akan Jadi Active: "<< endl;
    for (i=0; i<playerEngimons.n_elmt(); i++){
        cout << i+1 << ". " << playerEngimons[i].getName() << " ";
        if (playerEngimons[i].getName() == active.getName()){
            cout << "(active)";
        }
        cout<<endl;
    }
    int input;
    cin >> input;
    playerEngimons[input-1].setPosition(active.getPosition().getX(), active.getPosition().getY());
    active.setPosition(-1,-1);
    setActiveEngimon(input-1);
}

void Player::Breed(Engimon& father, Engimon& mother){
    
    if (father.getLevel() > 30 && mother.getLevel() > 30){
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
            // cout << "nSkill anak : " << child.getNSkill() << endl;
            // cout << "ini i:" << i << endl;
            // cout << "ini j:" << j << endl;
            if (father.getSkill()[i].getMasteryLevel() >= mother.getSkill()[j].getMasteryLevel()){
                for (int l = 0; l < child.getNElements() && child.getNSkill() <= 4; l++){
                    if (!father.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(father.getSkill()[i].getSkillName()) && (i < father.getNSkill())){
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
                    } else if (!mother.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(mother.getSkill()[j].getSkillName()) && (j < mother.getNSkill())){
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
                    if (!mother.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(mother.getSkill()[j].getSkillName()) && (j < mother.getNSkill())){
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
                    } else if (!father.isCorrectElement(child.getElements()[l]) && !child.isMemberSkill(father.getSkill()[i].getSkillName()) && (i < father.getNSkill())){
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
        // Level, experience, and cumulative
        child.setLevel(1);
        // reduce the level of parent
        father.setLevel(fatherLevelBefore-30);
        mother.setLevel(motherLevelBefore-30);
        // child.displayDetail();
        playerEngimons.append(child);
    } else {
        cout << "Belom cukup umur buat kawin." << endl;
    }
}

void Player::Battle(Engimon& musuh){
    musuh.displayDetail();
    bool menang = active.fight(musuh);
    if (!menang){
        cout << "Kalah battle" << endl;
        this->activeMati();
    }
    else{
        cout << "Kamu memenangkan battle" << endl;
        //Set musuh jadi mati
        musuh.setStatus("dead");
        //Nambahin exp
        int activeIndex = playerEngimons.indexByName(active.getName());
        active.increaseXP(50);
        playerEngimons[activeIndex] = active;
        if (active.getCumulativeExperience() >= 20000){
            this->activeMati();
        }
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
        if (playerEngimons.n_elmt() + playerItems.n_elmt() >= MAX_EL) {
            cout << "Inventory penuh" << endl;
            return;
        }
        if (musuh.getNSkill() > 0){
            cout << "nama skill : " << musuh.getSkill()[0].getSkillName() << endl;
            SkillItems skillItemBaru(musuh.getSkill()[0],1);
            this->addToInventory(skillItemBaru);
        }
    }
}

void Player::displayEngimon(string _name) {
    playerEngimons[playerEngimons.indexByName(_name)].displayDetail();
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

Position Player::getPosition() const {
    return playerPos;
}

void Player::setActiveEngimon(int i){
    active = playerEngimons[i];
}

void Player::activeMati(){
    if (playerEngimons.n_elmt() == 1) {
        throw "Kamu ga punya engimon";
    }
    else{
        int activeIndex = playerEngimons.indexByName(active.getName());
        active.setStatus("dead");
        playerEngimons[activeIndex] = active;
        int posX, posY;
        posX = active.getPosition().getX();
        posY = active.getPosition().getY();
        active.setPosition(-1, -1);
        playerEngimons.deleteAt(playerEngimons.indexByName(active.getName()));
        playerEngimons[0].setPosition(posX, posY);
        setActiveEngimon(0);
    }
}

void Player::setPosition(int _x, int _y) {
    playerPos.setX(_x);
    playerPos.setY(_y);
}

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

void Player::showItems() {
    cout << "Skill items: " << endl;
    playerItems.displayAll();
}
void Player::showEngimons() {
    cout << "Engimon: " << endl;
    playerEngimons.displayAll();
}

void Player::makeEngimon() {
    //Engimon
    OwnedEngimon temp("pikachu","kadal");
    temp.addElements("ice");
    temp.setLevel(200);
    Skill s("libasan ekor keadilan",100,100);
    s.addElement("ice");
    temp.addSkill(s);
    this->addToInventory(temp);
    //Active Engimon
    active = temp;
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

void Player::MBA(){
    if (playerEngimons.n_elmt() + playerItems.n_elmt() < 15){
        for (int i=0; i<playerEngimons.n_elmt(); i++){
            if (playerEngimons[i].getLevel() >= 30){
                cout << i+1 << ". " << playerEngimons[i].getName() << " " << endl;
            }
        }
        cout << "Pilih Abi :" << endl;    
        string Abi;
        cin >> Abi;

        cout << "Pilih Mami :" << endl;    
        string Mami;
        cin >> Mami;

        Breed(playerEngimons[playerEngimons.indexByName(Abi)], playerEngimons[playerEngimons.indexByName(Mami)]);
    }
    else
    {
        cout << "inventory penuh, gabisa breed" << endl;
    }
    
}



void Player::teach(string skillName, string eName) {
    Skill newSkill = playerItems[playerItems.indexByName(skillName)].getSkill();
    bool kompatibel = false;

    for (int i = 0; i < playerEngimons[playerEngimons.indexByName(eName)].getNElements(); i++) {
        if (newSkill.getElement()[0] == playerEngimons[playerEngimons.indexByName(eName)].getElements()[i]) {
            kompatibel = true;
        }        
    }

    if (!kompatibel) {
        cout << "Skill item tidak kompatibel" << endl;
        return;
    }
    playerEngimons[playerEngimons.indexByName(eName)].addSkill(newSkill);
    playerItems.deleteAt(playerItems.indexByName(skillName));
}