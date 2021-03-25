#include "WildEngimon.hpp"
#include "Cell.hpp"

map<string,string> WildEngimon::spesiesSkill = {{"kadal","libasan ekor keadilan"},{"ikan","tembakan gelembung kebebasan"},{"kambing", "serudukan tanduk keputusasaan"}, {"beruang", "cakaran cakar kematian"}, {"kelelawar", "teriakan ultrasonic kemarahan"}};

int WildEngimon::element2int(string element) {
    if (element == "fire" || element == "ground" || element == "electric") {
        return 1;
    } else {
        return 2;
    }
}

WildEngimon::WildEngimon() : Engimon() {
    status = "wild";
}

WildEngimon::WildEngimon(string species, string element, int level, int x, int y, Map* m) : Engimon() {
    this->name = species;
    this->species = species;
    string namaSkill = spesiesSkill.find(this->species)->second;
    int basePower;
    if (species == "kadal"){
        basePower = 100;
    }
    else if (species == "ikan"){
        basePower = 110;
    }
    else if (species == "kambing"){
        basePower = 120;
    }
    else if (species == "beruang"){
        basePower = 130;
    }
    else if (species == "kelelawar"){
        basePower = 140;
    }
    int masteryLevel = 1;
    Skill s(namaSkill,basePower,masteryLevel);
    this->elements[0] = element;
    this->nElements = 1;
    s.addElement(this->elements[0]);
    this->nSkill = 0;
    this->addSkill(s);
    this->level = level;
    this->experience = 0;
    this->cumulativeExperience = this->level*100;
    this->status = "wild";
    setPosition(x, y, m); 
}


void WildEngimon::operator=(const WildEngimon &other){
    // panggil ini aja
    // Engimon::operator=(other);
    this->name = other.species;
    this->species = other.species;
    this->nSkill = other.nSkill;
    delete[] this->skill;
    this->skill = new Skill[this->nSkill];
    for (int i = 0;i<this->nSkill;i++){
        this->skill[i] = other.skill[0];
    }
    delete[] this->elements;
    this->elements = new string[4];
    this->elements[0] = other.elements[0];
    this->nElements = other.nElements;
    this->level = other.level;
    this->experience = other.experience;
    this->cumulativeExperience = other.cumulativeExperience;
    this->status = other.status;
    this->position = other.position;

}

WildEngimon::~WildEngimon(){
    
}

string WildEngimon::getStatus(){
    return this-> status;
}

void WildEngimon::setStatus(string newstat){
    this->status = newstat;
}

Position WildEngimon::getPosition(){
    return this->position;
}

void WildEngimon::setPosition(int x, int y, Map* m) {
    position.setX(x);
    position.setY(y);

    // m->getCell(x, y).setEngimon(this);
}

void WildEngimon::assertPosition(Map* m) {
    m->getCell(position.getX(), position.getY()).setEngimon(this);
}


void WildEngimon::Move(Map* m){
    //get elemen
    //, CellType Wtype
    int x = position.getX();
    int y = position.getY();
    int number;
    number = rand() % 4 + 1;
    Engimon* temp = new WildEngimon();
    
    if (number == 1){
        if (validPosition(m, x, y+1)){
            m->getCell(x,y).setEngimon(temp);
            setPosition(x, y+1, m);
        }    
    } else if (number == 2){
        if (validPosition(m, x, y-1)){
            m->getCell(x,y).setEngimon(temp);
            setPosition(x, y-1, m);
        }
    } else if (number == 3){
        if (validPosition(m, x+1, y)){
            m->getCell(x,y).setEngimon(temp);
            setPosition(x+1, y, m);
        }
    } else {
        if (validPosition(m, x-1, y)){
            m->getCell(x,y).setEngimon(temp);
            setPosition(x-1, y, m);
        }
    }

}

bool WildEngimon::validPosition(Map* m, int x, int y) {
    CellType Wtype;
    Cell cell =  m->getCell(x,y);
    switch(element2int(getElements()[0])){
        case 1:
            Wtype = Grassland;
            break;
        case 2:
            Wtype = Sea;
            break;
        default:
            break;
    }
    if (x < 0  || x >= 30 || 
        y < 0 || y >=30 || 
        Wtype != cell.getType() ||
        cell.getOccupierE()->getName() != "XXX" ||
        cell.getOccupierP().getName() != "")
         {
            //throw("Kambing cuma bisa di air cuy");
            return false;
        } 
    return true;
}

void WildEngimon::displayDetail() {
    cout << "Nama : " << this->name << endl;
    cout << "Species : " << this->species << endl;
    cout << "Skill : ";
    cout << " NamaSkill : " << this->skill[0].getSkillName();
    cout << " BasePower : " << this->skill[0].getBasePower();
    cout << " MasteryLevel : " << this->skill[0].getMasteryLevel();
    cout << endl;
    cout << "Element : ";
    cout << this->elements[0];
    cout << endl;
    cout << "Level : " << this->level << endl;
}