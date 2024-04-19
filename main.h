#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_CLasses.h>
#include <fstream>

int windowWidth = 1280; //1415, 1280
int windowHeight = 720; //875, 720
int row = 4;
int col = 8;
const double ratio = windowHeight/windowWidth;
int lineSpaceing = 7*(windowHeight/720.0); //15
int blockLength = (windowWidth/col) - (2*lineSpaceing); //160

int fps = 15;

win window(windowWidth, windowHeight, "Loading Algorithm");

enum menu {
    QUIT,
    Main_Menu,
    X2,
    X3,
    X4,
    X5,
    X6,
    X7
};

int main_menu();
int algorithm_images();

#endif // MAIN_H