#include "Map.hpp"
#include "Cell.hpp"
#include "Player.hpp"

int main() {

    try {
        Player p("danan");

        Map m("map.txt", p);
        m.updateMap();
        m.drawMap();
        m.getCell(0,0).printInfo();
    } catch (const char* c) {
        cout << "Exception: " << c << endl;
    }
    

    return 0;
}