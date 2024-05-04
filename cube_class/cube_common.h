#ifndef CUBE_COMMON_H
#define CUBE_COMMON_H

#include <SDL2/SDL.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#include <iostream>
#include <string.h>

#define NUM_ARROW_POINTS (5)
#define FONT_SIZE (40)

#define CLOCKWISE (1)
#define COUNTER_CLOCKWISE (-1)

#define U_PRIME_COMMON(cube_size) (U_prime(window, right_arrow, rect, (cube_size), block_length, &i))
#define U2_COMMON(cube_size)      (U2(window, left_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define U_COMMON(cube_size)       (U(window, left_arrow, rect, (cube_size), block_length))

#define D_PRIME_COMMON(cube_size) (D_prime(window, left_arrow, rect, (cube_size), block_length, &i))
#define D2_COMMON(cube_size)      (D2(window, left_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define D_COMMON(cube_size)       (D(window, right_arrow, rect, (cube_size), block_length))

#define L_PRIME_COMMON(cube_size) (L_prime(window, up_arrow, rect, (cube_size), block_length, &i))
#define L2_COMMON(cube_size)      (L2(window, down_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define L_COMMON(cube_size)       (L(window, down_arrow, rect, (cube_size), block_length))

#define R_PRIME_COMMON(cube_size) (R_prime(window, down_arrow, rect, (cube_size), block_length, &i))
#define R2_COMMON(cube_size)      (R2(window, up_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define R_COMMON(cube_size)       (R(window, up_arrow, rect, (cube_size), block_length))

#define F_PRIME_COMMON(cube_size) (F_prime(window, right_arrow, down_arrow, left_arrow, up_arrow, rect, (cube_size), block_length, &i))
#define F2_COMMON(cube_size)      (F2(window, right_arrow, down_arrow, left_arrow, up_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define F_COMMON(cube_size)       (F(window, right_arrow, down_arrow, left_arrow, up_arrow, rect, (cube_size), block_length))

#define B_PRIME_COMMON(cube_size) (B_prime(window, right_arrow, down_arrow, left_arrow, up_arrow, &back_texture, rect, (cube_size), block_length, &i))
#define B2_COMMON(cube_size)      (B2(window, right_arrow, down_arrow, left_arrow, up_arrow, &b2_texture, rect, (cube_size), block_length, &i))
#define B_COMMON(cube_size)       (B(window, right_arrow, down_arrow, left_arrow, up_arrow, &back_texture, rect, (cube_size), block_length))

#define X_PRIME_COMMON(cube_size) (x_prime(window, down_arrow, rect, (cube_size), block_length, &i))
#define X2_COMMON(cube_size)      (x2(window, up_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define X_COMMON(cube_size)       (x(window, up_arrow, rect, (cube_size), block_length))

#define Y_PRIME_COMMON(cube_size) (y_prime(window, right_arrow, rect, (cube_size), block_length, &i))
#define Y2_COMMON(cube_size)      (y2(window, left_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define Y_COMMON(cube_size)       (y(window, left_arrow, rect, (cube_size), block_length))

#define Z_PRIME_COMMON(cube_size) (z_prime(window, right_arrow, down_arrow, left_arrow, up_arrow, rect, (cube_size), block_length, &i))
#define Z2_COMMON(cube_size)      (z2(window, right_arrow, down_arrow, left_arrow, up_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define Z_COMMON(cube_size)       (z(window, right_arrow, down_arrow, left_arrow, up_arrow, rect, (cube_size), block_length))

#define M_PRIME_COMMON(cube_size) (M_prime(window, up_arrow, rect, (cube_size), block_length, &i))
#define M2_COMMON(cube_size)      (M2(window, up_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define M_COMMON(cube_size)       (M(window, down_arrow, rect, (cube_size), block_length))

#define E_PRIME_COMMON(cube_size) (E_prime(window, left_arrow, rect, (cube_size), block_length, &i))
#define E2_COMMON(cube_size)      (E2(window, right_arrow, &x2_texture, rect, (cube_size), block_length, &i))
#define E_COMMON(cube_size)       (E(window, right_arrow, rect, (cube_size), block_length))

#define S_PRIME_COMMON(cube_size) (S_prime(window, right_arrow, down_arrow, left_arrow, up_arrow, &slice_texture, rect, (cube_size), block_length, &i))
#define S2_COMMON(cube_size)      (S2(window, right_arrow, down_arrow, left_arrow, up_arrow, &s2_texture, rect, (cube_size), block_length, &i))
#define S_COMMON(cube_size)       (S(window, right_arrow, down_arrow, left_arrow, up_arrow, &slice_texture, rect, (cube_size), block_length))

void draw_rects(Window *window, SDL_Rect *rect, int num_moves, int cube_size, int line_spaceing, int block_length);
void next_rect(Window *window, SDL_Rect *rect, int line_spaceing, int block_length);

void make_up_arrow(SDL_Point *up_arrow, SDL_Point up_arrow_point, int cube_size, int block_length);
void make_down_arrow(SDL_Point *down_arrow, SDL_Point down_arrow_point, int cube_size, int block_length);
void make_left_arrow(SDL_Point *left_arrow, SDL_Point left_arrow_point, int cube_size, int block_length);
void make_right_arrow(SDL_Point *right_arrow, SDL_Point right_arrow_point, int cube_size, int block_length);
void make_circle_arrows(SDL_Point *right_arrow,
                        SDL_Point *down_arrow,
                        SDL_Point *left_arrow, 
                        SDL_Point *up_arrow,
                        int *radius,
                        SDL_Point center,
                        int cube_size, int block_length, int clockwise);

void render_center_text(Window *window, TextureText* letter_texture, SDL_Rect rect, int block_length);

void U_prime(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void U2(Window *window, SDL_Point *left_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void U(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length);

void D_prime(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void D2(Window *window, SDL_Point *left_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void D(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length);

void L_prime(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void L2(Window *window, SDL_Point *down_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void L(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length);

void R_prime(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void R2(Window *window, SDL_Point *up_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void R(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length);

void F_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i);
void F2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *x2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i);
void F(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       SDL_Rect rect,
       int cube_size,
       int block_length);

void B_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             TextureText *back_texture,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i);
void B2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *b2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i);
void B(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       TextureText *back_texture,
       SDL_Rect rect,
       int cube_size,
       int block_length);

void x_prime(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void x2(Window *window, SDL_Point *up_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void x(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length);

void y_prime(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void y2(Window *window, SDL_Point *left_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void y(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length);

void z_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i);
void z2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *x2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i);
void z(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       SDL_Rect rect,
       int cube_size,
       int block_length);

void M_prime(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void M2(Window *window, SDL_Point *up_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void M(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length);

void E_prime(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length, int *i);
void E2(Window *window, SDL_Point *right_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i);
void E(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length);

void S_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             TextureText *slice_texture,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i);
void S2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *s2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i);
void S(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       TextureText *slice_texture,
       SDL_Rect rect,
       int cube_size,
       int block_length);

#endif // CUBE_COMMON_H
