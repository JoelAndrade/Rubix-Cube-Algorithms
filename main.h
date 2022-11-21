#include <iostream>
#include <string>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_CLasses.h>
#include <SDL_Functions.h>
#include <cube.h>

#ifndef MAIN_H
#define MAIN_H

int blockLength = 160;
int row = 5;
int col = 8;
int windowWidth = blockLength*col;
int windowHeight = blockLength*row;
int fps = 15;

SDL_Color violet = {255, 0, 255};
SDL_Color green = {0, 255, 0};
SDL_Color red = {255, 0, 0};
SDL_Color cyan = {0, 150, 225};
SDL_Color blue = {0, 0, 255};
SDL_Color black = {0, 0, 0};
SDL_Color white = {255, 255, 255};

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
void drawScreen2x2();
void drawScreen3x3();
void drawScreen4x4();

#endif