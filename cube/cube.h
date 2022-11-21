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
                window.drawRect(&blue, rect, 3, 3);

                nextRect();
            }

            drawArrow(cubeSize);
        }


    private:
        const int numArrowPoints = 5;
        int fontSize = 50;
        SDL_Point upArrow[5];
        SDL_Point downArrow[5];
        SDL_Point leftArrow[5];
        SDL_Point rightArrow[5];
        SDL_Point point;

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

        // Draw arrow on the cube
        void drawArrow(int cubeSize) {
            rect = {0, blockLength, blockLength, blockLength};
            rect.makeDimensions();

            auto x2Texture = window.loadText("Fonts/times.ttf", "X2", fontSize);
            x2Texture.changeColor(&violet);

            for (int i = 0; i < text.length(); ++i) {
                if (i == text.find("U'", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = point.y + (blockLength/cubeSize)/2;
                    drawRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    ++i;
                }
                else if (i == text.find("u'", i)) {
                    
                }
                else if (i == text.find("U2", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + (blockLength/cubeSize)/2;
                    point.y = point.y + (blockLength/cubeSize)/2;
                    drawLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                    x2Texture.createTexture(window.renderer);
                    x2Texture.render(window.renderer);
                }
                else if (i == text.find("U", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + (blockLength/cubeSize)/2;
                    point.y = point.y + (blockLength/cubeSize)/2;
                    drawLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("u", i)) {

                }

                else if (i == text.find("D'", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + (blockLength/cubeSize)/2;
                    point.y = point.y + blockLength - (blockLength/cubeSize)/2;
                    drawLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                    ++i;
                }
                else if (i == text.find("d'", i)) {
                }
                else if (i == text.find("D2", i)) {
                }
                else if (i == text.find("D", i)) { 
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = point.y + blockLength - (blockLength/cubeSize)/2;
                    drawRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("d", i)) {
                }

                else if (i == text.find("L'", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + (blockLength/cubeSize)/2;
                    point.y = point.y + (blockLength/cubeSize)/2;
                    drawUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    ++i;
                }
                else if (i == text.find("l'", i)) {
                }
                else if (i == text.find("L2", i)) {
                }
                else if (i == text.find("L", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + (blockLength/cubeSize)/2;
                    point.y = point.y + blockLength - (blockLength/cubeSize)/2;
                    drawDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("l", i)) {
                }

                else if (i == text.find("R'", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = point.y + blockLength - (blockLength/cubeSize)/2;
                    drawDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    ++i;
                }
                else if (i == text.find("r'", i)) {
                }
                else if (i == text.find("R2", i)) {
                }
                else if (i == text.find("R", i)) {
                    point.x = rect.x;
                    point.y = rect.y;
                    point.x = point.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = point.y + (blockLength/cubeSize)/2;
                    drawUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
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

        void drawUpArrow(SDL_Point upArrowPoint, int cubeSize) {
            upArrow[0].x = upArrowPoint.x;
            upArrow[0].y = upArrowPoint.y + blockLength - blockLength/(cubeSize);

            upArrow[1].x = upArrowPoint.x;
            upArrow[1].y = upArrowPoint.y;

            upArrow[2].x = upArrowPoint.x - 10;
            upArrow[2].y = upArrowPoint.y + 10;

            upArrow[3].x = upArrowPoint.x;
            upArrow[3].y = upArrowPoint.y;

            upArrow[4].x = upArrowPoint.x + 10;
            upArrow[4].y = upArrowPoint.y + 10;
        }

        void drawDownArrow(SDL_Point downArrowPoint, int cubeSize) {
            downArrow[0].x = downArrowPoint.x;
            downArrow[0].y = downArrowPoint.y - blockLength + blockLength/(cubeSize);

            downArrow[1].x = downArrowPoint.x;
            downArrow[1].y = downArrowPoint.y;

            downArrow[2].x = downArrowPoint.x - 10;
            downArrow[2].y = downArrowPoint.y - 10;

            downArrow[3].x = downArrowPoint.x;
            downArrow[3].y = downArrowPoint.y;

            downArrow[4].x = downArrowPoint.x + 10;
            downArrow[4].y = downArrowPoint.y - 10;
        }

        void drawLeftArrow(SDL_Point leftArrowPoint, int cubeSize) {
            leftArrow[0].x = leftArrowPoint.x + blockLength - blockLength/cubeSize;
            leftArrow[0].y = leftArrowPoint.y;

            leftArrow[1].x = leftArrowPoint.x;
            leftArrow[1].y = leftArrowPoint.y;

            leftArrow[2].x = leftArrowPoint.x + 10;
            leftArrow[2].y = leftArrowPoint.y - 10;

            leftArrow[3].x = leftArrowPoint.x;
            leftArrow[3].y = leftArrowPoint.y;

            leftArrow[4].x = leftArrowPoint.x + 10;
            leftArrow[4].y = leftArrowPoint.y + 10;
        }

        void drawRightArrow(SDL_Point rightArrowPoint, int cubeSize) {
            rightArrow[0].x = rightArrowPoint.x - blockLength + blockLength/cubeSize;
            rightArrow[0].y = rightArrowPoint.y;

            rightArrow[1].x = rightArrowPoint.x;
            rightArrow[1].y = rightArrowPoint.y;

            rightArrow[2].x = rightArrowPoint.x - 10;
            rightArrow[2].y = rightArrowPoint.y - 10;

            rightArrow[3].x = rightArrowPoint.x;
            rightArrow[3].y = rightArrowPoint.y;

            rightArrow[4].x = rightArrowPoint.x - 10;
            rightArrow[4].y = rightArrowPoint.y + 10;
        }

};

#endif
