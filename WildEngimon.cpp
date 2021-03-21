#include "WildEngimon.hpp"

int WildEngimon::element2int(string element) {
    if (element == "Fire" || element == "Ground" || element == "Electric") {
        return 1;
    } else {
        return 2;
    }
}

WildEngimon::WildEngimon() : Engimon() {
    this->status = "wild";
    // this->position = //random;
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

Position WildEngimon::getPosition(){
    return this->position;
}

void WildEngimon::setPosition(int x, int y, Map m){
    //get elemen
    //, CellType Wtype
    int number;
    srand (time(NULL));
    number = rand() % 4 + 1;
    
    if (number == 1){
        if (validPosition(m, x, y+1)){
            position.setY(y+1);
        }    
    } else if (number == 2){
        if (validPosition(m, x, y-1)){
            position.setY(y-1);
        }
    } else if (number == 3){
        if (validPosition(m, x-1, y)){
            position.setX(x-1);
        }
    } else {
        if (validPosition(m, x, y+1)){
            position.setX(y+1);
        }
    }

}

bool WildEngimon::validPosition(Map m, int x, int y) {
    CellType Wtype;
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
        WType != m[x][y].getType()) {
            throw "Posisi tidak valid";
        } 
    return true;


    
    // Position(this->x,this->y);
    
    /*position.gettype()
    if (ctype.getType() != Wtype){
        return false;
    } else {
        return true;
    }*/
    
    //ctype.getType().getX();
}