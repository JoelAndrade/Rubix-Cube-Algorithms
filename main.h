#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_CLasses.h>
#include <SDL_Functions.h>

#ifndef MAIN_H
#define MAIN_H

enum menu {
    QUIT, MAINMENU, X2, X3, X4, X5, X6, X7
};

int blockLength = 160;
int row = 5;
int col = 8;
int windowWidth = blockLength*col;
int windowHeight = blockLength*row;
int fps = 15;
std::string loadText = "R U2 R2 F R F' U2 R' F R F'";

int mode = X3;

const int numPoints = 9;
SDL_Point points[numPoints] = {
    {100, 50}, {200, 50}, {300, 50},
    {100, 150}, {200, 150}, {300, 150},
    {100, 250}, {200, 250}, {300, 250}
};

int mainMenu();
int algorithmImages();

#endif