#include "OwnedEngimon.hpp"

int main(){
    OwnedEngimon pikachu("pikachu","kadal");
    pikachu.setParentName("joko","mawar");
    pikachu.interact();
    Skill s1("azab petir",100,2);
    Skill s2("azab halilintar",200,1);
    Skill s3("azab jduar",200,3);
    s1.addElement("lightning");
    s2.addElement("lightning");
    pikachu.addElements("lightning");
    pikachu.addSkill(s1);
    pikachu.addSkill(s2);
    pikachu.addSkill(s3);
    pikachu.displayDetail();
    return 0;
}