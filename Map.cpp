#include "Map.hpp"

Map::Map() {
    filename = "game.txt";
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            Cell cell(i, j, Sea);
            map[i][j] = cell;
        }
    }
}

Map::Map(string _filename) {
    filename = _filename;
    string line_input;
    int i = 0;

    fstream file(filename);
    if (!file) {
        throw "File not found!";
    }

    cout << "got here\n";
    
    while (file && i < MAP_HEIGHT - 1) {
        getline(file, line_input);
        if (line_input.size() > MAP_WIDTH) {
            throw "Board size invalid";
        }
        for (size_t j = 0; j < line_input.size(); j++) {
            CellType type = getType(line_input[j]);
            Cell cell(i, j, type);
            map[i][j] = cell;
        }
        i++;
    }
}

Map::~Map() {
    //do nothing
}

//Getter
Cell Map::getCell(int x, int y) {
    return map[x][y];
}

//Methods
void Map::drawMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j].drawCell();
            cout << " ";
        }
        cout << endl;
    }
}


CellType Map::getType(char c) {
    CellType type;
    switch (c) {
        case '-':
        case 'F':
        case 'f':
        case 'G':
        case 'g':
        case 'E':
        case 'e':
        case 'L':
        case 'l':
        case 'N':
        case 'n':
            type = Grassland;
            break;
        case 'o':
        case 'W':
        case 'w':
        case 'I':
        case 'i':
        case 'S':
        case 's':
            type = Sea;
        default:
            break;
    }
    return type;
}

// Engimon Map::getOccupierE(char c);