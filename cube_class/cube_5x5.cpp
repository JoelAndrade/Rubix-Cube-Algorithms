#include "cube_5x5.h"

#include <SDL_CLasses.h>
#include <SDL_Util.h>

#define CUBE_SIZE_5X5 (5)

Cube5x5::Cube5x5() {}
Cube5x5::Cube5x5(Window *window, std::string text, int row, int col)
{
    this->window = window;
    this->text = text;
    this->row = row;
    this->col = col;
}

void Cube5x5::init(Window *window, std::string text, const char* font_path, int row, int col)
{
    this->window = window;
    this->text = text;
    this->row = row;
    this->col = col;

    line_spacing = 7*(window->h/window->h);
    block_length = (window->w/col) - (2*line_spacing);

    x2_texture.init(window->renderer,            font_path, "x2",    FONT_SIZE - 10);
    back_texture.init(window->renderer,          font_path, "B",     FONT_SIZE);
    b2_texture.init(window->renderer,            font_path, "Bx2",   FONT_SIZE - 20);
    _3b_texture.init(window->renderer,           font_path, "3B",    FONT_SIZE - 10);
    _3bx2_texture.init(window->renderer,         font_path, "3Bx2",  FONT_SIZE - 24);
    slice_texture.init(window->renderer,         font_path, "S",     FONT_SIZE);
    s2_texture.init(window->renderer,            font_path, "S2",    FONT_SIZE - 10);
    wide3_texture.init(window->renderer,         font_path, "3w",    FONT_SIZE - 11);
    wide3_x2_texture.init(window->renderer,      font_path, "3wx2",  FONT_SIZE - 24);
    back_wide3_texture.init(window->renderer,    font_path, "B3w",   FONT_SIZE - 20);
    back_wide3_x2_texture.init(window->renderer, font_path, "B3wx2", FONT_SIZE - 27);
    _3_texture.init(window->renderer,            font_path, "3",     FONT_SIZE);
    _3_x2_texture.init(window->renderer,         font_path, "3x2",   FONT_SIZE - 20);
    wide4_texture.init(window->renderer,         font_path, "4w",    FONT_SIZE - 11);
    wide4_x2_texture.init(window->renderer,      font_path, "4wx2",  FONT_SIZE - 24);
    back_wide4_texture.init(window->renderer,    font_path, "B4w",   FONT_SIZE - 20);
    back_wide4_x2_texture.init(window->renderer, font_path, "B4wx2", FONT_SIZE - 27);

    x2_texture.change_color(SDL_white);
    back_texture.change_color(SDL_white);
    b2_texture.change_color(SDL_white);
    _3b_texture.change_color(SDL_white);
    _3bx2_texture.change_color(SDL_white);
    slice_texture.change_color(SDL_white);
    s2_texture.change_color(SDL_white);
    wide3_texture.change_color(SDL_white);
    wide3_x2_texture.change_color(SDL_white);
    back_wide3_texture.change_color(SDL_white);
    back_wide3_x2_texture.change_color(SDL_white);
    _3_texture.change_color(SDL_white);
    _3_x2_texture.change_color(SDL_white);
    wide4_texture.change_color(SDL_white);
    wide4_x2_texture.change_color(SDL_white);
    back_wide4_texture.change_color(SDL_white);
    back_wide4_x2_texture.change_color(SDL_white);
}

// Fixes the string for the given cube size
void Cube5x5::fix_string(std::string fix_text)
{
    text = fix_text;
    for (int i = 0; i < text.length(); i++)
    {
        if (!(text[i] == 'U' ||
              text[i] == 'D' ||
              text[i] == 'L' ||
              text[i] == 'R' ||
              text[i] == 'F' ||
              text[i] == 'B' ||
              text[i] == 'x' || text[i] == 'y' || text[i] == 'z' ||
              text[i] == 'M' || text[i] == 'E' || text[i] == 'S' ||
              text[i] == '\''|| text[i] == '2' || text[i] == 'w' ||
              text[i] == '3' || text[i] == '4'))
        {
            text.erase(i, 1);
            i--;
        }
    }

    // ' or w can not be first
    while (text[0] == '\'' || text[0] == 'w')
    {
        text.erase(0, 1);
    }

    // A 2 can not be followed with a 2
    while (text[0] == '2' && text[1] == '2')
    {
        text.erase(0, 1);
    }

    // TODO: Bug where "3R" and "2R" next to each other are not compadible

    // The second "for loop" is to double check
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < text.length(); i++)
        {
            // Check for trailing w after a w
            while (text[i] == 'w' && text[i + 1] == 'w')
            {
                text.erase(i + 1, 1);
            }

            // Check that w is being used with a capital letter
            while (text[i] == 'w' && !LIMITS('A', text[i - 1], 'Z'))
            {
                text.erase(i, 1);
            }

            // Check that a 3 or 4 will follow with a capital letter
            while ((text[i] == '3' || text[i] == '4') && (!LIMITS('A', text[i + 1], 'Z')))
            {
                text.erase(i, 1);
            }

            // Check the string doesnt have consecutive 's and w's after an ' or 2
            while ((text[i]     == '\'' || text[i]     == '2') && 
                   (text[i + 1] == '\'' || text[i + 1] == 'w'))
            {
                text.erase(i + 1, 1);
            }

            // Checks that 2's are used correctly
            while ((text[i] == '2' || text[i] == '\'') && text[i + 1] == '2' && !LIMITS('A', text[i + 2], 'Z'))
            {
                text.erase(i + 1, 1);
            }
        }
    }
}

// Fills the square and and adds the lines
void Cube5x5::draw_cube(void)
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
        if (text[i] == '\'' || text[i] == '2' || text[i] == 'w' || text[i] == '3' || text[i] == '4')
        {
            num_moves--;
        }               
    }

    draw_rects(window, &rect, num_moves, CUBE_SIZE_5X5, line_spacing, block_length);
    draw_arrows();
}

// Draw arrow on the cube
void Cube5x5::draw_arrows(void)
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
        if (i == text.find("4Uw'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 3;
        }
        else if (i == text.find("4Uw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Uw'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 3;
        }
        else if (i == text.find("3Uw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Uw", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3Uw", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Uw'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Uw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3U'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + 5*(block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("2U'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + 3*(block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3U2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + 5*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2U2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + 3*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3U", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + 5*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("2U", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + 3*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("U'", i))
        {
            U_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("Uw", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y + (block_length/CUBE_SIZE_5X5);
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("U2", i))
        {
            U2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("U", i))
        {
            U_COMMON(CUBE_SIZE_5X5);
        }

        // D moves
        else if (i == text.find("4Dw'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 3;
        }
        else if (i == text.find("4Dw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Dw'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 3;
        }
        else if (i == text.find("3Dw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Dw", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3Dw", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Dw'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Dw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3D'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - 5*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("2D'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - 3*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3D2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - 5*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2D2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - 3*(block_length/CUBE_SIZE_5X5)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3D", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - 5*(block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("2D", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - 3*(block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("D'", i))
        {
            D_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("Dw", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.y = arrow_point.y - block_length/CUBE_SIZE_5X5;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("D2", i))
        {
            D2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("D", i))
        { 
            D_COMMON(CUBE_SIZE_5X5);
        }

        // L moves
        else if (i == text.find("4Lw'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        
            i += 3;
        }
        else if (i == text.find("4Lw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Lw'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        
            i += 3;
        }
        else if (i == text.find("3Lw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Lw", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3Lw", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Lw'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        
            i += 2;
        }
        else if (i == text.find("Lw2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3L'", i))
        {
            arrow_point.x = rect.x + 5*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("2L'", i))
        {
            arrow_point.x = rect.x + 3*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3L2", i))
        {
            arrow_point.x = rect.x + 5*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2L2", i))
        {
            arrow_point.x = rect.x + 3*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3L", i))
        {
            arrow_point.x = rect.x + 5*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("2L", i))
        {
            arrow_point.x = rect.x + 3*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("L'", i))
        {
            L_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("Lw", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x + block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("L2", i))
        {
            L2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("L", i))
        {
            L_COMMON(CUBE_SIZE_5X5);
        }

        // R moves
        else if (i == text.find("4Rw'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 3;
        }
        else if (i == text.find("4Rw2", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Rw'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 3;
        }
        else if (i == text.find("3Rw2", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Rw", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3Rw", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Rw'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("Rw2", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3R'", i))
        {
            arrow_point.x = rect.x + block_length - 5*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("2R'", i))
        {
            arrow_point.x = rect.x + block_length - 3*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_5X5)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i += 2;
        }
        else if (i == text.find("3R2", i))
        {
            arrow_point.x = rect.x + block_length - 5*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2R2", i))
        {
            arrow_point.x = rect.x + block_length - 3*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3R", i))
        {
            arrow_point.x = rect.x + block_length - 5*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("2R", i))
        {
            arrow_point.x = rect.x + block_length - 3*(block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("R'", i))
        {
            R_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("Rw", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_5X5)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_5X5)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = arrow_point.x - block_length/CUBE_SIZE_5X5;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_5X5, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("R2", i))
        {
            R2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("R", i))
        {
            R_COMMON(CUBE_SIZE_5X5);
        }
        
        // F moves
        else if (i == text.find("4Fw'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &wide4_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Fw2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &wide4_x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Fw'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &wide3_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Fw2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &wide3_x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Fw", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &wide4_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3Fw", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &wide3_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("Fw'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            i += 2;
        }
        else if (i == text.find("Fw2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3F'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &_3_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2F'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            i += 2;
        }
        else if (i == text.find("3F2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &_3_x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2F2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &x2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3F", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &_3_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("2F", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            i++;
        }
        else if (i == text.find("F'", i))
        {
            F_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("Fw", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            i++;
        }
        else if (i == text.find("F2", i))
        {
            F2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("F", i))
        {
            F_COMMON(CUBE_SIZE_5X5);
        }
        
        // B moves
        else if (i == text.find("4Bw'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide4_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Bw2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide4_x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Bw'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide3_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("3Bw2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide3_x2_texture, rect, block_length);

            i += 3;
        }
        else if (i == text.find("4Bw", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide4_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3Bw", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide3_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("Bw'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_wide3_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("Bw2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &b2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3B'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &_3b_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2B'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3B2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &_3bx2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("2B2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &b2_texture, rect, block_length);

            i += 2;
        }
        else if (i == text.find("3B", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &_3b_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("2B", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_black, radius, 4);
            window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("B'", i))
        {
            B_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("Bw", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_violet, radius, 4);
            window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_5X5,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("B2", i))
        {
            B2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("B", i))
        {
            B_COMMON(CUBE_SIZE_5X5);
        }
        
        // x moves
        else if (i == text.find("x'", i))
        {
            X_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("x2", i))
        {
            X2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("x", i))
        {
            X_COMMON(CUBE_SIZE_5X5);
        }
        
        // y moves
        else if (i == text.find("y'", i))
        {
            Y_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("y2", i))
        {
            Y2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("y", i))
        {
            Y_COMMON(CUBE_SIZE_5X5);
        }
        
        // z moves
        else if (i == text.find("z'", i))
        {
            Z_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("z2", i))
        {
            Z2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("z", i))
        {
            Z_COMMON(CUBE_SIZE_5X5);
        }

        // Slice moves
        else if (i == text.find("M'", i))
        {
            M_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("M2", i))
        {
            M2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("M", i))
        {
            M_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("E'", i))
        {
            E_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("E2", i))
        {
            E2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("E", i))
        {
            E_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("S'", i))
        {
            S_PRIME_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("S2", i))
        {
            S2_COMMON(CUBE_SIZE_5X5);
        }
        else if (i == text.find("S", i))
        {
            S_COMMON(CUBE_SIZE_5X5);
        }

        next_rect(window, &rect, line_spacing, block_length);
    }
}
