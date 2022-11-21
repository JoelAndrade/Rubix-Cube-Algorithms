#include "main.h"

std::string loadText = "R ";//U2 R2 F R F' U2 R' F R F'";

int mode = X3;

Uint32 startingTick;
SDL_Event event;

auto text = window.loadText();

cube myCube(loadText); 

int x = 0;
int y = 0;
SDL_Rect rect = {blockLength*(x + 2), blockLength*(y + 2), blockLength, blockLength};
SDL_Rect topRect = {0, 0, window.w, blockLength};

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    text.setup(window.renderer, "Fonts/times.ttf", myCube.text.c_str(), 50, window.w/2, blockLength/2);
    text.color = {255, 255, 255, 255};
    text.createTexture(window.renderer);
    text.rect.shiftXY();

    rect.makeDimensions();

    while (mode) {
        if (mode == MAINMENU) {
            mode = mainMenu();
        }
        if (mode != MAINMENU && mode != QUIT) {
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
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    ++x;
                    rect = {blockLength*x, blockLength*(y+1), blockLength, blockLength};
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    ++y;
                    rect = {blockLength*x, blockLength*(y+1), blockLength, blockLength};
                }
                if (event.key.keysym.sym == SDLK_LEFT) {
                    --x;
                    rect = {blockLength*x, blockLength*(y+1), blockLength, blockLength};
                }
                if (event.key.keysym.sym == SDLK_UP) {
                    --y;
                    rect = {blockLength*x, blockLength*(y+1), blockLength, blockLength};
                }
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

        // TODO: make arrow for all possible moves

        window.drawRect(&cyan, 3, 3);
        window.drawRect(&cyan, topRect, 3, 3);
        text.render(window.renderer);
        SDL_RenderPresent(window.renderer);
    }
    SDL_StopTextInput();
    return QUIT;
}