#include "../main.h"
#include "algorithm_image.h"

#include <cube_2x2.h>
#include <cube_3x3.h>
#include <cube_4x4.h>
#include <cube_5x5.h>
#include <SDL_Util.h>

template <class CubeSize>
int algorithm_images(void)
{
    CubeSize cube;
    cube.init(&window, text.text, FONT_PATH, NUM_ROW, NUM_COL);

    text.text = "";
    text.create_texture();
    text.change_pos(window.w/2, top_rect.h/2);
    rect_shiftXY(&text.rect);

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
                        text.create_texture();
                        text.change_pos(window.w/2, top_rect.h/2);
                        rect_shiftXY(&text.rect);
                    }
                }

                else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
                {
                    SDL_SetClipboardText(text.text.c_str());
                }
                else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
                {
                    text.text = SDL_GetClipboardText();
                    text.create_texture();
                    text.change_pos(window.w/2, top_rect.h/2);
                    rect_shiftXY(&text.rect);
                }
            }

            else if (event.type == SDL_TEXTINPUT)
            {
                if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
                {
                    text.text += event.text.text;
                    text.create_texture();
                    text.change_pos(window.w/2, top_rect.h/2);
                    rect_shiftXY(&text.rect);    
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

        window.clear_render();

        cube.fix_string(text.text);
        cube.draw_cube();

        window.draw_rect(SDL_cyan, 3, 3);
        window.draw_rect(SDL_cyan, top_rect, 2, 2);
        text.render();

        window.render();

        frame_cap(FPS, starting_tick);
    }

    SDL_StopTextInput();
    return QUIT;
}

template int algorithm_images<Cube2x2>(void);
template int algorithm_images<Cube3x3>(void);
template int algorithm_images<Cube4x4>(void);
template int algorithm_images<Cube5x5>(void);
