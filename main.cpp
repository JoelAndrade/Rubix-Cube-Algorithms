#include "main.h"
#include "cube/cube.h"

#include <SDL_Util.h>

std::string loadText = "R R' U U' L L' D D'"; //U2 R2 F R F' U2 R' F R F'";

int mode = X3;

Uint32 startingTick;
SDL_Event event;

auto text = window.loadText();

cube myCube(loadText); 

SDL_Rect topRect = {0, 0, window.w, blockLength};

SDL_Rect testPoint = {500, 500, blockLength, blockLength}; // temp

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    text.setup(window.renderer, "Fonts/times.ttf", myCube.text.c_str(), 50, window.w/2, blockLength/2);
    text.color = white;
    text.createTexture(window.renderer);
    text.rect.shiftXY();

    while (mode) {
        if (mode == MAINMENU) {
            mode = mainMenu();
        }
        if (mode != MAINMENU && mode != QUIT) { // this is temporary
            mode = algorithmImages();
        }
    }
    return 0;
}

int mainMenu() {
    return QUIT;
}

int algorithmImages() {
    SDL_SetWindowTitle(window.window, "Rubix Cube Algorithms");
    SDL_StartTextInput();
    while(true) {
        startingTick = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return QUIT;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (text.text.length() > 0) {
                        text.text.pop_back();
                        text.createTexture(window.renderer); 
                        text.changePos(window.w/2, blockLength/2);
                        text.rect.shiftXY();     
                    }
                }

                else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) {
                    SDL_SetClipboardText(text.text.c_str());
                }

                else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL) {
                    text.text = SDL_GetClipboardText();
                    text.createTexture(window.renderer);
                    text.changePos(window.w/2, blockLength/2);
                    text.rect.shiftXY();
                }
            }

            else if (event.type == SDL_TEXTINPUT) {
                if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V'))) {
                    text.text += event.text.text;
                    text.createTexture(window.renderer);
                    text.changePos(window.w/2, blockLength/2);
                    text.rect.shiftXY();    
                }
                
            }
        }

        frameCap(fps, startingTick);

        window.clearRender();

        myCube.fixString(text.text, mode);
        myCube.drawCube(mode);

        // TODO: add slice moves M, E, S
        // TODO: Support 2x2
        // TODO: Support 4x4
        // TODO: Support 5x5

        // TODO: Make a menu to choose the cube you want
        // TODO: Maybe make a specific algorithm page

        window.drawRect(&cyan, 3, 3);
        window.drawRect(&cyan, topRect, 3, 3);
        text.render(window.renderer);
        SDL_RenderPresent(window.renderer);
    }
    SDL_StopTextInput();
    return QUIT;
}