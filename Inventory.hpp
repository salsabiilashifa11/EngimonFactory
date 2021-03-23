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
        void displayAll() {
            if (n_elmt() == 0) {
                cout << "Inventory kosong" << endl;
                return;
            }
            for (int i = 0; i < container.size(); i++) {
                cout << i+1 << ". " << container[i].getName() << endl;
            }
        }
        int n_elmt() const{
            return container.size();
        }
        int indexByName(string name) {
            for (int i = 0; i < container.size(); i++) {
                if (container[i].getName() == name) {
                    return i;
                }
            }

            return -1;
        }

    private:
        vector<T> container;
};

template<>
inline int Inventory<SkillItems>::n_elmt() const{
    int sum = 0;
    for (int i = 0; i < container.size(); i++) {
        sum += container.at(i).getQuantity();
    }

    return sum;
}

template<>
inline void Inventory<SkillItems>::append(SkillItems el) {
    int idx = indexByName(el.getName());
    if (idx != -1) {
        container[idx].addQuantity(1);
    }
    else {
        container.push_back(el);
    }
}

template<>
inline void Inventory<SkillItems>::displayAll() {
    if (n_elmt() == 0) {
        cout << "Inventory kosong" << endl;
        return;
    }
    for (int i = 0; i < container.size(); i++) {
        cout << i+1 << ". " << container[i].getName() << " (qty: " <<
            container[i].getQuantity() << ")" << endl;
    }
}

template<>
inline SkillItems Inventory<SkillItems>::deleteAt(int i){
    SkillItems temp = container.at(i);
    if (temp.getQuantity() == 1) {
        container.erase(container.begin()+i);
    }
    else {
        container[i].addQuantity(-1);
    }
    return temp;
}


#endif
                