#include "Cell.hpp"
#include "WildEngimon.hpp"

Cell::Cell() {
    x = -1;
    y = -1;
    type = Grassland;
    // WildEngimon temp;
    // Player temp;
    // occupierP = temp;
    occupierE = new WildEngimon();
}

Cell::Cell(int _x, int _y, CellType _type) {
    x = _x;
    y = _y;
    type = _type;
    // WildEngimon temp;
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

//Getter
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
    //Check for player and engimon occupiers
    if (occupierP.getName() == "" && occupierE->getName() == "XXX") {
        if (type == Sea) {
            cout << "o";
        } else {
            cout << "-";
        }
    } else if (occupierP.getName() != "") {
        cout << "P";
    } else {
        drawEngimon(10);
    }

}

void Cell::drawEngimon(int level_min) {
    //Check for playe occupiers
    // int engimonType, rand1;
    // srand (time(NULL));
    // engimonType = rand() % 8 + 1;
    // rand1 = rand() % (input-1) + 1;

    string element = occupierE->getElements()[0];
    int level = occupierE->getLevel();
    
    if (element == "fire"){
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