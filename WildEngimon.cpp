#include "WildEngimon.hpp"

WildEngimon::WildEngimon() : Engimon() {
    this->status = "wild";
    this->position = //random;
}
WildEngimon::~WildEngimon(){
    //destruct
}


string WildEngimon::getStatus(){
    return this-> status;
}
void WildEngimon::setStatus(string newstat){
    this->status = newstat;
}

Cell WildEngimon::getPosition(){
    return this->position;
}

void WildEngimon::setPosition(int x, int y){
    //get elemen
    //, CellType Wtype
    int number;
    srand (time(NULL));
    number = rand() % 4 + 1;
    
    if (number == 1){
        this->y += 1;
        //up
    } else if (number == 2){
        this->y -= 1;
        //down
    } else if (number == 3){
        this->x -= 1;
        //left
    } else {
        this->x += 1;
        //right
    }

}

bool WildEngimon::validPosition(int x, int y){
    CellType Wtype;
    switch(Engimon.getElements()){
        case 'Fire';
        case 'Ground';
        case 'Electric';
            Wtype = Grassland;
            break;
        case 'Water';
        case 'Ice';
            Wtype = Sea;
            break;
        default:
            break;
    
    Position(this->x,this->y);
    
    /*position.gettype()
    if (ctype.getType() != Wtype){
        return false;
    } else {
        return true;
    }*/
    
    //ctype.getType().getX();
}