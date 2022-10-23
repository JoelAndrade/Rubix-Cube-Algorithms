#include <iostream>
#include <string>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_CLasses.h>
#include <SDL_Functions.h>
#include "main.h"
#include <cube.h>

win window("Loading Algorithm", windowWidth, windowHeight);
Uint32 startingTick;
SDL_Event event;

auto text = window.loadText();

cube myCube(loadText); 

int x = 0;
int y = 0;
SDL_Rect rect = {blockLength*x, blockLength*(y+1), blockLength, blockLength};
SDL_Rect topRect = {0, 0, window.w, blockLength};


SDL_Color violet = {255, 0, 255};
SDL_Color green = {0, 255, 0};
SDL_Color blue = {0, 0, 255};
SDL_Color black = {0, 0, 0};


void drawScreen() {
    int x = 0;
    myCube.text = text.text;
    myCube.fixString(mode);
    for (int i = 0; i < myCube.text.length(); ++i) {
        if (myCube.text.find("U'", i)) {
            myCube.Xx3.UPrime();
        }
        else if (myCube.text.find("u'", i)) {
            myCube.Xx3.uPrime();
        }
        else if (myCube.text.find("U2", i)) {
            myCube.Xx3.U2();
        }
        else if (myCube.text.find("U", i)) {
            myCube.Xx3.U();
        }
        else if (myCube.text.find("u", i)) {
            myCube.Xx3.u();
        }

        else if (myCube.text.find("D'", i)) {
            myCube.Xx3.DPrime();
        }
        else if (myCube.text.find("d'", i)) {
            myCube.Xx3.dPrime();
        }
        else if (myCube.text.find("D2", i)) {
            myCube.Xx3.D2();
        }
        else if (myCube.text.find("D", i)) {
            myCube.Xx3.D();
        }
        else if (myCube.text.find("d", i)) {
            myCube.Xx3.d();
        }

        else if (myCube.text.find("L'", i)) {
            myCube.Xx3.LPrime();
        }
        else if (myCube.text.find("l'", i)) {
            myCube.Xx3.lPrime();
        }
        else if (myCube.text.find("L2", i)) {
            myCube.Xx3.L2();
        }
        else if (myCube.text.find("L", i)) {
            myCube.Xx3.L();
        }
        else if (myCube.text.find("l", i)) {
            myCube.Xx3.l();
        }

        else if (myCube.text.find("R'", i)) {
            myCube.Xx3.LPrime();
        }
        else if (myCube.text.find("r'", i)) {
            myCube.Xx3.rPrime();
        }
        else if (myCube.text.find("R2", i)) {
            myCube.Xx3.R2();
        }
        else if (myCube.text.find("R", i)) {
            myCube.Xx3.R();
        }
        else if (myCube.text.find("r", i)) {
            myCube.Xx3.r();
        }
        
        else if (myCube.text.find("F'", i)) {
            myCube.Xx3.FPrime();
        }
        else if (myCube.text.find("f'", i)) {
            myCube.Xx3.fPrime();
        }
        else if (myCube.text.find("F2", i)) {
            myCube.Xx3.F2();
        }
        else if (myCube.text.find("F", i)) {
            myCube.Xx3.F();
        }
        else if (myCube.text.find("f", i)) {
            myCube.Xx3.f();
        }
        
        else if (myCube.text.find("B'", i)) {
            myCube.Xx3.BPrime();
        }
        else if (myCube.text.find("b'", i)) {
            myCube.Xx3.bPrime();
        }
        else if (myCube.text.find("B2", i)) {
            myCube.Xx3.B2();
        }
        else if (myCube.text.find("B", i)) {
            myCube.Xx3.B();
        }
        else if (myCube.text.find("b", i)) {
            myCube.Xx3.b();
        }
        
        else if (myCube.text.find("x'", i)) {
            myCube.Xx3.xPrime();
        }
        else if (myCube.text.find("x2", i)) {
            myCube.Xx3.x2();
        }
        else if (myCube.text.find("x", i)) {
            myCube.Xx3.x();
        }
        
        else if (myCube.text.find("y'", i)) {
            myCube.Xx3.yPrime();
        }
        else if (myCube.text.find("y2", i)) {
            myCube.Xx3.y2();
        }
        else if (myCube.text.find("y", i)) {
            myCube.Xx3.y();
        }
        
        else if (myCube.text.find("z'", i)) {
            myCube.Xx3.zPrime();
        }
        else if (myCube.text.find("z2", i)) {
            myCube.Xx3.z2();
        }
        else if (myCube.text.find("z", i)) {
            myCube.Xx3.z();
        }
        
    }
}

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    std::cout << myCube.text << std::endl;
    myCube.fixString(X3);
    std::cout << myCube.text << std::endl;

    text.setup(window.renderer, "Fonts/times.ttf", myCube.text.c_str(), 50, window.w/2, blockLength/2);
    text.color = {255, 255, 255, 255};
    text.createTexture(window.renderer);
    text.rect.shiftXY();
    std::cout << mode << std::endl;

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

        window.fillRect(&green, rect);
        window.drawLine(rect.x + blockLength/3, rect.y, rect.x + blockLength/3, rect.y + blockLength, &black);
        window.drawLine(rect.x + blockLength*2/3, rect.y, rect.x + blockLength*2/3, rect.y + blockLength, &black);
        window.drawLine(rect.x, rect.y + blockLength/3, rect.x + blockLength, rect.y + blockLength/3, &black);
        window.drawLine(rect.x, rect.y + blockLength*2/3, rect.x + blockLength, rect.y + blockLength*2/3, &black);
        window.drawRect(&violet, rect);
        


        window.drawRect(&violet);
        window.drawRect(&violet, topRect);
        text.render(window.renderer);
        SDL_RenderPresent(window.renderer);
    }
    SDL_StopTextInput();
    return QUIT;
}
        // window.fillRect(&green, rect);        


        // for (int i = 1; i < row; ++i) {
        //     window.drawLine(0, blockLength*i + blockLength/3, window.w, blockLength*i + blockLength/3, &blue);
        //     window.drawLine(0, blockLength*i + blockLength*2/3, window.w, blockLength*i + blockLength*2/3, &blue);
        //     window.drawLine(0, blockLength*i, window.w, blockLength*i, &violet, 3, 3);
        // }
        // for (int i = 0; i < col; ++i) {
        //     window.drawLine(blockLength*i + blockLength/3, blockLength, blockLength*i + blockLength/3, window.h, &blue);
        //     window.drawLine(blockLength*i + blockLength*2/3, blockLength, blockLength*i + blockLength*2/3, window.h, &blue);
        //     window.drawLine(blockLength*i, blockLength, blockLength*i, window.h, &violet, 3, 3);
        // }
        // window.drawRect(&violet, rect, 3, 3);
        // window.drawRect(&violet, 3, 3);        
        // text.render(window.renderer);
