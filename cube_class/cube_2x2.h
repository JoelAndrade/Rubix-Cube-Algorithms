#ifndef CUBE_2X2_H
#define CUBE_2X2_H

#include "cube_common.h"

#include <SDL2/SDL.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#include <iostream>
#include <string.h>

class Cube2x2
{
    public:
        Window *window = NULL;
        int row;
        int col;
        int line_spacing;
        int block_length;
        std::string text;
        
        TextureText x2_texture;
        TextureText back_texture;
        TextureText b2_texture;
        
        Cube2x2();
        Cube2x2(Window *window, std::string text, int row, int col);

        void init(Window *window, std::string text, const char* font_path, int row, int col);

        // Fixes the string for the given cube size
        void fix_string(std::string fix_text);

        // Fills the square and and adds the lines
        void draw_cube(void);
        
    private:
        SDL_Rect rect;

        // Draw arrow on the cube
        void draw_arrows(void);
};

#endif // CUBE_2X2_H