#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <string>
#include "NxN.h"
#include "../main.h"

class cube {
    public:
        xx2 Xx2;
        x3 Xx3;
        x4 Xx4;
        x5 Xx5;
        x6 Xx6;
        x7 Xx7;

        SDL_Rect rect;
        std::string text;

        cube() {
        }
        cube(std::string textVal) {
            text = textVal;
        }

        // Fixes the string for the given cube size
        void fixString(std::string newText, int cubeSize) {
            text = newText;
            if (cubeSize == 2) {
                
            }
            if (cubeSize == 3) {
                for (int i = 0; i < text.length(); ++i) {
                    if (!(text[i] == 'U' || text[i] == 'u' 
                    || text[i] == 'D' || text[i] == 'd' 
                    || text[i] == 'L' || text[i] == 'l' 
                    || text[i] == 'R' || text[i] == 'r' 
                    || text[i] == 'F' || text[i] == 'f' 
                    || text[i] == 'B' || text[i] == 'b' 
                    || text[i] == 'x' || text[i] == 'y' || text[i] == 'z' 
                    || text[i] == 'M' || text[i] == 'E' || text[i] == 'S' 
                    || text[i] == '\'' || text[i] == '2'))
                    {
                        text.erase(i, 1);
                        --i;
                    }
                }
            }
            if (cubeSize == 4) {
                
            }            
        }

        // Fills the square and and adds the lines
        void drawCube(int cubeSize) {
            rect = {0, blockLength, blockLength, blockLength};
            rect.makeDimensions();

            int numMoves = text.length();
            for (int i = 0; i < text.length(); ++i) {
                if (text[i] == '\'' || text[i] == '2') {
                    --numMoves;
                }
            }

            for (int i = 0; i < numMoves; ++i) {
                window.fillRect(&green, rect);
                for (int i = 1; i < cubeSize; ++i) {
                    window.drawLine(rect.x + (blockLength*i)/cubeSize, rect.y, rect.x + (blockLength*i)/cubeSize, rect.bottomY, &black, 3, 1);
                    window.drawLine(rect.x, rect.y + (blockLength*i)/cubeSize, rect.rightX, rect.y + (blockLength*i)/cubeSize, &black, 1, 3);
                }
                window.drawRect(&violet, rect, 3, 3);

                nextRect();
            }

            drawArrow(cubeSize);
        }

        // Draw arrow on the cube
        void drawArrow(int cubeSize) {

            rect = {0, blockLength, blockLength, blockLength};
            rect.makeDimensions();
            for (int i = 0; i < text.length(); ++i) {
                if (i == text.find("U'", i)) {
                    
                }
                else if (i == text.find("u'", i)) {
                    
                }
                else if (i == text.find("U2", i)) {
                    
                }
                else if (i == text.find("U", i)) {
                    window.drawLine(rect.x, rect.y + blockLength/(cubeSize*2), rect.rightX, rect.y + blockLength/(cubeSize*2), &black, 1, 3);
                }
                else if (i == text.find("u", i)) {

                }

                else if (i == text.find("D'", i)) {
                }
                else if (i == text.find("d'", i)) {
                }
                else if (i == text.find("D2", i)) {
                }
                else if (i == text.find("D", i)) {
                }
                else if (i == text.find("d", i)) {
                }

                else if (i == text.find("L'", i)) {
                }
                else if (i == text.find("l'", i)) {
                }
                else if (i == text.find("L2", i)) {
                }
                else if (i == text.find("L", i)) {
                    window.drawLine(rect.x + blockLength/(cubeSize*2), rect.y, rect.x + blockLength/(cubeSize*2), rect.bottomY, &black, 3, 1);
                }
                else if (i == text.find("l", i)) {
                }

                else if (i == text.find("R'", i)) {
                }
                else if (i == text.find("r'", i)) {
                }
                else if (i == text.find("R2", i)) {
                }
                else if (i == text.find("R", i)) {
                }
                else if (i == text.find("r", i)) {
                }
                
                else if (i == text.find("F'", i)) {
                }
                else if (i == text.find("f'", i)) {
                }
                else if (i == text.find("F2", i)) {
                }
                else if (i == text.find("F", i)) {
                }
                else if (i == text.find("f", i)) {
                }
                
                else if (i == text.find("B'", i)) {
                }
                else if (i == text.find("b'", i)) {
                }
                else if (i == text.find("B2", i)) {
                }
                else if (i == text.find("B", i)) {
                }
                else if (i == text.find("b", i)) {
                }
                
                else if (i == text.find("x'", i)) {
                }
                else if (i == text.find("x2", i)) {
                }
                else if (i == text.find("x", i)) {
                }
                
                else if (i == text.find("y'", i)) {
                }
                else if (i == text.find("y2", i)) {
                }
                else if (i == text.find("y", i)) {
                }
                
                else if (i == text.find("z'", i)) {
                }
                else if (i == text.find("z2", i)) {
                }
                else if (i == text.find("z", i)) {
                }
                
                nextRect();
            }
        }

        // Set up the next rect to be drawn
        void nextRect() {
            if (rect.rightX != windowWidth) {
                rect.x = rect.x + blockLength;
                rect.makeDimensions();  
            }
            else {
                rect.x = 0;
                rect.y = rect.y + blockLength;
                rect.makeDimensions();
            }        
        }

    private:
    
};

#endif
