#include "Map.hpp"
#include "Cell.hpp"

int main() {

    try {
        Map m("map.txt");
        m.drawMap();
        m.getCell(0,0).printInfo();
    } catch (const char* c) {
        cout << "Exception: " << c << endl;
    }
    

    return 0;
}