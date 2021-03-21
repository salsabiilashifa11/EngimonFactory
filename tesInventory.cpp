#include <iostream>
#include "Skill.hpp"
#include "SkillItems.hpp"
#include "Inventory.hpp"
#include "OwnedEngimon.hpp"

// g++ -std=c++11 tesInventory.cpp Engimon.cpp OwnedEngimon.cpp Position.cpp Skill.cpp SkillItems.cpp -o tesInv

int main() {
    Skill a("a", 1, 3);
    cout << a.getSkillName() << " ";
    cout << a.getBasePower() << " ";
    cout << a.getMasteryLevel() << endl;

    SkillItems b(a, 1);
    cout << b.getName() << " " << b.getQuantity() << endl;
    // b.addQuantity(10);
    cout << b.getName() << " " << b.getQuantity() << endl;

    Inventory<SkillItems> inva;
    inva.append(b);
    inva.displayAll();
    inva.append(b);
    inva.displayAll();
    cout << inva.indexByName("a") << endl;
    cout << inva.n_elmt();
    inva.deleteAt(0);
    inva.displayAll();
    while (inva.n_elmt() > 0) {
        inva.deleteAt(0);
        inva.displayAll();
    }
    inva.displayAll();
    
    SkillItems c;

    inva.append(b);
    inva.append(c);
    
    inva.displayAll();
    inva.deleteAt(0);

    inva.displayAll();

    cout << "----test inv OwnedEngimon---" << endl;
    Inventory<OwnedEngimon> invb;
    OwnedEngimon oe;
    OwnedEngimon oe1("joni", "orang");
    OwnedEngimon oe2("jono", "urang");
    invb.append(oe1);
    invb.append(oe);
    invb.append(oe2);
    oe1.setName("joni luar");
    oe.setName("XXX luar");
    invb.displayAll();
    cout << "delete test" << endl;
    invb.deleteAt(1);
    invb.displayAll();
    cout << "eop" << endl;

    return 0;
}