#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_CLasses.h>
#include <fstream>

#define FONT_PATH ("Fonts/Agane 55 (roman).ttf")
#define FPS (15)

#define NUM_ROW (4)
#define NUM_COL (8)

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

extern const double ratio;

extern Window window;
extern TextureText text;
extern SDL_Rect top_rect;

extern Uint32 starting_tick;
extern SDL_Event event;

int main_menu();
int algorithm_images();

#endif // MAIN_H