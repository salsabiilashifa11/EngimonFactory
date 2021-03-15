#include "OwnedEngimon.hpp"

OwnedEngimon::OwnedEngimon(string name, string species) : Engimon() {
    this->name = name;
    this->species = species; 
    this->satus = "owned";
}
OwnedEngimon::~OwnedEngimon(){
    delete[] parentName;
}

string* OwnedEngimon::getParentName(){
    return this->parentName;
}

void OwnedEngimon::setParentName(string parentName1, string parentName2)  {
    this->parentName[0] = parentName1;
    this->parentName[1] = parentName2;
}

string OwnedEngimon::getStatus(){
    return this->status;    
}

void OwnedEngimon::setStatus(string s){
    this->status = s;
}

Cell OwnedEngimon::getPosition(){
    return this->position;
}

void OwnedEngimon::interact(){
    //kirim pesan sama player
    //pesan unik per spesies
}

void OwnedEngimon::moveActive(int x, int y){
    this->position.x = x;
    this->position.y = y;
}