#include "Cell.hpp"
#include "WildEngimon.hpp"

//4 Sekawan
Cell::Cell() {
    x = -1;
    y = -1;
    type = Grassland;
    occupierE = new WildEngimon();
}

Cell::Cell(int _x, int _y, CellType _type) {
    x = _x;
    y = _y;
    type = _type;
    occupierE = new WildEngimon();
}

Cell::Cell(const Cell& c) {
    x = c.x;
    y = c.y;
    type = c.type;
    occupierP = c.occupierP;
    occupierE = c.occupierE;
}

void Cell::operator=(const Cell& c) {
    x = c.x;
    y = c.y;
    type = c.type;
    occupierP = c.occupierP;
    occupierE = c.occupierE;
}

Cell::~Cell(){}

//Getter dan Setter
int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

CellType Cell::getType() {
    return type;
}

Engimon* Cell::getOccupierE() {
    return occupierE;
}

void Cell::setPlayer(Player& p) {
    occupierP = p;
}

void Cell::setEngimon(Engimon* e) {
    this->occupierE = e;
}

//Method
void Cell::drawCell() {
    
    //Condition 1: player
    if (occupierP.getName() != "") {
        cout << "P";
    } 
    //Condition 2: Alive engimons
    else if (occupierE->getStatus() != "dead" && occupierE->getName() != "XXX") {
        drawEngimon(30);
    }
    //Condition 3: dummy occupiers
    else {
        if (type == Sea) {
            cout << "o";
        } else {
            cout << "-";
        }
    } 

}

void Cell::drawEngimon(int level_min) {

    string element = occupierE->getElements()[0];
    int level = occupierE->getLevel();
    
    if (occupierE->getStatus() == "owned") {
        cout << "&";
    } else if (element == "fire"){
        if (level < level_min){
            cout << "f";
        } else {
            cout << "F";
        }
    } else if (element == "ground"){
        if (level < level_min) {
            cout << "g";
        } else {
            cout << "G";
        }

    } else if (element == "electric"){
        if (level < level_min){
            cout << "e";
        } else {
            cout << "E";
        }
    } else if (element == "water") {
        if (level < level_min){
            cout << "w";
        } else {
            cout << "W";
        }
    } else {
        if (level < level_min){
            cout << "i";
        } else {
            cout << "I";
        }
    }

}

void Cell::printInfo() {
    cout << "x      : " << x << endl;
    cout << "y      : " << y << endl;
    cout << "type   : " << type << endl;
}

Player& Cell::getOccupierP(){
    return this->occupierP;
}