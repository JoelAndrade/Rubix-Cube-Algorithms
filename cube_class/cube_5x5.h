#ifndef CUBE_5X5_H
#define CUBE_5X5_H

#include "cube_common.h"

#include <SDL2/SDL.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#include <iostream>
#include <string.h>

class Cube5x5
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
        TextureText _3b_texture;
        TextureText _3bx2_texture;
        TextureText slice_texture;
        TextureText s2_texture;
        TextureText wide3_texture;
        TextureText wide3_x2_texture;
        TextureText back_wide3_texture;
        TextureText back_wide3_x2_texture;
        TextureText _3_texture;
        TextureText _3_x2_texture;
        TextureText wide4_texture;
        TextureText wide4_x2_texture;
        TextureText back_wide4_texture;
        TextureText back_wide4_x2_texture;
        
        Cube5x5();
        Cube5x5(Window *window, std::string text, int row, int col);

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

#endif // CUBE_5X5_H
