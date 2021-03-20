#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <string>
#include <iostream>
#include <vector>
#include "SkillItems.hpp"
using namespace std;

template <class T>
class Inventory {
    public:
        T operator[](int i){
            return container.at(i);   
        }
        T deleteAt(int i){
            T temp = container.at(i);
            container.erase(container.begin()+i);
            return temp;
        }
        void append(T el){
            container.push_back(el);
        }
        void displayAll() const{
            for (int i = 0; i < container.size(); i++) {
                cout << i+1 << ". " << container[i].getName();
            }
        }
        int n_elmt() const{
            return container.size();
        }
        int indexByName(string name) {
            for (int i = 0; i < container.size(); i++) {
                if (container[i].getName().compare(name) == 0) {
                    return i;
                }
            }

            return -1;
        }

    private:
        vector<T> container;
};

template<>
int Inventory<SkillItems>::n_elmt() const{
    int sum = 0;
    for (int i = 0; i < container.size(); i++) {
        sum += container.at(i).getQuantity();
    }

    return sum;
}

template<>
void Inventory<SkillItems>::append(SkillItems el) {
    int idx = indexByName(el.getName());
    if (idx != -1) {
        container[idx].addQuantity(1);
    }
    else {
        container.push_back(el);
    }
}
// template<class T> 
// T Inventory<T>::operator[](int i) {
//     return container.at(i);
//     }

// template<class T> 
// T Inventory<T>::deleteAt(int i) {
//     T temp = container.at(i);
//     container.erase(container.begin()+i-1);

//     return temp;
//     }

// template<class T> 
// void Inventory<T>::append(T el) {
//     container.push_back(el);
//     }

// template<class T> 
// void Inventory<T>::displayAll() const {
//     for (int i = 0; i < container.size(); i++) {
//         container[i].display();
//     }
// }

// template<class T>
// void n_elmt() const {
//     return container.size();
// }


#endif