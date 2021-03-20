#include <iostream>

using namespace std;

class ElementAdvantage {
    public:
        static float getAdv(string el1, string el2) {
            if (el1 == "fire") {
                if (el2 == "fire") {
                    return 1;
                }
                else if (el2 == "water") {
                    return 0;
                }
                else if (el2 == "electric") {
                    return 1;
                }
                else if (el2 == "ground") {
                    return 0.5;
                }
                else if (el2 == "ice") {
                    return 2;
                }
            }
            else if (el1 == "water") {
                if (el2 == "fire") {
                    return 2;
                }
                else if (el2 == "water") {
                    return 1;
                }
                else if (el2 == "electric") {
                    return 0;
                }
                else if (el2 == "ground") {
                    return 1;
                }
                else if (el2 == "ice") {
                    return 1;
                }
            }
            else if (el1 == "electric") {
                if (el2 == "fire") {
                    return 1;
                }
                else if (el2 == "water") {
                    return 2;
                }
                else if (el2 == "electric") {
                    return 1;
                }
                else if (el2 == "ground") {
                    return 0;
                }
                else if (el2 == "ice") {
                    return 1.5;
                }
            }
            else if (el1 == "ground") {
                if (el2 == "fire") {
                    return 1.5;
                }
                else if (el2 == "water") {
                    return 1;
                }
                else if (el2 == "electric") {
                    return 2;
                }
                else if (el2 == "ground") {
                    return 1;
                }
                else if (el2 == "ice") {
                    return 0;
                }
            }
            else if (el1 == "ice") {
                if (el2 == "fire") {
                    return 0;
                }
                else if (el2 == "water") {
                    return 1;
                }
                else if (el2 == "electric") {
                    return 0.5;
                }
                else if (el2 == "ground") {
                    return 2;
                }
                else if (el2 == "ice") {
                    return 1;
                }
            }
        }

};