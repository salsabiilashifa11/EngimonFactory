#include <iostream>
#include "Skill.hpp"
#include "SkillItems.hpp"
#include "Inventory.hpp"

// g++ tesInventory.cpp Skill.cpp SkillItems.cpp -o tesInv

int main() {
    Skill a("a", 1, 3);
    cout << a.getSkillName() << " ";
    cout << a.getBasePower() << " ";
    cout << a.getMasteryLevel() << endl;

    SkillItems b(a, 1);
    cout << b.getName() << " " << b.getQuantity() << endl;
    b.addQuantity(10);
    cout << b.getName() << " " << b.getQuantity() << endl;

    Inventory<SkillItems> inva;
    inva.append(b);
    inva.displayAll();
    inva.append(b);
    inva.displayAll();

    cout << inva.indexByName("a") << endl;
    cout << inva.n_elmt() << endl;

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
    inva.append(c);
    inva.append(c);

    inva.displayAll();
    cout << inva.n_elmt() << endl;

    return 0;
}