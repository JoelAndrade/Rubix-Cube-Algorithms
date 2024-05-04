#include "cube_common.h"

#include <SDL_CLasses.h>
#include <SDL_Util.h>

void draw_rects(Window *window, SDL_Rect *rect, int num_moves, int cube_size, int line_spaceing, int block_length)
{
    for (int i = 0; i < num_moves; i++)
    {
        window->fill_rect(SDL_green, *rect);
        for (int i = 1; i < cube_size; i++)
        {
            window->draw_line(rect->x + (block_length*i)/cube_size, rect->y, rect->x + (block_length*i)/cube_size, rect->bottomY, SDL_black, 3, 1);
            window->draw_line(rect->x, rect->y + (block_length*i)/cube_size, rect->rightX, rect->y + (block_length*i)/cube_size,  SDL_black, 1, 3);
        }
        window->draw_rect(SDL_blue, *rect, 3, 3);

        next_rect(window, rect, line_spaceing, block_length);
    }
}

void next_rect(Window *window, SDL_Rect *rect, int line_spacing, int block_length)
{
    if (rect->rightX < window->w - line_spacing)
    {
        rect->x = rect->x + block_length + 2*line_spacing;
        rect_make_dimensions(rect);  
    }
    else
    {
        rect->x = line_spacing;
        rect->y = rect->y + block_length + 2*line_spacing;
        rect_make_dimensions(rect);
    }
}

void make_up_arrow(SDL_Point *up_arrow, SDL_Point up_arrow_point, int cube_size, int block_length)
{
    up_arrow[0].x = up_arrow_point.x;
    up_arrow[0].y = up_arrow_point.y + block_length - block_length/(cube_size);

    up_arrow[1].x = up_arrow_point.x;
    up_arrow[1].y = up_arrow_point.y;

    up_arrow[2].x = up_arrow_point.x - 10;
    up_arrow[2].y = up_arrow_point.y + 10;

    up_arrow[3].x = up_arrow_point.x;
    up_arrow[3].y = up_arrow_point.y;

    up_arrow[4].x = up_arrow_point.x + 10;
    up_arrow[4].y = up_arrow_point.y + 10;
}

void make_down_arrow(SDL_Point *down_arrow, SDL_Point down_arrow_point, int cube_size, int block_length)
{
    down_arrow[0].x = down_arrow_point.x;
    down_arrow[0].y = down_arrow_point.y - block_length + block_length/(cube_size);

    down_arrow[1].x = down_arrow_point.x;
    down_arrow[1].y = down_arrow_point.y;

    down_arrow[2].x = down_arrow_point.x - 10;
    down_arrow[2].y = down_arrow_point.y - 10;

    down_arrow[3].x = down_arrow_point.x;
    down_arrow[3].y = down_arrow_point.y;

    down_arrow[4].x = down_arrow_point.x + 10;
    down_arrow[4].y = down_arrow_point.y - 10;
}

void make_left_arrow(SDL_Point *left_arrow, SDL_Point left_arrow_point, int cube_size, int block_length)
{
    left_arrow[0].x = left_arrow_point.x + block_length - block_length/cube_size;
    left_arrow[0].y = left_arrow_point.y;

    left_arrow[1].x = left_arrow_point.x;
    left_arrow[1].y = left_arrow_point.y;

    left_arrow[2].x = left_arrow_point.x + 10;
    left_arrow[2].y = left_arrow_point.y - 10;

    left_arrow[3].x = left_arrow_point.x;
    left_arrow[3].y = left_arrow_point.y;

    left_arrow[4].x = left_arrow_point.x + 10;
    left_arrow[4].y = left_arrow_point.y + 10;
}

void make_right_arrow(SDL_Point *right_arrow, SDL_Point right_arrow_point, int cube_size, int block_length)
{
    right_arrow[0].x = right_arrow_point.x - block_length + block_length/cube_size;
    right_arrow[0].y = right_arrow_point.y;

    right_arrow[1].x = right_arrow_point.x;
    right_arrow[1].y = right_arrow_point.y;

    right_arrow[2].x = right_arrow_point.x - 10;
    right_arrow[2].y = right_arrow_point.y - 10;

    right_arrow[3].x = right_arrow_point.x;
    right_arrow[3].y = right_arrow_point.y;

    right_arrow[4].x = right_arrow_point.x - 10;
    right_arrow[4].y = right_arrow_point.y + 10;
}

void make_circle_arrows(SDL_Point *right_arrow,
                        SDL_Point *down_arrow,
                        SDL_Point *left_arrow, 
                        SDL_Point *up_arrow,
                        int *radius,
                        SDL_Point center,
                        int cube_size, int block_length, int clockwise)
{
    *radius = block_length/2 - (block_length/cube_size)/2;

    right_arrow[0].x = center.x;
    right_arrow[0].y = center.y - block_length/2 + (block_length/cube_size)/2;

    right_arrow[1].x = right_arrow[0].x - clockwise*10;
    right_arrow[1].y = right_arrow[0].y - 10;

    right_arrow[2].x = center.x;
    right_arrow[2].y = center.y - block_length/2 + (block_length/cube_size)/2;

    right_arrow[3].x = right_arrow[0].x - clockwise*10;
    right_arrow[3].y = right_arrow[0].y + 10;

    right_arrow[4].x = center.x;
    right_arrow[4].y = center.y - block_length/2 + (block_length/cube_size)/2;



    down_arrow[0].x = center.x + block_length/2 - (block_length/cube_size)/2;
    down_arrow[0].y = center.y;

    down_arrow[1].x = down_arrow[0].x - 10;
    down_arrow[1].y = down_arrow[0].y - clockwise*10;

    down_arrow[2].x = center.x + block_length/2 - (block_length/cube_size)/2;
    down_arrow[2].y = center.y;

    down_arrow[3].x = down_arrow[0].x + 10;
    down_arrow[3].y = down_arrow[0].y - clockwise*10;

    down_arrow[4].x = center.x + block_length/2 - (block_length/cube_size)/2;
    down_arrow[4].y = center.y;



    left_arrow[0].x = center.x;
    left_arrow[0].y = center.y + block_length/2 - (block_length/cube_size)/2;

    left_arrow[1].x = left_arrow[0].x + clockwise*10;
    left_arrow[1].y = left_arrow[0].y + 10;

    left_arrow[2].x = center.x;
    left_arrow[2].y = center.y + block_length/2 - (block_length/cube_size)/2;

    left_arrow[3].x = left_arrow[0].x + clockwise*10;
    left_arrow[3].y = left_arrow[0].y - 10;

    left_arrow[4].x = center.x;
    left_arrow[4].y = center.y + block_length/2 - (block_length/cube_size)/2;



    up_arrow[0].x = center.x - block_length/2 + (block_length/cube_size)/2;
    up_arrow[0].y = center.y;

    up_arrow[1].x = up_arrow[0].x - 10;
    up_arrow[1].y = up_arrow[0].y + clockwise*10;

    up_arrow[2].x = center.x - block_length/2 + (block_length/cube_size)/2;
    up_arrow[2].y = center.y;

    up_arrow[3].x = up_arrow[0].x + 10;
    up_arrow[3].y = up_arrow[0].y + clockwise*10;

    up_arrow[4].x = center.x - block_length/2 + (block_length/cube_size)/2;
    up_arrow[4].y = center.y;
}

void render_center_text(Window *window, TextureText* letter_texture, SDL_Rect rect, int block_length)
{    
    SDL_Rect background = rect;
    background.x = background.x + block_length/2;
    background.y = background.y + block_length/2;
    background.w = FONT_SIZE;
    background.h = FONT_SIZE;
    rect_make_dimensions(&background);
    rect_shiftXY(&background);
    window->fill_rect(SDL_black, background);

    letter_texture->rect.x = rect.x + block_length/2;
    letter_texture->rect.y = rect.y + block_length/2 + 4;
    rect_make_dimensions(&letter_texture->rect);
    rect_shiftXY(&letter_texture->rect);
    letter_texture->create_texture();
    letter_texture->render();
}

void U_prime(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    *i += 1;
}

void U2(Window *window, SDL_Point *left_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void U(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
}

void D_prime(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    *i += 1;
}

void D2(Window *window, SDL_Point *left_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void D(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
}

void L_prime(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    *i += 1;
}

void L2(Window *window, SDL_Point *down_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void L(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
}

void R_prime(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    *i += 1;
}

void R2(Window *window, SDL_Point *up_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void R(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
}

void F_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                       down_arrow,
                       left_arrow,
                       up_arrow,
                       &radius,
                       arrow_point,
                       cube_size,
                       block_length,
                       COUNTER_CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    *i += 1;
}

void F2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *x2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                       down_arrow,
                       left_arrow,
                       up_arrow,
                       &radius,
                       arrow_point,
                       cube_size,
                       block_length,
                       CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void F(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       SDL_Rect rect,
       int cube_size,
       int block_length)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                       down_arrow,
                       left_arrow,
                       up_arrow,
                       &radius,
                       arrow_point,
                       cube_size,
                       block_length,
                       CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
}

void B_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             TextureText *back_texture,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                        down_arrow,
                        left_arrow,
                        up_arrow,
                        &radius,
                        arrow_point,
                        cube_size,
                        block_length,
                        CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, back_texture, rect, block_length);

    *i += 1;
}

void B2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *b2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                        down_arrow,
                        left_arrow,
                        up_arrow,
                        &radius,
                        arrow_point,
                        cube_size,
                        block_length,
                        COUNTER_CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, b2_texture, rect, block_length); 

    *i += 1;
}

void B(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       TextureText *back_texture,
       SDL_Rect rect,
       int cube_size,
       int block_length)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                        down_arrow,
                        left_arrow,
                        up_arrow,
                        &radius,
                        arrow_point,
                        cube_size,
                        block_length,
                        COUNTER_CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, back_texture, rect, block_length);
}

void x_prime(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    for (int i = 0; i < cube_size - 1; i++)
    {
        arrow_point.x = arrow_point.x + block_length/cube_size;
        make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    }

    *i += 1;
}

void x2(Window *window, SDL_Point *up_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    for (int i = 0; i < cube_size - 1; i++)
    {
        arrow_point.x = arrow_point.x + block_length/cube_size;
        make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    }

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void x(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    for (int i = 0; i < cube_size - 1; i++)
    {
        arrow_point.x = arrow_point.x + block_length/cube_size;
        make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    }
}

void y_prime(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    
    for (int i = 0; i < cube_size - 1; i++)
    {
        arrow_point.y = arrow_point.y + block_length/cube_size;
        make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    }

    *i += 1;
}

void y2(Window *window, SDL_Point *left_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    for (int i = 0; i < cube_size - 1; i++)
    {
        arrow_point.y = arrow_point.y + block_length/cube_size;
        make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    }

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void y(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    for (int i = 0; i < cube_size - 1; i++)
    {
        arrow_point.y = arrow_point.y + block_length/cube_size;
        make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
    }
}

void z_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    *i += 1;
}

void z2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *x2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i)
{
    SDL_Point arrow_point;
    int radius;

            arrow_point.x = rect.x + (block_length/cube_size)/2;
            arrow_point.y = rect.y + (block_length/cube_size)/2;
            make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
            arrow_point.y = rect.y + (block_length/cube_size)/2;
            make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
            arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
            make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            arrow_point.x = rect.x + (block_length/cube_size)/2;
            arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
            make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void z(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       SDL_Rect rect,
       int cube_size,
       int block_length)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;
    make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;
    make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
    window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
}

void M_prime(Window *window, SDL_Point *up_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size) + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;

    for (int i = 0; i < cube_size - 2; i++)
    {
        make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        arrow_point.x = arrow_point.x + block_length/cube_size;
    }

    *i += 1;
}

void M2(Window *window, SDL_Point *up_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size) + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size)/2;

    for (int i = 0; i < cube_size - 2; i++)
    {
        make_up_arrow(up_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        arrow_point.x = arrow_point.x + block_length/cube_size;
    }

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void M(Window *window, SDL_Point *down_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size) + (block_length/cube_size)/2;
    arrow_point.y = rect.y + block_length - (block_length/cube_size)/2;

    for (int i = 0; i < cube_size - 2; i++)
    {
        make_down_arrow(down_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        arrow_point.x = arrow_point.x + block_length/cube_size;
    }
}

void E_prime(Window *window, SDL_Point *left_arrow, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size) + (block_length/cube_size)/2;

    for (int i = 0; i < cube_size - 2; i++)
    { 
        make_left_arrow(left_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        arrow_point.y = arrow_point.y + block_length/cube_size;
    }

    *i += 1;
}

void E2(Window *window, SDL_Point *right_arrow, TextureText *x2_texture, SDL_Rect rect, int cube_size, int block_length, int *i)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size) + (block_length/cube_size)/2;

    for (int i = 0; i < cube_size - 2; i++)
    { 
        make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        arrow_point.y = arrow_point.y + block_length/cube_size;
    }

    render_center_text(window, x2_texture, rect, block_length);

    *i += 1;
}

void E(Window *window, SDL_Point *right_arrow, SDL_Rect rect, int cube_size, int block_length)
{
    SDL_Point arrow_point;

    arrow_point.x = rect.x + block_length - (block_length/cube_size)/2;
    arrow_point.y = rect.y + (block_length/cube_size) + (block_length/cube_size)/2;
    
    for (int i = 0; i < cube_size - 2; i++)
    { 
        make_right_arrow(right_arrow, arrow_point, cube_size, block_length);
        window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        arrow_point.y = arrow_point.y + block_length/cube_size;
    }
}


void S_prime(Window *window,
             SDL_Point *right_arrow,
             SDL_Point *down_arrow,
             SDL_Point *left_arrow,
             SDL_Point *up_arrow,
             TextureText *slice_texture,
             SDL_Rect rect,
             int cube_size,
             int block_length,
             int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                        down_arrow,
                        left_arrow,
                        up_arrow,
                        &radius,
                        arrow_point,
                        cube_size,
                        block_length,
                        COUNTER_CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, slice_texture, rect, block_length);

    *i += 1;
}

void S2(Window *window,
        SDL_Point *right_arrow,
        SDL_Point *down_arrow,
        SDL_Point *left_arrow,
        SDL_Point *up_arrow,
        TextureText *s2_texture,
        SDL_Rect rect,
        int cube_size,
        int block_length,
        int *i)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                        down_arrow,
                        left_arrow,
                        up_arrow,
                        &radius,
                        arrow_point,
                        cube_size,
                        block_length,
                        CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, s2_texture, rect, block_length);

    *i += 1;
}

void S(Window *window,
       SDL_Point *right_arrow,
       SDL_Point *down_arrow,
       SDL_Point *left_arrow,
       SDL_Point *up_arrow,
       TextureText *slice_texture,
       SDL_Rect rect,
       int cube_size,
       int block_length)
{
    SDL_Point arrow_point;
    int radius;

    arrow_point.x = rect.x + block_length/2;
    arrow_point.y = rect.y + block_length/2;

    make_circle_arrows(right_arrow,
                        down_arrow,
                        left_arrow,
                        up_arrow,
                        &radius,
                        arrow_point,
                        cube_size,
                        block_length,
                        CLOCKWISE);
    window->draw_circle(arrow_point, SDL_violet, radius, 3);
    window->draw_lines(up_arrow,     SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(right_arrow,  SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(down_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);
    window->draw_lines(left_arrow,   SDL_violet, NUM_ARROW_POINTS, 3, 3);

    render_center_text(window, slice_texture, rect, block_length);
}
