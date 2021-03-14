#include "Cell.hpp"

Cell::Cell() {
    x = -1;
    y = -1;
    type = Grassland;
}

Cell::Cell(int _x, int _y, CellType _type) {
    x = _x;
    y = _y;
    type = _type;
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

//Method
void Cell::drawCell() {
    // if (occupierE == NULL && occupierP == NULL) {
    if (type == Sea) {
        cout << "o";
    } else {
        cout << "-";
    }
    // }
}

void Cell::printInfo() {
    cout << "x      : " << x << endl;
    cout << "y      : " << y << endl;
    cout << "type   : " << type << endl;
}