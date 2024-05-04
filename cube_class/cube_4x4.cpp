#include "cube_4x4.h"

#include <SDL_CLasses.h>
#include <SDL_Util.h>

#define CUBE_SIZE_4X4 (4)

Cube4x4::Cube4x4() {}
Cube4x4::Cube4x4(Window *window, std::string text, int row, int col)
{
    this->window = window;
    this->text = text;
    this->row = row;
    this->col = col;
}

void Cube4x4::init(Window *window, std::string text, const char* font_path, int row, int col)
{
    this->window = window;
    this->text = text;
    this->row = row;
    this->col = col;

    line_spacing = 7*(window->h/window->h);
    block_length = (window->w/col) - (2*line_spacing);

    x2_texture.init(window->renderer,    font_path, "x2",  FONT_SIZE - 10);
    back_texture.init(window->renderer,  font_path, "B",   FONT_SIZE);
    b2_texture.init(window->renderer,    font_path, "Bx2", FONT_SIZE - 20);
    slice_texture.init(window->renderer, font_path, "S",   FONT_SIZE);
    s2_texture.init(window->renderer,    font_path, "S2",  FONT_SIZE - 10);

    x2_texture.change_color(SDL_white);
    back_texture.change_color(SDL_white);
    b2_texture.change_color(SDL_white);
    slice_texture.change_color(SDL_white);
    s2_texture.change_color(SDL_white);
}

// Fixes the string for the given cube size
void Cube4x4::fix_string(std::string fix_text)
{
    text = fix_text;
    for (int i = 0; i < text.length(); i++)
    {
        if (!(text[i] == 'U' || text[i] == 'u' ||
              text[i] == 'D' || text[i] == 'd' ||
              text[i] == 'L' || text[i] == 'l' ||
              text[i] == 'R' || text[i] == 'r' ||
              text[i] == 'F' || text[i] == 'f' ||
              text[i] == 'B' || text[i] == 'b' ||
              text[i] == 'x' || text[i] == 'y' || text[i] == 'z' ||
              text[i] == 'M' || text[i] == 'E' || text[i] == 'S' ||
              text[i] == '\''|| text[i] == '2' || text[i] == 'w' ||
              text[i] == '3'))
        {
            text.erase(i, 1);
            i--;
        }
    }

    // Check that ' and w are not in the front of string
    while (text[0] == '\'' || text[0] == 'w')
    {
        text.erase(0, 1);
    }

    // A 2 can not be followed with a 2 or lowercase letter
    while (text[0] == '2' && (text[1] == '2' || LIMITS('a', text[1], 'z')))
    {
        text.erase(0, 1);
    }

    // The second "for loop" is to double check
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < text.length(); i++)
        {

            // Check for trailing w after a w
            while (text[i] == 'w' && text[i + 1] == 'w')
            {
                text.erase(i + 1, 1);
            }

            // Check that w is being used with a capital letter
            while (text[i] == 'w' && !LIMITS('A', text[i - 1], 'Z'))
            {
                text.erase(i, 1);
            }

            // Check that a 3 will follow with a capital letter
            while (text[i] == '3' && (!LIMITS('A', text[i - 1], 'Z')))
            {
                text.erase(i, 1);
            }

            // Check the string doesnt have consecutive 's and w's after an ' or 2
            while ((text[i]     == '\'' || text[i]     == '2') && 
                   (text[i + 1] == '\'' || text[i + 1] == 'w'))
            {
                text.erase(i + 1, 1);
            }

            // Checks that 2's are used correctly
            while ((text[i] == '2' || text[i] == '\'') && text[i + 1] == '2' && !LIMITS('A', text[i + 2], 'Z'))
            {
                text.erase(i + 1, 1);
            }
        }
    }
}

// Fills the square and and adds the lines
void Cube4x4::draw_cube(void)
{
    rect = {
        line_spacing,
        window->h - row*(2*line_spacing + block_length) + line_spacing,
        block_length,
        block_length
    };
    rect_make_dimensions(&rect);

    int num_moves = text.length();
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '\'' || text[i] == '2' || text[i] == 'w' || text[i] == '3')
        {
            num_moves--;
        }               
    }

    draw_rects(window, &rect, num_moves, CUBE_SIZE_4X4, line_spacing, block_length);
    draw_arrows();
}

// Draw arrow on the cube
void Cube4x4::draw_arrows(void)
{
    SDL_Point up_arrow[NUM_ARROW_POINTS];
    SDL_Point down_arrow[NUM_ARROW_POINTS];
    SDL_Point left_arrow[NUM_ARROW_POINTS];
    SDL_Point right_arrow[NUM_ARROW_POINTS];
    SDL_Point arrow_point;
    int radius;

    rect = {
        line_spacing,
        window->h - row*(2*line_spacing + block_length) + line_spacing,
        block_length,
        block_length
    };
    rect_make_dimensions(&rect);

    for (int i = 0; i < text.length(); i++)
    {
        // U moves
        if (i == text.find("U'", i))
        {
            U_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("u'", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + 3*(block_length/CUBE_SIZE_4X4)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("U2", i))
        {
            U2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("u2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + 3*(block_length/CUBE_SIZE_4X4)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("U", i))
        {
            U_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("u", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + 3*(block_length/CUBE_SIZE_4X4)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        }

        // D moves
        else if (i == text.find("D'", i))
        {
            D_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("d'", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + block_length - 3*(block_length/CUBE_SIZE_4X4)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("D2", i))
        {
            D2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("d2", i))
        {
            arrow_point.x = rect.x + (block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + block_length - 3*(block_length/CUBE_SIZE_4X4)/2;
            make_left_arrow(left_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(left_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("D", i))
        { 
            D_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("d", i))
        {
            arrow_point.x = rect.x + block_length - (block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + block_length - 3*(block_length/CUBE_SIZE_4X4)/2;
            make_right_arrow(right_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(right_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        }

        // L moves
        else if (i == text.find("L'", i))
        {
            L_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("l'", i))
        {
            arrow_point.x = rect.x + 3*(block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_4X4)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        
            i++;
        }
        else if (i == text.find("L2", i))
        {
            L2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("l2", i))
        {
            arrow_point.x = rect.x + 3*(block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_4X4)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("L", i))
        {
            L_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("l", i))
        {
            arrow_point.x = rect.x + 3*(block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_4X4)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        }

        // R moves
        else if (i == text.find("R'", i))
        {
            R_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("r'", i))
        {
            arrow_point.x = rect.x + block_length - 3*(block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + block_length - (block_length/CUBE_SIZE_4X4)/2;
            make_down_arrow(down_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(down_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            i++;
        }
        else if (i == text.find("R2", i))
        {
            R2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("r2", i))
        {
            arrow_point.x = rect.x + block_length - 3*(block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_4X4)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);

            render_center_text(window, &x2_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("R", i))
        {
            R_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("r", i))
        {
            arrow_point.x = rect.x + block_length - 3*(block_length/CUBE_SIZE_4X4)/2;
            arrow_point.y = rect.y + (block_length/CUBE_SIZE_4X4)/2;
            make_up_arrow(up_arrow, arrow_point, CUBE_SIZE_4X4, block_length);
            window->draw_lines(up_arrow, SDL_violet, NUM_ARROW_POINTS, 3, 3);
        }
        
        // F moves
        else if (i == text.find("F'", i))
        {
            F_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("f'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point, SDL_black, radius, 4);
            window->draw_lines(up_arrow,     SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point, SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,     SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            i++;
        }
        else if (i == text.find("F2", i))
        {
            F2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("f2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point, SDL_black, radius, 4);
            window->draw_lines(up_arrow,     SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point, SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,     SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &x2_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("F", i))
        {
            F_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("f", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point, SDL_black, radius, 4);
            window->draw_lines(up_arrow,     SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point, SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,     SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
        }
        
        // B moves
        else if (i == text.find("B'", i))
        {
            B_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("b'", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point, SDL_black, radius, 4);
            window->draw_lines(up_arrow,     SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                CLOCKWISE);
            window->draw_circle(arrow_point, SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,     SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_texture, rect, block_length);

            i++;
        }
        else if (i == text.find("B2", i))
        {
            B2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("b2", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point, SDL_black, radius, 4);
            window->draw_lines(up_arrow,     SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point, SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,     SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &b2_texture, rect, block_length); 

            i++;
        }
        else if (i == text.find("B", i))
        {
            B_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("b", i))
        {
            arrow_point.x = rect.x + block_length/2;
            arrow_point.y = rect.y + block_length/2;

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point, SDL_black, radius, 4);
            window->draw_lines(up_arrow,     SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(right_arrow,  SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(down_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);
            window->draw_lines(left_arrow,   SDL_black, NUM_ARROW_POINTS, 4, 4);

            make_circle_arrows(right_arrow,
                                down_arrow,
                                left_arrow,
                                up_arrow,
                                &radius,
                                arrow_point,
                                CUBE_SIZE_4X4,
                                block_length,
                                COUNTER_CLOCKWISE);
            window->draw_circle(arrow_point, SDL_cyan, radius, 2);
            window->draw_lines(up_arrow,     SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(right_arrow,  SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(down_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);
            window->draw_lines(left_arrow,   SDL_cyan, NUM_ARROW_POINTS, 2, 2);

            render_center_text(window, &back_texture, rect, block_length);
        }
        
        // x moves
        else if (i == text.find("x'", i))
        {
            X_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("x2", i))
        {
            X2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("x", i))
        {
            X_COMMON(CUBE_SIZE_4X4);
        }
        
        // y moves
        else if (i == text.find("y'", i))
        {
            Y_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("y2", i))
        {
            Y2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("y", i))
        {
            Y_COMMON(CUBE_SIZE_4X4);
        }
        
        // z moves
        else if (i == text.find("z'", i))
        {
            Z_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("z2", i))
        {
            Z2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("z", i))
        {
            Z_COMMON(CUBE_SIZE_4X4);
        }

        // Slice moves
        else if (i == text.find("M'", i))
        {
            M_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("M2", i))
        {
            M2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("M", i))
        {
            M_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("E'", i))
        {
            E_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("E2", i))
        {
            E2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("E", i))
        {
            E_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("S'", i))
        {
            S_PRIME_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("S2", i))
        {
            S2_COMMON(CUBE_SIZE_4X4);
        }
        else if (i == text.find("S", i))
        {
            S_COMMON(CUBE_SIZE_4X4);
        }

        next_rect(window, &rect, line_spacing, block_length);
    }
}
