#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_CLasses.h>
#include <fstream>

#define NUM_ROW (4)
#define NUM_COL (8)

extern const double ratio;
extern int line_spaceing; //15
extern int block_length; //160

int fps = 15;

extern Window window;

typedef enum Mode_e
{
    QUIT,
    Main_Menu,
    X2,
    X3,
    X4,
    X5,
    X6,
    X7
} Mode_t;

int main_menu();
int algorithm_images();

#endif // MAIN_H