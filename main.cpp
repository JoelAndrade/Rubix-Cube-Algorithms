#include "main.h"
#include "cube/cube.h"

#include <SDL_Util.h>

std::string loadText = "Choose your cube";

int mode = MAINMENU;

Uint32 startingTick;
SDL_Event event;

textureText text;
textureText text2x2;
textureText text3x3;
textureText text4x4;
textureText text5x5;
textureText text6x6;
textureText text7x7;

cube myCube; 

SDL_Rect topRect = {0, 0, window.w, window.h - row*(2*lineSpaceing + blockLength)};
SDL_Rect highLightRect = {0, blockLength + 1, window.w/3, (row*(2*lineSpaceing + blockLength))/2};

int getMode(SDL_Rect rect);
void posHighlight(SDL_Rect* rect);

int main(int argc, char* args[]) {
    //Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    myCube.init(loadText);

    text.init(window.renderer, "Fonts/times.ttf", loadText.c_str(), 50, window.w/2, topRect.h/2);
    text2x2.init(window.renderer, "Fonts/times.ttf", "2x2", 100,   window.w/6,   (window.h - topRect.h)/4 + topRect.h);
    text3x3.init(window.renderer, "Fonts/times.ttf", "3x3", 100,   window.w/2,   (window.h - topRect.h)/4 + topRect.h);
    text4x4.init(window.renderer, "Fonts/times.ttf", "4x4", 100, 5*window.w/6,   (window.h - topRect.h)/4 + topRect.h);
    text5x5.init(window.renderer, "Fonts/times.ttf", "5x5", 100,   window.w/6, 3*(window.h - topRect.h)/4 + topRect.h);
    text6x6.init(window.renderer, "Fonts/times.ttf", "6x6", 100,   window.w/2, 3*(window.h - topRect.h)/4 + topRect.h);
    text7x7.init(window.renderer, "Fonts/times.ttf", "7x7", 100, 5*window.w/6, 3*(window.h - topRect.h)/4 + topRect.h);

    // Colors the text textures
    text.color = white;
    text2x2.color = white;
    text3x3.color = white;
    text4x4.color = white;
    text5x5.color = white;
    text6x6.color = white;
    text7x7.color = white;

    // Creates the text tuextures
    text.createTexture(window.renderer);
    text2x2.createTexture(window.renderer);
    text3x3.createTexture(window.renderer);
    text4x4.createTexture(window.renderer);
    text5x5.createTexture(window.renderer);
    text6x6.createTexture(window.renderer);
    text7x7.createTexture(window.renderer);

    // Shift text to be base off the center
    text.rect.shiftXY();
    text2x2.rect.shiftXY();
    text3x3.rect.shiftXY();
    text4x4.rect.shiftXY();
    text5x5.rect.shiftXY();
    text6x6.rect.shiftXY();
    text7x7.rect.shiftXY();

    // Changes menu of the application
    while (mode) {
        if (mode == MAINMENU) {
            mode = mainMenu();
        }
        if (mode != MAINMENU && mode != QUIT) { // this is temporary
            mode = algorithmImages();
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
int mainMenu() {
    int xPos = 0;
    int yPos = 0;
    bool checkSpace;
    bool hold = false;

    text.text = "Choose your cube";
    text.createTexture(window.renderer);
    text.changePos(window.w/2, topRect.h/2);
    text.rect.shiftXY();

    SDL_SetWindowTitle(window.window, "Rubix Cube Algorithm Maker");
    while(true) {
        startingTick = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return QUIT;
            }

            if (event.type == SDL_MOUSEMOTION) {
                highLightRect.x = event.motion.x;
                highLightRect.y = event.motion.y;
                posHighlight(&highLightRect);
                checkSpace = event.motion.y > topRect.h;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    hold = event.button.state;
                }
            }

            if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    hold = event.button.state;
                    if (event.button.y > topRect.h) {
                        return getMode(highLightRect);
                    }
                }

            }
        }

        window.clearRender();

        window.drawRect(&cyan, 3, 3);
        window.drawRect(&cyan, topRect, 2, 2);
        window.drawLine(  window.w/3, topRect.h,   window.w/3, window.h, &cyan, 2, 2);
        window.drawLine(2*window.w/3, topRect.h, 2*window.w/3, window.h, &cyan, 2, 2);
        window.drawLine(0, (window.h - topRect.h)/2 + topRect.h, window.w, (window.h - topRect.h)/2 + topRect.h, &cyan, 2, 2);
        if (checkSpace && hold) {
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

        frameCap(fps, startingTick);
    }
    return QUIT;
}

// Handles drawing algorithms and stuff
int algorithmImages() {
    text.text = "";
    text.createTexture(window.renderer);
    text.changePos(window.w/2, topRect.h/2);
    text.rect.shiftXY();

    SDL_SetWindowTitle(window.window, "Rubix Cube Algorithm Maker");
    SDL_StartTextInput();
    while(true) {
        startingTick = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_StopTextInput();
                return QUIT;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    SDL_StopTextInput();
                    return MAINMENU;
                }

                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (text.text.length() > 0) {
                        text.text.pop_back();
                        text.createTexture(window.renderer); 
                        text.changePos(window.w/2, topRect.h/2);
                        text.rect.shiftXY();     
                    }
                }
                else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) {
                    SDL_SetClipboardText(text.text.c_str());
                }
                else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL) {
                    text.text = SDL_GetClipboardText();
                    text.createTexture(window.renderer);
                    text.changePos(window.w/2, topRect.h/2);
                    text.rect.shiftXY();
                }
            }

            else if (event.type == SDL_TEXTINPUT) {
                if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V'))) {
                    text.text = text.text + event.text.text;
                    text.createTexture(window.renderer);
                    text.changePos(window.w/2, topRect.h/2);
                    text.rect.shiftXY();    
                }
                
            }
        }
        window.clearRender();

        myCube.fixString(text.text, mode);
        myCube.drawCube(mode);

        // TODO: Support 5x5
        // fix a bug with 2F type algorythms
            
        // TODO: Support memory

        window.drawRect(&cyan, 3, 3);
        window.drawRect(&cyan, topRect, 2, 2);
        text.render(window.renderer);

        SDL_RenderPresent(window.renderer);

        frameCap(fps, startingTick);
    }
    SDL_StopTextInput();
    return QUIT;
}

// Returns which mode to switch to after a click
int getMode(SDL_Rect rect) {
    menu menuMatrix[2][3] = {{X2,       X3,       X4},
                             {X5, MAINMENU, MAINMENU}};

    int i = rect.x/rect.w;
    int j = (rect.y - topRect.h)/rect.h;

    return menuMatrix[j][i];
}

// Postisions the highlight rect based on where the user clicked
void posHighlight(SDL_Rect* rect) {
    int i = rect->x / rect->w;
    int j = ((rect->y - topRect.h) / rect->h);

    rect->x = i*rect->w;
    rect->y = j*rect->h + topRect.h;
}
