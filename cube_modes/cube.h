#ifndef CUBE_H
#define CUBE_H

#include <SDL2/SDL.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#include <iostream>
#include <string.h>

#define WINDOW_WIDTH (1280) //1415, 1280
#define WINDOW_HEIGHT (720) //875, 720
#define LINE_SPACING (7)
#define BLOCK_LENGTH ((WINDOW_WIDTH/NUM_COL) - (2*LINE_SPACING))

#define CLOCKWISE (1)
#define COUNTER_CLOCKWISE (-1)

#define fontPath ("Fonts/Agane 55 (roman).ttf")

class Cube
{
    public:
        Window *window = NULL;

        SDL_Rect rect;
        std::string text;
        
        TextureText x2Texture;
        TextureText backTexture;
        TextureText b2Texture;
        TextureText _3bTexture;
        TextureText _3bx2Texture;
        TextureText sliceTexture;
        TextureText s2Texture;
        TextureText wide3Texture;
        TextureText wide3_x2Texture;
        TextureText backWide3Texture;
        TextureText backWide3_x2Texture;
        TextureText _3Texture;
        TextureText _3x2Texture;
        TextureText wide4Texture;
        TextureText wide4_x2Texture;
        TextureText backWide4Texture;
        TextureText backWide4_x2Texture;
        
        Cube()
        {}
        Cube(Window *window, std::string text)
        {
            this->window = window;
            this->text = text;
        }

        void init(Window *window, std::string text)
        {
            this->window = window;
            this->text = text;

            x2Texture.init(window->renderer,           fontPath, "x2",    fontSize - 10);
            backTexture.init(window->renderer,         fontPath, "B",     fontSize);
            b2Texture.init(window->renderer,           fontPath, "Bx2",   fontSize - 20);
            _3bTexture.init(window->renderer,          fontPath, "3B",    fontSize - 10);
            _3bx2Texture.init(window->renderer,        fontPath, "3Bx2",  fontSize - 24);
            sliceTexture.init(window->renderer,        fontPath, "S",     fontSize);
            s2Texture.init(window->renderer,           fontPath, "S2",    fontSize - 10);
            wide3Texture.init(window->renderer,        fontPath, "3w",    fontSize - 11);
            wide3_x2Texture.init(window->renderer,     fontPath, "3wx2",  fontSize - 24);
            backWide3Texture.init(window->renderer,    fontPath, "B3w",   fontSize - 20);
            backWide3_x2Texture.init(window->renderer, fontPath, "B3wx2", fontSize - 27);
            _3Texture.init(window->renderer,           fontPath, "3",     fontSize);
            _3x2Texture.init(window->renderer,         fontPath, "3x2",   fontSize - 20);
            wide4Texture.init(window->renderer,        fontPath, "4w",    fontSize - 11);
            wide4_x2Texture.init(window->renderer,     fontPath, "4wx2",  fontSize - 24);
            backWide4Texture.init(window->renderer,    fontPath, "B4w",   fontSize - 20);
            backWide4_x2Texture.init(window->renderer, fontPath, "B4wx2", fontSize - 27);
            
            x2Texture.change_color(SDL_white);
            backTexture.change_color(SDL_white);
            b2Texture.change_color(SDL_white);
            _3bTexture.change_color(SDL_white);
            _3bx2Texture.change_color(SDL_white);
            sliceTexture.change_color(SDL_white);
            s2Texture.change_color(SDL_white);
            wide3Texture.change_color(SDL_white);
            wide3_x2Texture.change_color(SDL_white);
            backWide3Texture.change_color(SDL_white);
            backWide3_x2Texture.change_color(SDL_white);
            _3Texture.change_color(SDL_white);
            _3x2Texture.change_color(SDL_white);
            wide4Texture.change_color(SDL_white);
            wide4_x2Texture.change_color(SDL_white);
            backWide4Texture.change_color(SDL_white);
            backWide4_x2Texture.change_color(SDL_white);
        }

        // Fixes the string for the given cube size
        void fixString(std::string fixText, int cubeSize)
        {
            text = fixText;
            if (cubeSize == X2)
            {
                for (int i = 0; i < text.length(); ++i)
                {
                    if (!(text[i] == 'U' || text[i] == 'D'
                       || text[i] == 'L' || text[i] == 'R'
                       || text[i] == 'F' || text[i] == 'B'
                       || text[i] == 'x' || text[i] == 'y' || text[i] == 'z' 
                       || text[i] == '\'' || text[i] == '2')) 
                       {
                        text.erase(i, 1);
                        --i;
                       }

                }
            }
            else if (cubeSize == X3)
            {
                for (int i = 0; i < text.length(); ++i)
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
            else if (cubeSize == X4)
            {
                for (int i = 0; i < text.length(); ++i)
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
            else if (cubeSize == X5)
            {
                for (int i = 0; i < text.length(); ++i)
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

            switch (cubeSize)
            {
            case X2:
                // Checkout that ' and 2 are not in the front of string
                while (text[0] == '\'' || text[0] == '2')
                {
                    text.erase(0, 1);
                }

                for (int i = 0; i < text.length(); ++i)
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

                for (int i = 0; i < text.length(); ++i)
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
                    for (int i = 0; i < text.length(); ++i)
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
                    for (int i = 0; i < text.length(); ++i)
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
            // std::cout << text << std::endl;
        }

        // Fills the square and and adds the lines
        void drawCube(int cubeSize)
        {
            rect = {line_spaceing, window->h - NUM_ROW*(2*line_spaceing + BLOCK_LENGTH) + line_spaceing, BLOCK_LENGTH, BLOCK_LENGTH};
            rect_make_dimensions(&rect);

            int numMoves = text.length();
            for (int i = 0; i < text.length(); ++i)
            {
                if (text[i] == '\'' || text[i] == '2' || text[i] == 'w' || text[i] == '3' || text[i] == '4')
                {
                    --numMoves;
                }               
            }

            for (int i = 0; i < numMoves; ++i)
            {
                window->fill_rect(SDL_green, rect);
                for (int i = 1; i < cubeSize; ++i)
                {
                    window->draw_line(rect.x + (BLOCK_LENGTH*i)/cubeSize, rect.y, rect.x + (BLOCK_LENGTH*i)/cubeSize, rect.bottomY, SDL_black, 3, 1);
                    window->draw_line(rect.x, rect.y + (BLOCK_LENGTH*i)/cubeSize, rect.rightX, rect.y + (BLOCK_LENGTH*i)/cubeSize,  SDL_black, 1, 3);
                }
                window->draw_rect(SDL_blue, rect, 3, 3);

                nextRect();
            }

            drawArrow(cubeSize);
        }

    private:        
        const int numArrowPoints = 5;
        SDL_Point upArrow[5];
        SDL_Point downArrow[5];
        SDL_Point leftArrow[5];
        SDL_Point rightArrow[5];
        int radius;
        SDL_Point point;
        int fontSize = 40;

        // Set up the next rect to be drawn
        void nextRect()
        {
            if (rect.rightX < window->w - line_spaceing)
            {
                rect.x = rect.x + BLOCK_LENGTH + 2*line_spaceing;
                rect_make_dimensions(&rect);  
            }
            else
            {
                rect.x = line_spaceing;
                rect.y = rect.y + BLOCK_LENGTH + 2*line_spaceing;
                rect_make_dimensions(&rect);
            }
        }

        // Draw arrow on the cube
        void drawArrow(int cubeSize)
        {
            rect = {line_spaceing, window->h - NUM_ROW*(2*line_spaceing + BLOCK_LENGTH) + line_spaceing, BLOCK_LENGTH, BLOCK_LENGTH};
            rect_make_dimensions(&rect);

            for (int i = 0; i < text.length(); ++i)
            {
                // U moves
                if (i == text.find("4Uw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 3;
                }
                else if (i == text.find("4Uw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("3Uw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 3;
                }
                else if (i == text.find("3Uw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("4Uw", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Uw", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Uw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Uw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3U'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 5*(BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2U'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3U2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 5*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("2U2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3U", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 5*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("2U", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("U'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("u'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.y = point.y - (BLOCK_LENGTH/cubeSize);
                        makeRightArrow(point, cubeSize);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("Uw", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y + (BLOCK_LENGTH/cubeSize);
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("U2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("u2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.y = point.y - (BLOCK_LENGTH/cubeSize);
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("U", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("u", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.y = point.y - (BLOCK_LENGTH/cubeSize);
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                }

                // D moves
                else if (i == text.find("4Dw'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 3;
                }
                else if (i == text.find("4Dw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("3Dw'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 3;
                }
                else if (i == text.find("3Dw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("4Dw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Dw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Dw'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Dw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3D'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 5*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2D'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3D2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 5*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("2D2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3D", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 5*(BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("2D", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("D'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("d'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("Dw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.y = point.y - BLOCK_LENGTH/cubeSize;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("D2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("d2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("D", i))
                { 
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("d", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                        makeRightArrow(point, cubeSize);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                }

                // L moves
                else if (i == text.find("4Lw'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                
                    i += 3;
                }
                else if (i == text.find("4Lw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("3Lw'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                
                    i += 3;
                }
                else if (i == text.find("3Lw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("4Lw", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Lw", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Lw'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                
                    i += 2;
                }
                else if (i == text.find("Lw2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3L'", i))
                {
                    point.x = rect.x + 5*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2L'", i))
                {
                    point.x = rect.x + 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3L2", i))
                {
                    point.x = rect.x + 5*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("2L2", i))
                {
                    point.x = rect.x + 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3L", i))
                {
                    point.x = rect.x + 5*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("2L", i))
                {
                    point.x = rect.x + 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("L'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("l'", i))
                {
                    point.x = rect.x + 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.x = point.x - BLOCK_LENGTH/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                
                    ++i;
                }
                else if (i == text.find("Lw", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x + BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("L2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("l2", i))
                {
                    point.x = rect.x + 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.x = point.x - BLOCK_LENGTH/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("L", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("l", i))
                {
                    point.x = rect.x + 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.x = point.x - BLOCK_LENGTH/cubeSize;
                        makeDownArrow(point, cubeSize);
                        window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                }

                // R moves
                else if (i == text.find("4Rw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 3;
                }
                else if (i == text.find("4Rw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("3Rw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 3;
                }
                else if (i == text.find("3Rw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 3;
                }
                else if (i == text.find("4Rw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3Rw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Rw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("Rw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3R'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 5*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("2R'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    i += 2;
                }
                else if (i == text.find("3R2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 5*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("2R2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3R", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 5*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("2R", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("R'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("r'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                        makeDownArrow(point, cubeSize);
                        window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("Rw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = point.x - BLOCK_LENGTH/cubeSize;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("R2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("r2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("R", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("r", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - 3*(BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    if (cubeSize == X3)
                    {
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                }
                
                // F moves
                else if (i == text.find("4Fw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&wide4Texture);

                    i += 3;
                }
                else if (i == text.find("4Fw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&wide4_x2Texture);

                    i += 3;
                }
                else if (i == text.find("3Fw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&wide3Texture);

                    i += 3;
                }
                else if (i == text.find("3Fw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&wide3_x2Texture);

                    i += 3;
                }
                else if (i == text.find("4Fw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&wide4Texture);

                    i += 2;
                }
                else if (i == text.find("3Fw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&wide3Texture);

                    i += 2;
                }
                else if (i == text.find("Fw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    i += 2;
                }
                else if (i == text.find("Fw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3F'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&_3Texture);

                    i += 2;
                }
                else if (i == text.find("2F'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    i += 2;
                }
                else if (i == text.find("3F2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&_3x2Texture);

                    i += 2;
                }
                else if (i == text.find("2F2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&x2Texture);

                    i += 2;
                }
                else if (i == text.find("3F", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&_3Texture);

                    ++i;
                }
                else if (i == text.find("2F", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    ++i;
                }
                else if (i == text.find("F'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 3);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 3, 3);

                    ++i;
                }
                else if (i == text.find("f'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    if (cubeSize == X3)
                    {
                        makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                        window->draw_circle(point,     SDL_violet, radius, 4);
                        window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);
                    }
                    else
                    {
                        makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                        window->draw_circle(point,     SDL_black, radius, 4);
                        window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);
                    }

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    ++i;
                }
                else if (i == text.find("Fw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    ++i;
                }
                else if (i == text.find("F2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 3);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("f2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    if (cubeSize == X3)
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_violet, radius, 4);
                        window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);
                    }
                    else
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_black, radius, 4);
                        window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);
                    }

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("F", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 3);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 3, 3);
                }
                else if (i == text.find("f", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    if (cubeSize == X3)
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_violet, radius, 4);
                        window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);
                    }
                    else
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_black, radius, 4);
                        window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);
                    }

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);
                }
                
                // B moves
                else if (i == text.find("4Bw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide4Texture);

                    i += 3;
                }
                else if (i == text.find("4Bw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide4_x2Texture);

                    i += 3;
                }
                else if (i == text.find("3Bw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide3Texture);

                    i += 3;
                }
                else if (i == text.find("3Bw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide3_x2Texture);

                    i += 3;
                }
                else if (i == text.find("4Bw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide4Texture);

                    i += 2;
                }
                else if (i == text.find("3Bw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide3Texture);

                    i += 2;
                }
                else if (i == text.find("Bw'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backWide3Texture);

                    i += 2;
                }
                else if (i == text.find("Bw2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&b2Texture);

                    i += 2;
                }
                else if (i == text.find("3B'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&_3bTexture);

                    i += 2;
                }
                else if (i == text.find("2B'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);

                    i += 2;
                }
                else if (i == text.find("3B2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&_3bx2Texture);

                    i += 2;
                }
                else if (i == text.find("2B2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&b2Texture);

                    i += 2;
                }
                else if (i == text.find("3B", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&_3bTexture);

                    ++i;
                }
                else if (i == text.find("2B", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_black, radius, 4);
                    window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);

                    ++i;
                }
                else if (i == text.find("B'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 3);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&backTexture);

                    ++i;
                }
                else if (i == text.find("b'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    if (cubeSize == X3)
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_violet, radius, 4);
                        window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);
                    }
                    else
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_black, radius, 4);
                        window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);
                    }

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);

                    ++i;
                }
                else if (i == text.find("Bw", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 4);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);

                    ++i;
                }
                else if (i == text.find("B2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 3);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&b2Texture); 

                    ++i;
                }
                else if (i == text.find("b2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    if (cubeSize == X3)
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_violet, radius, 4);
                        window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);
                    }
                    else
                    {
                        makeCircleArrows(point, cubeSize, CLOCKWISE);
                        window->draw_circle(point,     SDL_black, radius, 4);
                        window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);
                    }

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point,     SDL_cyan, radius, 2);
                    window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                    window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&b2Texture);

                    ++i;
                }
                else if (i == text.find("B", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point,     SDL_violet, radius, 3);
                    window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&backTexture);
                }
                else if (i == text.find("b", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    if (cubeSize == X3)
                    {
                        makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                        window->draw_circle(point,     SDL_violet, radius, 4);
                        window->draw_lines(upArrow,    SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_violet, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_violet, numArrowPoints, 4, 4);
                    }
                    else
                    {
                        makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                        window->draw_circle(point,     SDL_black, radius, 4);
                        window->draw_lines(upArrow,    SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(rightArrow, SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(downArrow,  SDL_black, numArrowPoints, 4, 4);
                        window->draw_lines(leftArrow,  SDL_black, numArrowPoints, 4, 4);
                    }

                        makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                        window->draw_circle(point,     SDL_cyan, radius, 2);
                        window->draw_lines(upArrow,    SDL_cyan, numArrowPoints, 2, 2);
                        window->draw_lines(rightArrow, SDL_cyan, numArrowPoints, 2, 2);
                        window->draw_lines(downArrow,  SDL_cyan, numArrowPoints, 2, 2);
                        window->draw_lines(leftArrow,  SDL_cyan, numArrowPoints, 2, 2);

                    renderCenterText(&backTexture);
                }
                
                // x moves
                else if (i == text.find("x'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i)
                    {
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                        makeDownArrow(point, cubeSize);
                        window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                    ++i;
                }
                else if (i == text.find("x2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i)
                    {
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("x", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i)
                    {
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                }
                
                // y moves
                else if (i == text.find("y'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    
                    for (int i = 0; i < cubeSize - 1; ++i)
                    {
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                        makeRightArrow(point, cubeSize);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    ++i;
                }
                else if (i == text.find("y2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i)
                    {
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("y", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    for (int i = 0; i < cubeSize - 1; ++i)
                    {
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                    }
                }
                
                // z moves
                else if (i == text.find("z'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    
                    ++i;
                }
                else if (i == text.find("z2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("z", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeUpArrow(point, cubeSize);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;
                    makeRightArrow(point, cubeSize);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeDownArrow(point, cubeSize);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);

                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    makeLeftArrow(point, cubeSize);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                }

                // Slice moves
                else if (i == text.find("M'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize) + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i)
                    {
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                    }

                    ++i;
                }
                else if (i == text.find("M2", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize) + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i)
                    {
                        makeUpArrow(point, cubeSize);
                        window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("M", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize) + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i)
                    {
                        makeDownArrow(point, cubeSize);
                        window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                        point.x = point.x + BLOCK_LENGTH/cubeSize;
                    }
                }
                else if (i == text.find("E'", i))
                {
                    point.x = rect.x + (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize) + (BLOCK_LENGTH/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i)
                    { 
                        makeLeftArrow(point, cubeSize);
                        window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                    }

                    ++i;
                }
                else if (i == text.find("E2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize) + (BLOCK_LENGTH/cubeSize)/2;

                    for (int i = 0; i < cubeSize - 2; ++i)
                    { 
                        makeRightArrow(point, cubeSize);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                    }

                    renderCenterText(&x2Texture);

                    ++i;
                }
                else if (i == text.find("E", i))
                {
                    point.x = rect.x + BLOCK_LENGTH - (BLOCK_LENGTH/cubeSize)/2;
                    point.y = rect.y + (BLOCK_LENGTH/cubeSize) + (BLOCK_LENGTH/cubeSize)/2;
                    
                    for (int i = 0; i < cubeSize - 2; ++i)
                    { 
                        makeRightArrow(point, cubeSize);
                        window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                        point.y = point.y + BLOCK_LENGTH/cubeSize;
                    }
                }
                else if (i == text.find("S'", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, COUNTER_CLOCKWISE);
                    window->draw_circle(point, SDL_violet, radius, 3);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&sliceTexture);

                    ++i;
                }
                else if (i == text.find("S2", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point, SDL_violet, radius, 3);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&s2Texture);

                    ++i;
                }
                else if (i == text.find("S", i))
                {
                    point.x = rect.x + BLOCK_LENGTH/2;
                    point.y = rect.y + BLOCK_LENGTH/2;

                    makeCircleArrows(point, cubeSize, CLOCKWISE);
                    window->draw_circle(point, SDL_violet, radius, 3);
                    window->draw_lines(upArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(rightArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(downArrow, SDL_violet, numArrowPoints, 3, 3);
                    window->draw_lines(leftArrow, SDL_violet, numArrowPoints, 3, 3);

                    renderCenterText(&sliceTexture);
                }
                
                nextRect();
            }
        }

        void makeUpArrow(SDL_Point upArrowPoint, int cubeSize)
        {
            upArrow[0].x = upArrowPoint.x;
            upArrow[0].y = upArrowPoint.y + BLOCK_LENGTH - BLOCK_LENGTH/(cubeSize);

            upArrow[1].x = upArrowPoint.x;
            upArrow[1].y = upArrowPoint.y;

            upArrow[2].x = upArrowPoint.x - 10;
            upArrow[2].y = upArrowPoint.y + 10;

            upArrow[3].x = upArrowPoint.x;
            upArrow[3].y = upArrowPoint.y;

            upArrow[4].x = upArrowPoint.x + 10;
            upArrow[4].y = upArrowPoint.y + 10;
        }

        void makeDownArrow(SDL_Point downArrowPoint, int cubeSize)
        {
            downArrow[0].x = downArrowPoint.x;
            downArrow[0].y = downArrowPoint.y - BLOCK_LENGTH + BLOCK_LENGTH/(cubeSize);

            downArrow[1].x = downArrowPoint.x;
            downArrow[1].y = downArrowPoint.y;

            downArrow[2].x = downArrowPoint.x - 10;
            downArrow[2].y = downArrowPoint.y - 10;

            downArrow[3].x = downArrowPoint.x;
            downArrow[3].y = downArrowPoint.y;

            downArrow[4].x = downArrowPoint.x + 10;
            downArrow[4].y = downArrowPoint.y - 10;
        }

        void makeLeftArrow(SDL_Point leftArrowPoint, int cubeSize)
        {
            leftArrow[0].x = leftArrowPoint.x + BLOCK_LENGTH - BLOCK_LENGTH/cubeSize;
            leftArrow[0].y = leftArrowPoint.y;

            leftArrow[1].x = leftArrowPoint.x;
            leftArrow[1].y = leftArrowPoint.y;

            leftArrow[2].x = leftArrowPoint.x + 10;
            leftArrow[2].y = leftArrowPoint.y - 10;

            leftArrow[3].x = leftArrowPoint.x;
            leftArrow[3].y = leftArrowPoint.y;

            leftArrow[4].x = leftArrowPoint.x + 10;
            leftArrow[4].y = leftArrowPoint.y + 10;
        }

        void makeRightArrow(SDL_Point rightArrowPoint, int cubeSize)
        {
            rightArrow[0].x = rightArrowPoint.x - BLOCK_LENGTH + BLOCK_LENGTH/cubeSize;
            rightArrow[0].y = rightArrowPoint.y;

            rightArrow[1].x = rightArrowPoint.x;
            rightArrow[1].y = rightArrowPoint.y;

            rightArrow[2].x = rightArrowPoint.x - 10;
            rightArrow[2].y = rightArrowPoint.y - 10;

            rightArrow[3].x = rightArrowPoint.x;
            rightArrow[3].y = rightArrowPoint.y;

            rightArrow[4].x = rightArrowPoint.x - 10;
            rightArrow[4].y = rightArrowPoint.y + 10;
        }

        void makeCircleArrows(SDL_Point center, int cubeSize, int clockwise = 1)
        {
            radius = BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;

            rightArrow[0].x = center.x;
            rightArrow[0].y = center.y - BLOCK_LENGTH/2 + (BLOCK_LENGTH/cubeSize)/2;

            rightArrow[1].x = rightArrow[0].x - clockwise*10;
            rightArrow[1].y = rightArrow[0].y - 10;

            rightArrow[2].x = center.x;
            rightArrow[2].y = center.y - BLOCK_LENGTH/2 + (BLOCK_LENGTH/cubeSize)/2;

            rightArrow[3].x = rightArrow[0].x - clockwise*10;
            rightArrow[3].y = rightArrow[0].y + 10;

            rightArrow[4].x = center.x;
            rightArrow[4].y = center.y - BLOCK_LENGTH/2 + (BLOCK_LENGTH/cubeSize)/2;



            downArrow[0].x = center.x + BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;
            downArrow[0].y = center.y;

            downArrow[1].x = downArrow[0].x - 10;
            downArrow[1].y = downArrow[0].y - clockwise*10;

            downArrow[2].x = center.x + BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;
            downArrow[2].y = center.y;

            downArrow[3].x = downArrow[0].x + 10;
            downArrow[3].y = downArrow[0].y - clockwise*10;

            downArrow[4].x = center.x + BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;
            downArrow[4].y = center.y;



            leftArrow[0].x = center.x;
            leftArrow[0].y = center.y + BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;

            leftArrow[1].x = leftArrow[0].x + clockwise*10;
            leftArrow[1].y = leftArrow[0].y + 10;

            leftArrow[2].x = center.x;
            leftArrow[2].y = center.y + BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;

            leftArrow[3].x = leftArrow[0].x + clockwise*10;
            leftArrow[3].y = leftArrow[0].y - 10;

            leftArrow[4].x = center.x;
            leftArrow[4].y = center.y + BLOCK_LENGTH/2 - (BLOCK_LENGTH/cubeSize)/2;



            upArrow[0].x = center.x - BLOCK_LENGTH/2 + (BLOCK_LENGTH/cubeSize)/2;
            upArrow[0].y = center.y;

            upArrow[1].x = upArrow[0].x - 10;
            upArrow[1].y = upArrow[0].y + clockwise*10;

            upArrow[2].x = center.x - BLOCK_LENGTH/2 + (BLOCK_LENGTH/cubeSize)/2;
            upArrow[2].y = center.y;

            upArrow[3].x = upArrow[0].x + 10;
            upArrow[3].y = upArrow[0].y + clockwise*10;

            upArrow[4].x = center.x - BLOCK_LENGTH/2 + (BLOCK_LENGTH/cubeSize)/2;
            upArrow[4].y = center.y;
        }

        void renderCenterText(TextureText* letterTexture)
        {
            SDL_Rect background = rect;
            background.x = background.x + BLOCK_LENGTH/2;
            background.y = background.y + BLOCK_LENGTH/2;
            background.w = fontSize;
            background.h = fontSize;
            rect_make_dimensions(&background);
            rect_shiftXY(&background);
            window->fill_rect(SDL_black, background);

            letterTexture->rect.x = rect.x + BLOCK_LENGTH/2;
            letterTexture->rect.y = rect.y + BLOCK_LENGTH/2 + 4;
            rect_make_dimensions(&letterTexture->rect);
            rect_shiftXY(&letterTexture->rect);
            letterTexture->create_texture();
            letterTexture->render();
        }
};

#endif // CUBE_H
