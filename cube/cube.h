#ifndef CUBE_H
#define CUBE_H

// #include "NxN.h"

#include "../main.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#define CLOCKWISE (1)
#define COUNTER_CLOCKWISE (-1)

#define font "Fonts/Agane 55 (roman).ttf"

class cube {
    public:
        SDL_Rect rect;
        std::string text;
        textureText x2Texture;
        textureText backTexture;
        textureText b2Texture;
        textureText sliceTexture;
        textureText s2Texture;

        cube() {}
        cube(std::string text) {
            this->text = text;
        }

        void init(std::string text) {
            this->text = text;
            x2Texture.init(window.renderer,    "Fonts/Agane 55 (roman).ttf", "x2", fontSize - 10);
            backTexture.init(window.renderer,  "Fonts/Agane 55 (roman).ttf", "B",  fontSize);
            b2Texture.init(window.renderer,    "Fonts/Agane 55 (roman).ttf", "B2", fontSize - 10);
            sliceTexture.init(window.renderer, "Fonts/Agane 55 (roman).ttf", "S",  fontSize);
            s2Texture.init(window.renderer,    "Fonts/Agane 55 (roman).ttf", "S2", fontSize - 10);

            x2Texture.changeColor(&white);
            backTexture.changeColor(&white);
            b2Texture.changeColor(&white);
            sliceTexture.changeColor(&white);
            s2Texture.changeColor(&white);
            
        }

        // Fixes the string for the given cube size
        void fixString(std::string fixText, int cubeSize) {
            text = fixText;
            if (cubeSize == X2) {
                for (int i = 0; i < text.length(); ++i) {
                    if (!(text[i] == 'U' || text[i] == 'D'
                       || text[i] == 'L' || text[i] == 'R'
                       || text[i] == 'F' || text[i] == 'B'
                       || text[i] == 'x' || text[i] == 'y' || text[i] == 'z' 
                       || text[i] == '\'' || text[i] == '2')) 
                       {
                        text.erase(i, 1);
                        --i;
                       }

                }
            }
            else if (cubeSize == X3) {
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
            else if (cubeSize == X4) {
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
            else if (cubeSize == X5) {
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
        }

        // Fills the square and and adds the lines
        void drawCube(int cubeSize) {
            rect = {lineSpaceing, window.h - row*(2*lineSpaceing + blockLength) + lineSpaceing, blockLength, blockLength};
            rect.makeDimensions();

            int numMoves = text.length();
            for (int i = 0; i < text.length(); ++i) {
                if (text[i] == '\'' || text[i] == '2') {

                    // This is to fix a bug with multiple 2's or 's in the string
                    while ((text[i] == '\'' || text[i] == '2') && (text[i+1] == '\'' || text[i+1] == '2')) {
                        text.erase(i + 1, 1);
                        --i;
                    }

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
        SDL_Point upArrow[5];
        SDL_Point downArrow[5];
        SDL_Point leftArrow[5];
        SDL_Point rightArrow[5];
        int radius;
        SDL_Point point;
        int fontSize = 40;

        // Set up the next rect to be drawn
        void nextRect() {
            if (rect.rightX < window.w - lineSpaceing) {
                rect.x = rect.x + blockLength + 2*lineSpaceing;
                rect.makeDimensions();  
            }
            else {
                rect.x = lineSpaceing;
                rect.y = rect.y + blockLength + 2*lineSpaceing;
                rect.makeDimensions();
            }        
        }

        // Draw arrow on the cube
        void drawArrow(int cubeSize) {
            rect = {lineSpaceing, window.h - row*(2*lineSpaceing + blockLength) + lineSpaceing, blockLength, blockLength};
            rect.makeDimensions();

            for (int i = 0; i < text.length(); ++i) {
                if (i == text.find("U'", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("u'", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.y = point.y + (blockLength/cubeSize);
                        makeRightArrow(point, cubeSize);
                        window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("U2", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("U", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("u", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.y = point.y + (blockLength/cubeSize);
                        makeLeftArrow(point, cubeSize);
                        window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                    }

                    if (i + 1 == text.find("2", i + 1)) {
                        ++i;
                    }
                }

                else if (i == text.find("D'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("d'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.y = point.y - blockLength/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("D2", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("D", i)) { 
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("d", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.y = point.y - blockLength/cubeSize;
                        makeRightArrow(point, cubeSize);
                        window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    }

                    if (i + 1 == text.find("2", i + 1)) {
                        ++i;
                    }
                }

                else if (i == text.find("L'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("l'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.x = point.x + blockLength/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    }
                
                    ++i;
                }
                else if (i == text.find("L2", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("L", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("l", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.x = point.x + blockLength/cubeSize;
                        makeDownArrow(point, cubeSize);
                        window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    }
                    
                    if (i + 1 == text.find("2", i + 1)) {
                        ++i;
                    }
                }

                else if (i == text.find("R'", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("r'", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.x = point.x - blockLength/cubeSize;
                        makeDownArrow(point, cubeSize);
                        window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("R2", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("R", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("r", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        point.x = point.x - blockLength/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    }
                    
                    if (i + 1 == text.find("2", i + 1)) {
                        ++i;
                    }
                }
                
                else if (i == text.find("F'", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("f'", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 4);
                    window.drawLines(upArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(downArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &cyan, radius, 2);
                    window.drawLines(upArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(rightArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(downArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(leftArrow, &cyan, numArrowPoints, 2, 2);

                    ++i;
                }
                else if (i == text.find("F2", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("F", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("f", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 4);
                    window.drawLines(upArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(downArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &cyan, radius, 2);
                    window.drawLines(upArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(rightArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(downArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(leftArrow, &cyan, numArrowPoints, 2, 2);
                    
                    if (i + 1 == text.find("2", i + 1)) {
                        ++i;
                    }
                }
                
                else if (i == text.find("B'", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&backTexture);

                    ++i;
                }
                else if (i == text.find("b'", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 4);
                    window.drawLines(upArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(downArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &cyan, radius, 2);
                    window.drawLines(upArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(rightArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(downArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(leftArrow, &cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);

                    ++i;
                }
                else if (i == text.find("B2", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&b2Texture); 

                    ++i;
                }
                else if (i == text.find("B", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&backTexture);
                }
                else if (i == text.find("b", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 4);
                    window.drawLines(upArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(downArrow, &violet, numArrowPoints, 4, 4);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &cyan, radius, 2);
                    window.drawLines(upArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(rightArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(downArrow, &cyan, numArrowPoints, 2, 2);
                    window.drawLines(leftArrow, &cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);
                    
                    if (i + 1 == text.find("2", i + 1)) {
                        ++i;
                    }
                }
                
                else if (i == text.find("x'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i) {
                        point.x = point.x + blockLength/cubeSize;
                        makeDownArrow(point, cubeSize);
                        window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    }
                    ++i;
                }
                else if (i == text.find("x2", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i) {
                        point.x = point.x + blockLength/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("x", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i) {
                        point.x = point.x + blockLength/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    }
                }
                
                else if (i == text.find("y'", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    
                    for (int i = 0; i < cubeSize - 1; ++i) {
                        point.y = point.y + blockLength/cubeSize;
                        makeRightArrow(point, cubeSize);
                        window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("y2", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i) {
                        point.y = point.y + blockLength/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("y", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i) {
                        point.y = point.y + blockLength/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                    }
                }
                
                else if (i == text.find("z'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    
                    ++i;
                }
                else if (i == text.find("z2", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("z", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);

                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                }

                else if (i == text.find("M'", i)) {
                    point.x = rect.x + (blockLength/cubeSize) + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        makeUpArrow(point, cubeSize);
                        window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                        point.x = point.x + blockLength/cubeSize;
                    }

                    ++i;
                }
                else if (i == text.find("M2", i)) {
                    point.x = rect.x + (blockLength/cubeSize) + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        makeUpArrow(point, cubeSize);
                        window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                        point.x = point.x + blockLength/cubeSize;
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("M", i)) {
                    point.x = rect.x + (blockLength/cubeSize) + (blockLength/cubeSize)/2;
                    point.y = rect.y + blockLength - (blockLength/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i) {
                        makeDownArrow(point, cubeSize);
                        window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                        point.x = point.x + blockLength/cubeSize;
                    }
                }
                else if (i == text.find("E'", i)) {
                    point.x = rect.x + (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize) + (blockLength/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i) { 
                        makeLeftArrow(point, cubeSize);
                        window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);
                        point.y = point.y + blockLength/cubeSize;
                    }

                    ++i;
                }
                else if (i == text.find("E2", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize) + (blockLength/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i) { 
                        makeRightArrow(point, cubeSize);
                        window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                        point.y = point.y + blockLength/cubeSize;
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("E", i)) {
                    point.x = rect.x + blockLength - (blockLength/cubeSize)/2;
                    point.y = rect.y + (blockLength/cubeSize) + (blockLength/cubeSize)/2;
                    
                    for (int i = 0; i < cubeSize - 2; ++i) { 
                        makeRightArrow(point, cubeSize);
                        window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                        point.y = point.y + blockLength/cubeSize;
                    }
                }
                else if (i == text.find("S'", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&sliceTexture);

                    ++i;
                }
                else if (i == text.find("S2", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&s2Texture);

                    ++i;
                }
                else if (i == text.find("S", i)) {
                    point.x = rect.x + blockLength/2;
                    point.y = rect.y + blockLength/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window.drawCircle(point, &violet, radius, 3);
                    window.drawLines(upArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(rightArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(downArrow, &violet, numArrowPoints, 3, 3);
                    window.drawLines(leftArrow, &violet, numArrowPoints, 3, 3);

                    renderCenterText(&sliceTexture);
                }
                
                nextRect();
            }
        }

        void makeUpArrow(SDL_Point upArrowPoint, int cubeSize) {
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

        void makeDownArrow(SDL_Point downArrowPoint, int cubeSize) {
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

        void makeLeftArrow(SDL_Point leftArrowPoint, int cubeSize) {
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

        void makeRightArrow(SDL_Point rightArrowPoint, int cubeSize) {
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

        void makeCircleArrows(SDL_Point center, int cubeSize, int clockwise = 1) {
            radius = blockLength/2 - (blockLength/cubeSize)/2;

            rightArrow[0].x = center.x;
            rightArrow[0].y = center.y - blockLength/2 + (blockLength/cubeSize)/2;

            rightArrow[1].x = rightArrow[0].x - clockwise*10;
            rightArrow[1].y = rightArrow[0].y - 10;

            rightArrow[2].x = center.x;
            rightArrow[2].y = center.y - blockLength/2 + (blockLength/cubeSize)/2;

            rightArrow[3].x = rightArrow[0].x - clockwise*10;
            rightArrow[3].y = rightArrow[0].y + 10;

            rightArrow[4].x = center.x;
            rightArrow[4].y = center.y - blockLength/2 + (blockLength/cubeSize)/2;



            downArrow[0].x = center.x + blockLength/2 - (blockLength/cubeSize)/2;
            downArrow[0].y = center.y;

            downArrow[1].x = downArrow[0].x - 10;
            downArrow[1].y = downArrow[0].y - clockwise*10;

            downArrow[2].x = center.x + blockLength/2 - (blockLength/cubeSize)/2;
            downArrow[2].y = center.y;

            downArrow[3].x = downArrow[0].x + 10;
            downArrow[3].y = downArrow[0].y - clockwise*10;

            downArrow[4].x = center.x + blockLength/2 - (blockLength/cubeSize)/2;
            downArrow[4].y = center.y;



            leftArrow[0].x = center.x;
            leftArrow[0].y = center.y + blockLength/2 - (blockLength/cubeSize)/2;

            leftArrow[1].x = leftArrow[0].x + clockwise*10;
            leftArrow[1].y = leftArrow[0].y + 10;

            leftArrow[2].x = center.x;
            leftArrow[2].y = center.y + blockLength/2 - (blockLength/cubeSize)/2;

            leftArrow[3].x = leftArrow[0].x + clockwise*10;
            leftArrow[3].y = leftArrow[0].y - 10;

            leftArrow[4].x = center.x;
            leftArrow[4].y = center.y + blockLength/2 - (blockLength/cubeSize)/2;



            upArrow[0].x = center.x - blockLength/2 + (blockLength/cubeSize)/2;
            upArrow[0].y = center.y;

            upArrow[1].x = upArrow[0].x - 10;
            upArrow[1].y = upArrow[0].y + clockwise*10;

            upArrow[2].x = center.x - blockLength/2 + (blockLength/cubeSize)/2;
            upArrow[2].y = center.y;

            upArrow[3].x = upArrow[0].x + 10;
            upArrow[3].y = upArrow[0].y + clockwise*10;

            upArrow[4].x = center.x - blockLength/2 + (blockLength/cubeSize)/2;
            upArrow[4].y = center.y;
        }

        void renderCenterText(textureText* letterTexture) {
            SDL_Rect background = rect;
            background.x = background.x + blockLength/2;
            background.y = background.y + blockLength/2;
            background.w = fontSize;
            background.h = fontSize;
            background.makeDimensions();
            background.shiftXY();
            window.fillRect(&black, background);

            letterTexture->rect.x = rect.x + blockLength/2;
            letterTexture->rect.y = rect.y + blockLength/2 + 4;
            letterTexture->rect.makeDimensions();
            letterTexture->rect.shiftXY();
            letterTexture->createTexture(window.renderer);
            letterTexture->render(window.renderer);
        }

};

#endif // CUBE_H
