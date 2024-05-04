#ifndef CUBE_H
#define CUBE_H

#include <SDL2/SDL.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#include <iostream>
#include <string.h>

#define WINDOW_WIDTH (1280) //1415, 1280
#define WINDOW_HEIGHT (720) //875, 720

#define NUM_ROW (4)
#define NUM_COL (8)

#define LINE_SPACING (7)
#define BLOCK_LENGTH ((WINDOW_WIDTH/NUM_COL) - (2*LINE_SPACING))
#define NUM_ARROW_POINTS (5)
#define FONT_SIZE (40)

#define CLOCKWISE (1)
#define COUNTER_CLOCKWISE (-1)

#define FONT_PATH ("Fonts/Agane 55 (roman).ttf")

class Cube
{
    public:
        Window *window = NULL;
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
        
        Cube() {}
        Cube(Window *window, std::string text)
        {
            this->window = window;
            this->text = text;
        }

        void init(Window *window, std::string text, const char* font_path)
        {
            this->window = window;
            this->text = text;

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
        void fix_string(std::string fix_text, int cube_size)
        {
            text = fix_text;
            if (cube_size == X2)
            {
                for (int i = 0; i < text.length(); i++)
                {
                    if (!(text[i] == 'U'  || text[i] == 'D'
                       || text[i] == 'L'  || text[i] == 'R'
                       || text[i] == 'F'  || text[i] == 'B'
                       || text[i] == 'x'  || text[i] == 'y' || text[i] == 'z' 
                       || text[i] == '\'' || text[i] == '2')) 
                    {
                        text.erase(i, 1);
                        --i;
                    }

                }
            }
            else if (cube_size == X3)
            {
                for (int i = 0; i < text.length(); i++)
                {
                    if (!(text[i] == 'U' || text[i] == 'u' ||
                          text[i] == 'D' || text[i] == 'd' ||
                          text[i] == 'L' || text[i] == 'l' ||
                          text[i] == 'R' || text[i] == 'r' ||
                          text[i] == 'F' || text[i] == 'f' ||
                          text[i] == 'B' || text[i] == 'b' ||
                          text[i] == 'x' || text[i] == 'y' || text[i] == 'z' ||
                          text[i] == 'M' || text[i] == 'E' || text[i] == 'S' ||
                          text[i] == '\''|| text[i] == '2' || text[i] == 'w')) 
                    {
                        text.erase(i, 1);
                        --i;
                    }

                }
            }
            else if (cube_size == X4)
            {
                for (int i = 0; i < text.length(); i++)
                {
                    if (!(text[i] == 'U' || text[i] == 'u' ||
                          text[i] == 'D' || text[i] == 'd' ||
                          text[i] == 'L' || text[i] == 'l' ||
                          text[i] == 'R' || text[i] == 'r' ||
                          text[i] == 'F' || text[i] == 'f' ||
                          text[i] == 'B' || text[i] == 'b' ||
                          text[i] == 'x' || text[i] == 'y' || text[i] == 'z' ||
                          text[i] == 'M' || text[i] == 'E' || text[i] == 'S' ||
                          text[i] == '\''|| text[i] == '2' || text[i] == 'w' ||
                          text[i] == '3'))
                       {
                        text.erase(i, 1);
                        --i;
                       }
                       
                }
            }
            else if (cube_size == X5)
            {
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
                        --i;
                       }
                       
                }
            }

            switch (cube_size)
            {
            case X2:
                // Checkout that ' and 2 are not in the front of string
                while (text[0] == '\'' || text[0] == '2')
                {
                    text.erase(0, 1);
                }

                for (int i = 0; i < text.length(); i++)
                {
                    // Check the string doesnt have consecutive 's and 2's after an ' or 2
                    while ((text[i]     == '\'' || text[i]     == '2') && 
                           (text[i + 1] == '\'' || text[i + 1] == '2'))
                    {
                        text.erase(i + 1, 1);
                    }
                }
                break;
            
            case X3:
                // Checkout that ' and 2 are not in the front of string
                while (text[0] == '\'' || text[0] == '2')
                {
                    text.erase(0, 1);
                }

                for (int i = 0; i < text.length(); i++)
                {
                    // Check the string doesnt have consecutive 's and 2's after an ' or 2
                    while ((text[i]     == '\'' || text[i]     == '2') && 
                           (text[i + 1] == '\'' || text[i + 1] == '2')) 
                    {
                        text.erase(i + 1, 1);
                    }
                }
                break;

            case X4:
                // ' or w can not be first
                while (text[0] == '\'' || text[0] == 'w')
                {
                    text.erase(0, 1);
                }

                // A 2 can not be followed with a 2 or lowercase letter 
                while (text[0] == '2' && (text[1] == '2' || (('a' <= text[1]) && (text[1] <= 'z'))))
                {
                    text.erase(0, 1);
                }

                // The second "for loop" is to double check
                for (int j = 0; j < 2; ++j)
                {
                    for (int i = 0; i < text.length(); i++)
                    {

                        // Check for trailing w after a w
                        while (text[i] == 'w' && text[i + 1] == 'w')
                        {
                            text.erase(i + 1, 1);
                        }

                        // Check that w is being used with a capital letter
                        while (text[i] == 'w' && !(('A' <= text[i - 1]) && (text[i - 1] <= 'Z')))
                        {
                            text.erase(i, 1);
                        }

                        // Check that a 3 will follow with a capital letter
                        while (text[i] == '3' && (!(('A' <= text[i + 1]) && (text[i + 1] <= 'Z'))))
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
                        while ((text[i] == '2' || text[i] == '\'') && text[i + 1] == '2' && !(('A' <= text[i + 2]) && (text[i + 2]) <= 'Z'))
                        {
                            text.erase(i + 1, 1);
                        }
                    }
                }
                break;

            case X5:
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

                // The second "for loop" is to double check
                for (int j = 0; j < 2; ++j)
                {
                    for (int i = 0; i < text.length(); i++)
                    {

                        // Check for trailing w after a w
                        while (text[i] == 'w' && text[i + 1] == 'w')
                        {
                            text.erase(i + 1, 1);
                        }

                        // Check that w is being used with a capital letter
                        while (text[i] == 'w' && !(('A' <= text[i - 1]) && (text[i - 1] <= 'Z')))
                        {
                            text.erase(i, 1);
                        }

                        // Check that a 3 or 4 will follow with a capital letter
                        while ((text[i] == '3' || text[i] == '4') && (!(('A' <= text[i + 1]) && (text[i + 1] <= 'Z'))))
                        {
                            text.erase(i, 1);
                        }

                        // Check the string doesnt have consecutive 's and w's after an ' or 2
                        while ((text[i] == '\'' || text[i] == '2') && 
                               (text[i + 1] == '\'' || text[i + 1] == 'w')) 
                        {
                            text.erase(i + 1, 1);
                        }

                        // Checks that 2's are used correctly
                        while ((text[i] == '2' || text[i] == '\'') && text[i + 1] == '2' && !(('A' <= text[i + 2]) && (text[i + 2]) <= 'Z'))
                        {
                            text.erase(i + 1, 1);
                        }
                    }
                }
                break;
                
            default:
                break;
            }
        }

        // Fills the square and and adds the lines
        void draw_cube(int cube_size)
        {
            rect = {
                line_spacing,
                window->h - NUM_ROW*(2*line_spacing + block_length) + line_spacing,
                block_length,
                block_length
            };
            rect_make_dimensions(&rect);

            int num_moves = text.length();
            for (int i = 0; i < text.length(); i++)
            {
                if (text[i] == '\'' || text[i] == '2' || text[i] == 'w' || text[i] == '3' || text[i] == '4')
                {
                    --num_moves;
                }               
            }

            for (int i = 0; i < num_moves; i++)
            {
                window->fill_rect(SDL_green, rect);
                for (int i = 1; i < cube_size; i++)
                {
                    window->draw_line(rect.x + (block_length*i)/cube_size, rect.y, rect.x + (block_length*i)/cube_size, rect.bottomY, SDL_black, 3, 1);
                    window->draw_line(rect.x, rect.y + (block_length*i)/cube_size, rect.rightX, rect.y + (block_length*i)/cube_size,  SDL_black, 1, 3);
                }
                window->draw_rect(SDL_blue, rect, 3, 3);

                next_rect();
            }

            draw_arrows(cube_size);
        }

    private:
        SDL_Rect rect;

        SDL_Point up_arrow[NUM_ARROW_POINTS];
        SDL_Point down_arrow[NUM_ARROW_POINTS];
        SDL_Point left_arrow[NUM_ARROW_POINTS];
        SDL_Point right_arrow[NUM_ARROW_POINTS];
        int radius;
        SDL_Point arrow_point;

        // Set up the next rect to be drawn
        void next_rect()
        {
            if (rect.rightX < window->w - line_spacing)
            {
                rect.x = rect.x + block_length + 2*line_spacing;
                rect_make_dimensions(&rect);  
            }
            else
            {
                rect.x = line_spacing;
                rect.y = rect.y + block_length + 2*line_spacing;
                rect_make_dimensions(&rect);
            }
        }

        // Draw arrow on the cube
        void draw_arrows(int cube_size)
        {
            rect = {
                line_spacing,
                window->h - NUM_ROW*(2*line_spacing + block_length) + line_spacing,
                block_length,
                block_length
            };
            rect_make_dimensions(&rect);

            for (int i = 0; i < text.length(); i++)
            {
                // U moves
                if (i == text.find("4Uw'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 3;
                }
                else if (i == text.find("4Uw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("3Uw'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 3;
                }
                else if (i == text.find("3Uw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("4Uw", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Uw", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Uw'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Uw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3U'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 5*(block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2U'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 3*(block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3U2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 5*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("2U2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3U", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 5*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("2U", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("U'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("u'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 3*(block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.y = arrow_point.y - (block_length/cube_size);
                        make_right_arrow(arrow_point, cube_size);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    i++;
                }
                else if (i == text.find("Uw", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y + (block_length/cube_size);
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("U2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("u2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.y = arrow_point.y - (block_length/cube_size);
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("U", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                }
                else if (i == text.find("u", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.y = arrow_point.y - (block_length/cube_size);
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                }

                // D moves
                else if (i == text.find("4Dw'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 3;
                }
                else if (i == text.find("4Dw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("3Dw'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 3;
                }
                else if (i == text.find("3Dw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("4Dw", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Dw", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Dw'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Dw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3D'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 5*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2D'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3D2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 5*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("2D2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3D", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 5*(block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("2D", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 3*(block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("D'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("d'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    i++;
                }
                else if (i == text.find("Dw", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.y = arrow_point.y - block_length/cube_size;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("D2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("d2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 3*(block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("D", i))
                { 
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                }
                else if (i == text.find("d", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - 3*(block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                        make_right_arrow(arrow_point, cube_size);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                }

                // L moves
                else if (i == text.find("4Lw'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                
                    i += 3;
                }
                else if (i == text.find("4Lw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("3Lw'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                
                    i += 3;
                }
                else if (i == text.find("3Lw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("4Lw", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Lw", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Lw'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                
                    i += 2;
                }
                else if (i == text.find("Lw2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3L'", i))
                {
                    arrow_point.x = rect.x + 5*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2L'", i))
                {
                    arrow_point.x = rect.x + 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3L2", i))
                {
                    arrow_point.x = rect.x + 5*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("2L2", i))
                {
                    arrow_point.x = rect.x + 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3L", i))
                {
                    arrow_point.x = rect.x + 5*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("2L", i))
                {
                    arrow_point.x = rect.x + 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("L'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("l'", i))
                {
                    arrow_point.x = rect.x + 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.x = arrow_point.x - block_length/cube_size;
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                
                    i++;
                }
                else if (i == text.find("Lw", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x + block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("L2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("l2", i))
                {
                    arrow_point.x = rect.x + 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.x = arrow_point.x - block_length/cube_size;
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("L", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                }
                else if (i == text.find("l", i))
                {
                    arrow_point.x = rect.x + 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.x = arrow_point.x - block_length/cube_size;
                        make_down_arrow(arrow_point, cube_size);
                        window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                }

                // R moves
                else if (i == text.find("4Rw'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 3;
                }
                else if (i == text.find("4Rw2", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("3Rw'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 3;
                }
                else if (i == text.find("3Rw2", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 3;
                }
                else if (i == text.find("4Rw", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Rw", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Rw'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Rw2", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3R'", i))
                {
                    arrow_point.x = rect.x + block_length - 5*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2R'", i))
                {
                    arrow_point.x = rect.x + block_length - 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3R2", i))
                {
                    arrow_point.x = rect.x + block_length - 5*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("2R2", i))
                {
                    arrow_point.x = rect.x + block_length - 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3R", i))
                {
                    arrow_point.x = rect.x + block_length - 5*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("2R", i))
                {
                    arrow_point.x = rect.x + block_length - 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("R'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("r'", i))
                {
                    arrow_point.x = rect.x + block_length - 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                        make_down_arrow(arrow_point, cube_size);
                        window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    i++;
                }
                else if (i == text.find("Rw", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = arrow_point.x - block_length/cube_size;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("R2", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("r2", i))
                {
                    arrow_point.x = rect.x + block_length - 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("R", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                }
                else if (i == text.find("r", i))
                {
                    arrow_point.x = rect.x + block_length - 3*(block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    if (cube_size == X3)
                    {
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                }
                
                // F moves
                else if (i == text.find("4Fw'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&wide4_texture);

                    i += 3;
                }
                else if (i == text.find("4Fw2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&wide4_x2_texture);

                    i += 3;
                }
                else if (i == text.find("3Fw'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&wide3_texture);

                    i += 3;
                }
                else if (i == text.find("3Fw2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&wide3_x2_texture);

                    i += 3;
                }
                else if (i == text.find("4Fw", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&wide4_texture);

                    i += 2;
                }
                else if (i == text.find("3Fw", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&wide3_texture);

                    i += 2;
                }
                else if (i == text.find("Fw'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
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

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3F'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&_3_texture);

                    i += 2;
                }
                else if (i == text.find("2F'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
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

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&_3_x2_texture);

                    i += 2;
                }
                else if (i == text.find("2F2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&x2_texture);

                    i += 2;
                }
                else if (i == text.find("3F", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&_3_texture);

                    i++;
                }
                else if (i == text.find("2F", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    i++;
                }
                else if (i == text.find("F'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 3);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    i++;
                }
                else if (i == text.find("f'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    if (cube_size == X3)
                    {
                        make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                        window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    }
                    else
                    {
                        make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_black, radius, 4);
                        window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    }

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    i++;
                }
                else if (i == text.find("Fw", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    i++;
                }
                else if (i == text.find("F2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 3);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("f2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    if (cube_size == X3)
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                        window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    }
                    else
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_black, radius, 4);
                        window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    }

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("F", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 3);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                }
                else if (i == text.find("f", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    if (cube_size == X3)
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                        window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    }
                    else
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_black, radius, 4);
                        window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    }

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                }
                
                // B moves
                else if (i == text.find("4Bw'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide4_texture);

                    i += 3;
                }
                else if (i == text.find("4Bw2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide4_x2_texture);

                    i += 3;
                }
                else if (i == text.find("3Bw'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide3_texture);

                    i += 3;
                }
                else if (i == text.find("3Bw2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide3_x2_texture);

                    i += 3;
                }
                else if (i == text.find("4Bw", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide4_texture);

                    i += 2;
                }
                else if (i == text.find("3Bw", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide3_texture);

                    i += 2;
                }
                else if (i == text.find("Bw'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_wide3_texture);

                    i += 2;
                }
                else if (i == text.find("Bw2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&b2_texture);

                    i += 2;
                }
                else if (i == text.find("3B'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&_3b_texture);

                    i += 2;
                }
                else if (i == text.find("2B'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_texture);

                    i += 2;
                }
                else if (i == text.find("3B2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&_3bx2_texture);

                    i += 2;
                }
                else if (i == text.find("2B2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&b2_texture);

                    i += 2;
                }
                else if (i == text.find("3B", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&_3b_texture);

                    i++;
                }
                else if (i == text.find("2B", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_black, radius, 4);
                    window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_texture);

                    i++;
                }
                else if (i == text.find("B'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 3);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&back_texture);

                    i++;
                }
                else if (i == text.find("b'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    if (cube_size == X3)
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                        window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    }
                    else
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_black, radius, 4);
                        window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    }

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_texture);

                    i++;
                }
                else if (i == text.find("Bw", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_texture);

                    i++;
                }
                else if (i == text.find("B2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 3);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&b2_texture); 

                    i++;
                }
                else if (i == text.find("b2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    if (cube_size == X3)
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                        window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    }
                    else
                    {
                        make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_black, radius, 4);
                        window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    }

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                    window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                    window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&b2_texture);

                    i++;
                }
                else if (i == text.find("B", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point,     SDL_violet, radius, 3);
                    window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&back_texture);
                }
                else if (i == text.find("b", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    if (cube_size == X3)
                    {
                        make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_violet, radius, 4);
                        window->draw_lines(up_arrow,    SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_violet, NUM_ARROW_POINTS, 4, 4);
                    }
                    else
                    {
                        make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_black, radius, 4);
                        window->draw_lines(up_arrow,    SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(right_arrow, SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(down_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                        window->draw_lines(left_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
                    }

                        make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                        window->draw_circle(arrow_point,     SDL_cyan, radius, 2);
                        window->draw_lines(up_arrow,    SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                        window->draw_lines(right_arrow, SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                        window->draw_lines(down_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
                        window->draw_lines(left_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);

                    render_center_text(&back_texture);
                }
                
                // x moves
                else if (i == text.find("x'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    for (int i = 0; i < cube_size - 1; i++)
                    {
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                        make_down_arrow(arrow_point, cube_size);
                        window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                    i++;
                }
                else if (i == text.find("x2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    for (int i = 0; i < cube_size - 1; i++)
                    {
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("x", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    for (int i = 0; i < cube_size - 1; i++)
                    {
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                }
                
                // y moves
                else if (i == text.find("y'", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    
                    for (int i = 0; i < cube_size - 1; i++)
                    {
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                        make_right_arrow(arrow_point, cube_size);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    i++;
                }
                else if (i == text.find("y2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    for (int i = 0; i < cube_size - 1; i++)
                    {
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("y", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    for (int i = 0; i < cube_size - 1; i++)
                    {
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    }
                }
                
                // z moves
                else if (i == text.find("z'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    
                    i++;
                }
                else if (i == text.find("z2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("z", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_up_arrow(arrow_point, cube_size);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;
                    make_right_arrow(arrow_point, cube_size);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_down_arrow(arrow_point, cube_size);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
                    make_left_arrow(arrow_point, cube_size);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                }

                // Slice moves
                else if (i == text.find("M'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size) + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;

                    for (int i = 0; i < cube_size - 2; i++)
                    {
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                    }

                    i++;
                }
                else if (i == text.find("M2", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size) + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size)/2;

                    for (int i = 0; i < cube_size - 2; i++)
                    {
                        make_up_arrow(arrow_point, cube_size);
                        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("M", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size) + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;

                    for (int i = 0; i < cube_size - 2; i++)
                    {
                        make_down_arrow(arrow_point, cube_size);
                        window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                        arrow_point.x = arrow_point.x + block_length/cube_size;
                    }
                }
                else if (i == text.find("E'", i))
                {
                    arrow_point.x = rect.x + (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size) + (block_length/cube_size)/2;

                    for (int i = 0; i < cube_size - 2; i++)
                    { 
                        make_left_arrow(arrow_point, cube_size);
                        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                    }

                    i++;
                }
                else if (i == text.find("E2", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size) + (block_length/cube_size)/2;

                    for (int i = 0; i < cube_size - 2; i++)
                    { 
                        make_right_arrow(arrow_point, cube_size);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                    }

                    render_center_text(&x2_texture);

                    i++;
                }
                else if (i == text.find("E", i))
                {
                    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
                    arrow_point.y = rect.y + (block_length/cube_size) + (block_length/cube_size)/2;
                    
                    for (int i = 0; i < cube_size - 2; i++)
                    { 
                        make_right_arrow(arrow_point, cube_size);
                        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                        arrow_point.y = arrow_point.y + block_length/cube_size;
                    }
                }
                else if (i == text.find("S'", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, COUNTER_CLOCKWISE);
                    window->draw_circle(arrow_point, SDL_violet, radius, 3);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&slice_texture);

                    i++;
                }
                else if (i == text.find("S2", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point, SDL_violet, radius, 3);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&s2_texture);

                    i++;
                }
                else if (i == text.find("S", i))
                {
                    arrow_point.x = rect.x + block_length/2;
                    arrow_point.y = rect.y + block_length/2;

                    make_circle_arrows(arrow_point, cube_size, CLOCKWISE);
                    window->draw_circle(arrow_point, SDL_violet, radius, 3);
                    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
                    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

                    render_center_text(&slice_texture);
                }
                
                next_rect();
            }
        }

        void make_up_arrow(SDL_Point up_arrow_point, int cube_size)
        {
            up_arrow[0].x = up_arrow_point.x;
            up_arrow[0].y = up_arrow_point.y + block_length - block_length/(cube_size);

            up_arrow[1].x = up_arrow_point.x;
            up_arrow[1].y = up_arrow_point.y;

            up_arrow[2].x = up_arrow_point.x - 10;
            up_arrow[2].y = up_arrow_point.y + 10;

            up_arrow[3].x = up_arrow_point.x;
            up_arrow[3].y = up_arrow_point.y;

            up_arrow[4].x = up_arrow_point.x + 10;
            up_arrow[4].y = up_arrow_point.y + 10;
        }

        void make_down_arrow(SDL_Point down_arrow_point, int cube_size)
        {
            down_arrow[0].x = down_arrow_point.x;
            down_arrow[0].y = down_arrow_point.y - block_length + block_length/(cube_size);

            down_arrow[1].x = down_arrow_point.x;
            down_arrow[1].y = down_arrow_point.y;

            down_arrow[2].x = down_arrow_point.x - 10;
            down_arrow[2].y = down_arrow_point.y - 10;

            down_arrow[3].x = down_arrow_point.x;
            down_arrow[3].y = down_arrow_point.y;

            down_arrow[4].x = down_arrow_point.x + 10;
            down_arrow[4].y = down_arrow_point.y - 10;
        }

        void make_left_arrow(SDL_Point left_arrow_point, int cube_size)
        {
            left_arrow[0].x = left_arrow_point.x + block_length - block_length/cube_size;
            left_arrow[0].y = left_arrow_point.y;

            left_arrow[1].x = left_arrow_point.x;
            left_arrow[1].y = left_arrow_point.y;

            left_arrow[2].x = left_arrow_point.x + 10;
            left_arrow[2].y = left_arrow_point.y - 10;

            left_arrow[3].x = left_arrow_point.x;
            left_arrow[3].y = left_arrow_point.y;

            left_arrow[4].x = left_arrow_point.x + 10;
            left_arrow[4].y = left_arrow_point.y + 10;
        }

        void make_right_arrow(SDL_Point right_arrow_point, int cube_size)
        {
            right_arrow[0].x = right_arrow_point.x - block_length + block_length/cube_size;
            right_arrow[0].y = right_arrow_point.y;

            right_arrow[1].x = right_arrow_point.x;
            right_arrow[1].y = right_arrow_point.y;

            right_arrow[2].x = right_arrow_point.x - 10;
            right_arrow[2].y = right_arrow_point.y - 10;

            right_arrow[3].x = right_arrow_point.x;
            right_arrow[3].y = right_arrow_point.y;

            right_arrow[4].x = right_arrow_point.x - 10;
            right_arrow[4].y = right_arrow_point.y + 10;
        }

        void make_circle_arrows(SDL_Point center, int cube_size, int clockwise)
        {
            radius = block_length/2 - (block_length/cube_size)/2;

            right_arrow[0].x = center.x;
            right_arrow[0].y = center.y - block_length/2 + (block_length/cube_size)/2;

            right_arrow[1].x = right_arrow[0].x - clockwise*10;
            right_arrow[1].y = right_arrow[0].y - 10;

            right_arrow[2].x = center.x;
            right_arrow[2].y = center.y - block_length/2 + (block_length/cube_size)/2;

            right_arrow[3].x = right_arrow[0].x - clockwise*10;
            right_arrow[3].y = right_arrow[0].y + 10;

            right_arrow[4].x = center.x;
            right_arrow[4].y = center.y - block_length/2 + (block_length/cube_size)/2;



            down_arrow[0].x = center.x + block_length/2 - (block_length/cube_size)/2;
            down_arrow[0].y = center.y;

            down_arrow[1].x = down_arrow[0].x - 10;
            down_arrow[1].y = down_arrow[0].y - clockwise*10;

            down_arrow[2].x = center.x + block_length/2 - (block_length/cube_size)/2;
            down_arrow[2].y = center.y;

            down_arrow[3].x = down_arrow[0].x + 10;
            down_arrow[3].y = down_arrow[0].y - clockwise*10;

            down_arrow[4].x = center.x + block_length/2 - (block_length/cube_size)/2;
            down_arrow[4].y = center.y;



            left_arrow[0].x = center.x;
            left_arrow[0].y = center.y + block_length/2 - (block_length/cube_size)/2;

            left_arrow[1].x = left_arrow[0].x + clockwise*10;
            left_arrow[1].y = left_arrow[0].y + 10;

            left_arrow[2].x = center.x;
            left_arrow[2].y = center.y + block_length/2 - (block_length/cube_size)/2;

            left_arrow[3].x = left_arrow[0].x + clockwise*10;
            left_arrow[3].y = left_arrow[0].y - 10;

            left_arrow[4].x = center.x;
            left_arrow[4].y = center.y + block_length/2 - (block_length/cube_size)/2;



            up_arrow[0].x = center.x - block_length/2 + (block_length/cube_size)/2;
            up_arrow[0].y = center.y;

            up_arrow[1].x = up_arrow[0].x - 10;
            up_arrow[1].y = up_arrow[0].y + clockwise*10;

            up_arrow[2].x = center.x - block_length/2 + (block_length/cube_size)/2;
            up_arrow[2].y = center.y;

            up_arrow[3].x = up_arrow[0].x + 10;
            up_arrow[3].y = up_arrow[0].y + clockwise*10;

            up_arrow[4].x = center.x - block_length/2 + (block_length/cube_size)/2;
            up_arrow[4].y = center.y;
        }

        void render_center_text(TextureText* letter_texture)
        {
            SDL_Rect background = rect;
            background.x = background.x + block_length/2;
            background.y = background.y + block_length/2;
            background.w = FONT_SIZE;
            background.h = FONT_SIZE;
            rect_make_dimensions(&background);
            rect_shiftXY(&background);
            window->fill_rect(SDL_black, background);

            letter_texture->rect.x = rect.x + block_length/2;
            letter_texture->rect.y = rect.y + block_length/2 + 4;
            rect_make_dimensions(&letter_texture->rect);
            rect_shiftXY(&letter_texture->rect);
            letter_texture->create_texture();
            letter_texture->render();
        }
};

#endif // CUBE_H
