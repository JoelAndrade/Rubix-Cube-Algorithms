#ifndef SDL_UTIL_H
#define SDL_UTIL_H

#include <SDL2/SDL.h>

SDL_Color violet = {255, 0, 255};
SDL_Color green = {0, 255, 0};
SDL_Color red = {255, 0, 0};
SDL_Color cyan = {0, 150, 225};
SDL_Color blue = {0, 0, 255};
SDL_Color black = {0, 0, 0};
SDL_Color white = {255, 255, 255};

void frameCap(int fps, Uint32 startingTick) {
    if (1000/fps > SDL_GetTicks() - startingTick) {
        SDL_Delay(1000/fps - (SDL_GetTicks() - startingTick));
    }
}

#endif // SDL_UTIL_H