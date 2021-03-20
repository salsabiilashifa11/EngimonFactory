#include "OwnedEngimon.hpp"

int main(){
    OwnedEngimon pikachu("pikachu","lightning");
    pikachu.setParentName("joko","mawar");
    pikachu.interact();
    Skill s1("azab petir",100,0);
    Skill s2("azab halilintar",200,0);
    s1.addElement("lightning");
    s2.addElement("lightning");
    pikachu.addElements("lighning");
    pikachu.addSkill(s1);
    pikachu.addSkill(s2);
    pikachu.displayDetail();
    return 0;
}