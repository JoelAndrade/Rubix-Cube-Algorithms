#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_CLasses.h>
#include <fstream>

int blockLength = 160;
int row = 5;
int col = 8;
int windowWidth = blockLength*col;
int windowHeight = blockLength*row;
int fps = 15;

win window("Loading Algorithm", windowWidth, windowHeight);

enum menu {
    QUIT,
    MAINMENU,
    X2,
    X3,
    X4,
    X5,
    X6,
    X7
};

int mainMenu();
int algorithmImages();

#endif // MAIN_H