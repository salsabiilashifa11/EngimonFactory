#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <string>
#include <iostream>
#include <vector>
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
                container[i].display();
            }
        }
        int n_elmt() const{
            return container.size();
        }
        T findByName(string name) {

        }

    private:
        vector<T> container;
};

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