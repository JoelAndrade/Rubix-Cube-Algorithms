#include "main.h"
#include "cube/cube.h"

#include <SDL_Util.h>

std::string load_text = "Choose your cube";

int mode = Main_Menu;

Uint32 starting_tick;
SDL_Event event;

texture_text text;
texture_text text2x2;
texture_text text3x3;
texture_text text4x4;
texture_text text5x5;
texture_text text6x6;
texture_text text7x7;

Cube my_cube; 

SDL_Rect top_rect = {0, 0, window.w, window.h - row*(2*lineSpaceing + blockLength)};
SDL_Rect highLightRect = {0, blockLength + 1, window.w/3, (row*(2*lineSpaceing + blockLength))/2};

static int get_mode(SDL_Rect rect);
static void pos_highlight(SDL_Rect* rect);

int main(int argc, char* args[]) 
{
    //Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    my_cube.init(load_text);

    text.init(window.renderer, "Fonts/times.ttf", load_text.c_str(), 50, window.w/2, top_rect.h/2);
    text2x2.init(window.renderer, "Fonts/times.ttf", "2x2", 100,   window.w/6,   (window.h - top_rect.h)/4 + top_rect.h);
    text3x3.init(window.renderer, "Fonts/times.ttf", "3x3", 100,   window.w/2,   (window.h - top_rect.h)/4 + top_rect.h);
    text4x4.init(window.renderer, "Fonts/times.ttf", "4x4", 100, 5*window.w/6,   (window.h - top_rect.h)/4 + top_rect.h);
    text5x5.init(window.renderer, "Fonts/times.ttf", "5x5", 100,   window.w/6, 3*(window.h - top_rect.h)/4 + top_rect.h);
    text6x6.init(window.renderer, "Fonts/times.ttf", "6x6", 100,   window.w/2, 3*(window.h - top_rect.h)/4 + top_rect.h);
    text7x7.init(window.renderer, "Fonts/times.ttf", "7x7", 100, 5*window.w/6, 3*(window.h - top_rect.h)/4 + top_rect.h);

    // Colors the text textures
    text.color    = white;
    text2x2.color = white;
    text3x3.color = white;
    text4x4.color = white;
    text5x5.color = white;
    text6x6.color = white;
    text7x7.color = white;

    // Creates the text tuextures
    text.create_texture(window.renderer);
    text2x2.create_texture(window.renderer);
    text3x3.create_texture(window.renderer);
    text4x4.create_texture(window.renderer);
    text5x5.create_texture(window.renderer);
    text6x6.create_texture(window.renderer);
    text7x7.create_texture(window.renderer);

    // Shift text to be base off the center
    text.rect.shiftXY();
    text2x2.rect.shiftXY();
    text3x3.rect.shiftXY();
    text4x4.rect.shiftXY();
    text5x5.rect.shiftXY();
    text6x6.rect.shiftXY();
    text7x7.rect.shiftXY();

    // Changes menu of the application
    while (mode) 
    {
        if (mode == Main_Menu) 
        {
            mode = main_menu();
        }
        else if (mode != Main_Menu && mode != QUIT) // this is temporary
        {
            mode = algorithm_images();
        }
    }

    // Clean memory after the aplication closes
    SDL_DestroyWindow(window.window); //This closed the window
    SDL_DestroyRenderer(window.renderer);
    SDL_Quit(); //Closed the SDL program
    IMG_Quit();
    TTF_Quit();
    return 0;
}

// Handes main menu stuff
int main_menu()
{
    int xPos = 0;
    int yPos = 0;
    bool check_space;
    bool hold = false;

    text.text = "Choose your cube";
    text.create_texture(window.renderer);
    text.change_pos(window.w/2, top_rect.h/2);
    text.rect.shiftXY();

    SDL_SetWindowTitle(window.window, "Rubix Cube Algorithm Maker");
    while (true)
    {
        starting_tick = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                return QUIT;

            else if (event.type == SDL_MOUSEMOTION)
            {
                highLightRect.x = event.motion.x;
                highLightRect.y = event.motion.y;
                pos_highlight(&highLightRect);
                check_space = event.motion.y > top_rect.h;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                    hold = event.button.state;
            }

            if (event.type == SDL_MOUSEBUTTONUP)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    hold = event.button.state;
                    if (event.button.y > top_rect.h)
                        return get_mode(highLightRect);
                }
            }
        }

        window.clearRender();

        window.drawRect(&cyan, 3, 3);
        window.drawRect(&cyan, top_rect, 2, 2);
        window.drawLine(  window.w/3, top_rect.h,   window.w/3, window.h, &cyan, 2, 2);
        window.drawLine(2*window.w/3, top_rect.h, 2*window.w/3, window.h, &cyan, 2, 2);
        window.drawLine(0, (window.h - top_rect.h)/2 + top_rect.h, window.w, (window.h - top_rect.h)/2 + top_rect.h, &cyan, 2, 2);

        if (check_space && hold)
        {
            window.drawRect(&green, highLightRect, 2, 2);    
        }

        text.render(window.renderer);
        text2x2.render(window.renderer);
        text3x3.render(window.renderer);
        text4x4.render(window.renderer);
        text5x5.render(window.renderer);
        text6x6.render(window.renderer);
        text7x7.render(window.renderer);

        SDL_RenderPresent(window.renderer);

        frame_cap(fps, starting_tick);
    }

    return QUIT;
}

// Handles drawing algorithms and stuff
int algorithm_images()
{
    text.text = "";
    text.create_texture(window.renderer);
    text.change_pos(window.w/2, top_rect.h/2);
    text.rect.shiftXY();

    SDL_SetWindowTitle(window.window, "Rubix Cube Algorithm Maker");
    SDL_StartTextInput();
    while (true)
    {
        starting_tick = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                SDL_StopTextInput();
                return QUIT;
            }

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    SDL_StopTextInput();
                    return Main_Menu;
                }

                if (event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    if (text.text.length() > 0)
                    {
                        text.text.pop_back();
                        text.create_texture(window.renderer); 
                        text.change_pos(window.w/2, top_rect.h/2);
                        text.rect.shiftXY();     
                    }
                }

                else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
                {
                    SDL_SetClipboardText(text.text.c_str());
                }
                else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
                {
                    text.text = SDL_GetClipboardText();
                    text.create_texture(window.renderer);
                    text.change_pos(window.w/2, top_rect.h/2);
                    text.rect.shiftXY();
                }
            }

            else if (event.type == SDL_TEXTINPUT)
            {
                if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
                {
                    text.text = text.text + event.text.text;
                    text.create_texture(window.renderer);
                    text.change_pos(window.w/2, top_rect.h/2);
                    text.rect.shiftXY();    
                }
            }

            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    SDL_StopTextInput();
                    return Main_Menu;
                }
            }
        }

        window.clearRender();

        my_cube.fixString(text.text, mode);
        my_cube.drawCube(mode);

        window.drawRect(&cyan, 3, 3);
        window.drawRect(&cyan, top_rect, 2, 2);
        text.render(window.renderer);

        SDL_RenderPresent(window.renderer);

        frame_cap(fps, starting_tick);
    }

    SDL_StopTextInput();
    return QUIT;
}

// Returns which mode to switch to after a click
static int get_mode(SDL_Rect rect)
{
    menu menu_matrix[2][3] = {{X2,        X3,        X4},
                             {X5, Main_Menu, Main_Menu}};

    int i = rect.x/rect.w;
    int j = (rect.y - top_rect.h)/rect.h;

    return menu_matrix[j][i];
}

// Postisions the highlight rect based on where the user clicked
static void pos_highlight(SDL_Rect* rect)
{
    int i = rect->x / rect->w;
    int j = ((rect->y - top_rect.h) / rect->h);

    rect->x = i*rect->w;
    rect->y = j*rect->h + top_rect.h;
}

// TODO:
// 4x4 is fixed as far as i can tell
// 5x5 need to check if 5x5 is working correctly
    
// TODO: Support memory
