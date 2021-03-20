#include "Position.hpp"

Position::Position() {
    x = -1;
    y = -1;
}

Position::Position(int _x, int _y) {
    x = _x;
    y = _y;
}

Position::~Position() {
    //do nothing
}

// Operator Overloading
Position& Position::operator=(const Position& other){
    x = other.x;
    y = other.y;

    return *this;
}

//Getter
int Position::getX() {
    return x;
}

int Position::getY() {
    return y;
}

//Setter
void Position::setX(int _x) {
    x = _x;
}

void Position::setY(int _y) {
    y = _y;
}

//Methods
void Position::print() {
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
}
