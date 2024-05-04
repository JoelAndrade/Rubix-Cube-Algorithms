#include "cube_2x2.h"

#include <SDL_CLasses.h>
#include <SDL_Util.h>

#define CUBE_SIZE_2X2 (2)

Cube2x2::Cube2x2() {}
Cube2x2::Cube2x2(Window *window, std::string text, int row, int col)
{
    this->window = window;
    this->text = text;
    this->row = row;
    this->col = col;
}

void Cube2x2::init(Window *window, std::string text, const char* font_path, int row, int col)
{
    this->window = window;
    this->text = text;
    this->row = row;
    this->col = col;

    line_spacing = 7*(window->h/window->h);
    block_length = (window->w/col) - (2*line_spacing);

    x2_texture.init(window->renderer,   font_path, "x2",  FONT_SIZE - 10);
    back_texture.init(window->renderer, font_path, "B",   FONT_SIZE);
    b2_texture.init(window->renderer,   font_path, "Bx2", FONT_SIZE - 20);
    
    x2_texture.change_color(SDL_white);
    back_texture.change_color(SDL_white);
    b2_texture.change_color(SDL_white);
}

// Fixes the string for the given cube size
void Cube2x2::fix_string(std::string fix_text)
{
    text = fix_text;
    for (int i = 0; i < text.length(); i++)
    {
        if (!(text[i] == 'U'  || text[i] == 'D' ||
              text[i] == 'L'  || text[i] == 'R' ||
              text[i] == 'F'  || text[i] == 'B' ||
              text[i] == 'x'  || text[i] == 'y' || text[i] == 'z' ||
              text[i] == '\'' || text[i] == '2'))
        {
            text.erase(i, 1);
            i--;
        }
    }

    // Check that ' and 2 are not in the front of string
    while (text[0] == '\'' || text[0] == '2')
    {
        text.erase(0, 1);
    }

    for (int i = 0; i < text.length(); i++)
    {
        // Check the string doesnt have consecutive 's and 2's after an ' or 2
        while ((text[i]      == '\'' || text[i]     == '2') && 
                (text[i + 1] == '\'' || text[i + 1] == '2'))
        {
            text.erase(i + 1, 1);
        }
    }
}

// Fills the square and and adds the lines
void Cube2x2::draw_cube(void)
{
    rect = {
        line_spacing,
        window->h - row*(2*line_spacing + block_length) + line_spacing,
        block_length,
        block_length
    };
    rect_make_dimensions(&rect);

    int num_moves = text.length();
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '\'' || text[i] == '2')
        {
            num_moves--;
        }               
    }

    draw_rects(window, &rect, num_moves, CUBE_SIZE_2X2, line_spacing, block_length);
    draw_arrows();
}

// Draw arrow on the cube
void Cube2x2::draw_arrows(void)
{
    SDL_Point up_arrow[NUM_ARROW_POINTS];
    SDL_Point down_arrow[NUM_ARROW_POINTS];
    SDL_Point left_arrow[NUM_ARROW_POINTS];
    SDL_Point right_arrow[NUM_ARROW_POINTS];
    SDL_Point arrow_point;
    int radius;

    rect = {
        line_spacing,
        window->h - row*(2*line_spacing + block_length) + line_spacing,
        block_length,
        block_length
    };
    rect_make_dimensions(&rect);

    for (int i = 0; i < text.length(); i++)
    {
        // U moves
        if (i == text.find("U'", i))
        {
            U_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("U2", i))
        {
            U2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("U", i))
        {
            U_COMMON(CUBE_SIZE_2X2);
        }

        // D moves
        else if (i == text.find("D'", i))
        {
            D_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("D2", i))
        {
            D2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("D", i))
        { 
            D_COMMON(CUBE_SIZE_2X2);
        }

        // L moves
        else if (i == text.find("L'", i))
        {
            L_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("L2", i))
        {
            L2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("L", i))
        {
            L_COMMON(CUBE_SIZE_2X2);
        }

        // R moves
        else if (i == text.find("R'", i))
        {
            R_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("R2", i))
        {
            R2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("R", i))
        {
            R_COMMON(CUBE_SIZE_2X2);
        }
        
        // F moves
        else if (i == text.find("F'", i))
        {
            F_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("F2", i))
        {
            F2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("F", i))
        {
            F_COMMON(CUBE_SIZE_2X2);
        }
        
        // B moves
        else if (i == text.find("B'", i))
        {
            B_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("B2", i))
        {
            B2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("B", i))
        {
            B_COMMON(CUBE_SIZE_2X2);
        }
        
        // x moves
        else if (i == text.find("x'", i))
        {
            X_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("x2", i))
        {
            X2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("x", i))
        {
            X_COMMON(CUBE_SIZE_2X2);
        }
        
        // y moves
        else if (i == text.find("y'", i))
        {
            Y_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("y2", i))
        {
            Y2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("y", i))
        {
            Y_COMMON(CUBE_SIZE_2X2);
        }
        
        // z moves
        else if (i == text.find("z'", i))
        {
            Z_PRIME_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("z2", i))
        {
            Z2_COMMON(CUBE_SIZE_2X2);
        }
        else if (i == text.find("z", i))
        {
            Z_COMMON(CUBE_SIZE_2X2);
        }

        next_rect(window, &rect, line_spacing, block_length);
    }
}
