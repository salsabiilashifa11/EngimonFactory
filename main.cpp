#include "Map.hpp"
#include "Cell.hpp"
#include "Player.hpp"
#include "WildEngimon.hpp"
// #include "Engimon.hpp"
// #include "OwnedEngimon.hpp"
// #include "SkillItems.hpp"
// #include "Skill.hpp"
// #include "Inventory.hpp"
// #include "Position.hpp"

int main() {
    
    try {
        
        Player p("danan");

        Map m("map.txt", p);
        m.updateMap();
        m.drawMap();
        m.getCell(0,0).printInfo();
        
        //Game loop
        OwnedEngimon pikachu("pikachu","beruang");
        pikachu.addElements("electric");
        Skill skill1("libasan ekor keadilan",100,0);
        Skill skill2("seruputan kopi maut",100,0);
        Skill skill3("tembakan gelembung kebebasan", 110, 1);
        Skill skill4("teori maksiat habis ibadah", 110, 1);
        skill1.addElement("electric");
        skill2.addElement("electric");
        skill3.addElement("fire");
        skill4.addElement("fire");
        // Skill skill5("EVOS ROAR", 110, 1);
        pikachu.addSkill(skill1);
        pikachu.addSkill(skill2);
        pikachu.setLevel(150);
        OwnedEngimon charizard("charizard","ikan");
        charizard.addElements("fire");
        charizard.addSkill(skill3);
        charizard.addSkill(skill4);
        charizard.setLevel(150);
        charizard.displayDetail();
        pikachu.displayDetail();

        //WildEngimon Spawning DEBUGGGG
        WildEngimon wildengimon("kambing", "water", 20, 9, 28, &m);
        // wildengimon.setPosition(5, 28, &m);
        // wildengimon.Move();
        cout << "Ini harusnya kambing: " << wildengimon.getName() << endl;
        cout << "Ini harusnya kambing: " << wildengimon.getLevel() << endl;
        cout << m.getCell(5, 28).getOccupierE()->getName() << endl;
        cout << m.getCell(5, 28).getOccupierE()->getSpecies() << endl;
        cout << m.getCell(28, 5).getOccupierE()->getName() << endl;
        cout << m.getCell(28, 5).getOccupierE()->getSpecies() << endl;
        cout << m.getCell(5, 20).getOccupierE()->getName() << endl;
        
        char command; //Masih char, nanti harus jadiin string dan make strComp
        while (true) {
            cin >> command;
            //cout << endl;
            
            switch (command) {
                case 'w':
                    m.getPlayer().Move('w');
                    wildengimon.Move(&m);
                    break;
                case 'a':
                    m.getPlayer().Move('a');
                    wildengimon.Move(&m);
                    break;
                case 's':
                    m.getPlayer().Move('s');
                    wildengimon.Move(&m);
                    break;
                case 'd':
                    m.getPlayer().Move('d');
                    wildengimon.Move(&m);
                    break;
                case 'b':
                    // breed
                    p.Breed(charizard, pikachu);
                case 'q':
                    break;
                default:
                    break;
            }
            if (command == 'q') {
                break;
            }
            m.updateMap();
            m.drawMap();
            m.getPlayer().getPosition().print();
        }
    } 

    catch (const char* c) {
        cout << "Exception: " << c << endl;
    }

    return 0;
}