#include "Map.hpp"
#include "Cell.hpp"
#include "Player.hpp"
#include "WildEngimon.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    //Inisialisasi
    cout<<"Selamat datang di Engimon Factory"<<endl<<endl;
    string PlayerName;
    cout<<"Masukkan nama player : ";
    cin>>PlayerName;
    Player p(PlayerName);
    Map m("map.txt", p);
    int JumlahEngimon, JumlahEngimonAir, JumlahEngimonGrassland1, JumlahEngimonGrassland2, posisiX, posisiY, lvl, element;
    cout<<"Masukkan jumlah engimon : ";
    cin>>JumlahEngimon;
    WildEngimon *Engimon = new WildEngimon[JumlahEngimon]; 
    JumlahEngimonAir = JumlahEngimon/4;
    JumlahEngimonGrassland1 = JumlahEngimonAir;
    JumlahEngimonGrassland2 = JumlahEngimon - JumlahEngimonAir - JumlahEngimonGrassland1;
    int j = 0;
    srand (time(0));
    m.updatePlayer(); //Moved here

    //Inisialisasi Engimon di air
    for (int i = 0; i < JumlahEngimonAir; i++){
        // 0<x=10 20<y<=30
        posisiX = (rand() % 10);
        posisiY = (rand() % 10) + 20;
        lvl = (rand() % 69);
        element = (rand() % 2);
        switch (element){
            case 0:
                Engimon[j] = WildEngimon("kadal", "ice", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            case 1:
                Engimon[j] = WildEngimon("kambing", "water", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
        }
        j++; 
    }

    // Inisialisasi Engimon di Grassland yang bagian atas
    for (int i = 0; i < JumlahEngimonGrassland1; i++){
        posisiX = (rand() % 9) + 1;
        posisiY = (rand() % 20);
        lvl = (rand() % 69);
        element = (rand() % 3);
        switch (element){
            case 0:
                Engimon[j] = WildEngimon("ikan", "fire", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            case 1:
                Engimon[j] = WildEngimon("kelelawar", "ground", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            case 2:
                Engimon[j] = WildEngimon("beruang", "electric", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            default:
                break;
        }
        j++;
    }

    // Inisialisasi Engimon di Grassland yang
    for (int i = 0; i < JumlahEngimonGrassland2; i++){
        posisiX = (rand() % 20) +10;
        posisiY = (rand() % 30);
        lvl = (rand() % 69);
        element = (rand() % 3);
        switch (element){
            case 0:
                Engimon[j] = WildEngimon("ikan", "fire", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            case 1:
                Engimon[j] = WildEngimon("kelelawar", "ground", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            case 2:
                Engimon[j] = WildEngimon("beruang", "electric", lvl, posisiX, posisiY, &m);
                m.getCell(posisiX, posisiY).setEngimon(&Engimon[j]);
                break;
            default:
                break;
        }
        j++;
    }
    m.drawMap();
    m.getCell(0,0).printInfo();

    try{
        string command;
        while (true) {
            cin >> command;
            //cout << endl;  
            if (command == "w"){
                m.getPlayer().Move('w');
                m.updatePlayer();
            }
            else if (command == "a"){
                m.getPlayer().Move('a');
                m.updatePlayer();
            }
            else if (command == "s"){
                m.getPlayer().Move('s');  
                m.updatePlayer();  
            }
            else if (command  == "d"){
                m.getPlayer().Move('d');
                cout << "posisi owned x : " << m.getPlayer().getActiveEngimon().getPosition().getX() << endl;
                cout << "posisi owned y : " << m.getPlayer().getActiveEngimon().getPosition().getY() << endl;
                m.updatePlayer();
            }else if (command == "q"){
                // exit(0);
                break;
            }else if (command == "display"){
                p.showInventory();
            }
            else if (command == "battle"){
                if (m.getEnemy().getOccupierP().getName() != ""){
                    cout << "Tidak ada musuh di sekitar player" << endl; 
                }
                else{
                    p.Battle(*(m.getEnemy().getOccupierE()));
                }
            }
            else if (command == "breed"){
                cout<<"LOM JADI JING"<<endl;
            }
            else{
                cout<<"Invalid Command"<<endl;
                // exit(0);
            }
            for (int i = 0; i < JumlahEngimon; i++) {
                // Engimon[i].Move(&m);
                Engimon[i].assertPosition(&m); //haruss sebelom drawMap OK
                // cout << Engimon[i].getName() << endl;
            }
            m.drawMap();
            m.getPlayer().getPosition().print();   
            cout << JumlahEngimon << endl;
        }
    }
    
    catch (const char* c) {
        cout << "Exception: " << c << endl;
        // exit(0);
    }

    return 0;
}