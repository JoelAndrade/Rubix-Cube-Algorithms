#include <iostream>
#include "NxN.h"

class cube {
    public:
        xx2 Xx2;
        x3 Xx3;
        x4 Xx4;
        x5 Xx5;
        x6 Xx6;
        x7 Xx7;

        std::string text;

        cube() {}
        cube(std::string textVal) {
            text = textVal;
        }

        void fixString(int cubeSize) {
            if (cubeSize == 2) {
                
            }
            if (cubeSize == 3) {
                text = Xx3.fixString(text);
            }
            if (cubeSize == 4) {
                
            }            
        }

    private:
    
};
