#include "main.h"
// #include "cube_class/cube_common.h"
#include "cube_mode/algorithm_image.h"

#include <cube_2x2.h>
#include <cube_3x3.h>
#include <cube_4x4.h>
#include <cube_5x5.h>
#include <SDL_Util.h>

#define WINDOW_WIDTH (1280) // 1415, 1280
#define WINDOW_HEIGHT (720) // 875,  720

#define LINE_SPACING (7*(window.h/window.h))
#define BLOCK_LENGTH ((window.w/NUM_COL) - (2*LINE_SPACING))

int mode;

Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Loading Algorithm");
Uint32 starting_tick;
SDL_Event event;

TextureText text;
std::string load_text;
SDL_Rect top_rect = {0, 0, window.w, window.h - NUM_ROW*(2*LINE_SPACING + BLOCK_LENGTH)};

static SDL_Rect highlight_rect = {0, BLOCK_LENGTH + 1, window.w/3, (NUM_ROW*(2*LINE_SPACING + BLOCK_LENGTH))/2};

static int get_mode(SDL_Rect rect);
static void pos_highlight(SDL_Rect* rect);

int main(int argc, char* args[]) 
{
    // Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    mode = Main_Menu;

    // my_cube.init(&window, load_text, FONT_PATH);

    text.init(window.renderer, "Fonts/times.ttf", load_text.c_str(), 50, window.w/2, top_rect.h/2);
    text.color = SDL_white;
    text.create_texture();

    // Changes menu of the application
    while (mode != QUIT) 
    {
        switch (mode)
        {
        case Main_Menu:
            mode = main_menu();
            break;

        case X2:
            mode = algorithm_images<Cube2x2>();
            break;

        case X3:
            mode = algorithm_images<Cube3x3>();
            break;

        case X4:
            mode = algorithm_images<Cube4x4>();
            break;

        case X5:
            mode = algorithm_images<Cube5x5>();
            break;

        case X6:
            mode = Main_Menu;
            // mode = algorithm_images<Cube6x6>();
            break;

        case X7:
            mode = Main_Menu;
            // mode = algorithm_images<Cube7x7>();
            break;

        default:
            break;
        }
    }

    // Clean memory after the aplication closes
    SDL_Quit(); //Closed the SDL program
    IMG_Quit();
    TTF_Quit();
    return 0;
}

// Handes main menu stuff
int main_menu()
{
    TextureText text2x2;
    TextureText text3x3;
    TextureText text4x4;
    TextureText text5x5;
    TextureText text6x6;
    TextureText text7x7;

    text2x2.color = SDL_white;
    text3x3.color = SDL_white;
    text4x4.color = SDL_white;
    text5x5.color = SDL_white;
    text6x6.color = SDL_white;
    text7x7.color = SDL_white;

    text2x2.create_texture();
    text3x3.create_texture();
    text4x4.create_texture();
    text5x5.create_texture();
    text6x6.create_texture();
    text7x7.create_texture();

    text2x2.init(window.renderer, "Fonts/times.ttf", "2x2", 100,   window.w/6,   (window.h - top_rect.h)/4 + top_rect.h);
    text2x2.init(window.renderer, "Fonts/times.ttf", "2x2", 100,   window.w/6,   (window.h - top_rect.h)/4 + top_rect.h);
    text3x3.init(window.renderer, "Fonts/times.ttf", "3x3", 100,   window.w/2,   (window.h - top_rect.h)/4 + top_rect.h);
    text4x4.init(window.renderer, "Fonts/times.ttf", "4x4", 100, 5*window.w/6,   (window.h - top_rect.h)/4 + top_rect.h);
    text5x5.init(window.renderer, "Fonts/times.ttf", "5x5", 100,   window.w/6, 3*(window.h - top_rect.h)/4 + top_rect.h);
    text6x6.init(window.renderer, "Fonts/times.ttf", "6x6", 100,   window.w/2, 3*(window.h - top_rect.h)/4 + top_rect.h);
    text7x7.init(window.renderer, "Fonts/times.ttf", "7x7", 100, 5*window.w/6, 3*(window.h - top_rect.h)/4 + top_rect.h);

    rect_shiftXY(&text2x2.rect);
    rect_shiftXY(&text3x3.rect);
    rect_shiftXY(&text4x4.rect);
    rect_shiftXY(&text5x5.rect);
    rect_shiftXY(&text6x6.rect);
    rect_shiftXY(&text7x7.rect);

    int xPos = 0;
    int yPos = 0;
    bool check_space;
    bool hold = false;

    text.text = "Choose your cube";
    text.create_texture();
    text.change_pos(window.w/2, top_rect.h/2);
    rect_shiftXY(&text.rect);

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
                highlight_rect.x = event.motion.x;
                highlight_rect.y = event.motion.y;
                pos_highlight(&highlight_rect);
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
                        return get_mode(highlight_rect);
                }
            }
        }

        window.clear_render();

        window.draw_rect(SDL_cyan, 3, 3);
        window.draw_rect(SDL_cyan, top_rect, 2, 2);
        window.draw_line(  window.w/3, top_rect.h,   window.w/3, window.h, SDL_cyan, 2, 2);
        window.draw_line(2*window.w/3, top_rect.h, 2*window.w/3, window.h, SDL_cyan, 2, 2);
        window.draw_line(0, (window.h - top_rect.h)/2 + top_rect.h, window.w, (window.h - top_rect.h)/2 + top_rect.h, SDL_cyan, 2, 2);

        if (check_space && hold)
        {
            window.draw_rect(SDL_green, highlight_rect, 2, 2);    
        }

        text.render();
        text2x2.render();
        text3x3.render();
        text4x4.render();
        text5x5.render();
        text6x6.render();
        text7x7.render();

        window.render();

        frame_cap(FPS, starting_tick);
    }

    return QUIT;
}

// Returns which mode to switch to after a click
static int get_mode(SDL_Rect rect)
{
    Mode_t menu_matrix[2][3] = {{X2,        X3,        X4},
                                {X5, Main_Menu, Main_Menu}};

    int i = rect.x/rect.w;
    int j = (rect.y - top_rect.h)/rect.h;

    return menu_matrix[j][i];
}

// Positions the highlight rect based on where the user clicked
static void pos_highlight(SDL_Rect* rect)
{
    int i = rect->x/rect->w;
    int j = (rect->y - top_rect.h)/rect->h;

    rect->x = i*rect->w;
    rect->y = j*rect->h + top_rect.h;
}
