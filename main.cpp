#include "Map.hpp"
#include "Cell.hpp"
#include "Player.hpp"
#include "Engimon.hpp"
#include "OwnedEngimon.hpp"
#include "SkillItems.hpp"
#include "Skill.hpp"
#include "Inventory.hpp"
#include "Position.hpp"

int main() {
    
    // try {
        Player p("danan");

        Map m("map.txt", p);
        m.updateMap();
        m.drawMap();
        m.getCell(0,0).printInfo();

        //Game loop
        char command; //Masih char, nanti harus jadiin string dan make strComp
        while (true) {
            cin >> command;
            //cout << endl;
            switch (command) {
                case 'w':
                    m.getPlayer().Move('w');
                    break;
                case 'a':
                    m.getPlayer().Move('a');
                    break;
                case 's':
                    m.getPlayer().Move('s');
                    break;
                case 'd':
                    m.getPlayer().Move('d');
                    break;
                case 'q':
                    break;
                default:
                    break;
            }
            //cout<<"Hai"<<endl;
            m.updateMap();
            m.drawMap();
            m.getPlayer().getPosition().print();
            if (command == 'q') {
                break;
            }
            
            
        }
        cout << "Ini ujung";

    // } 
    // catch (const char* c) {
    //     cout << "Exception: " << c << endl;
    // }

    return 0;
}