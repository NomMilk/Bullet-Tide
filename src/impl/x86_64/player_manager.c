#include <stdint.h>

#include "player_manager.h"
#include "print.h"

int prev_x = 0, prev_y = 0;
float pos_x = 0.0f, pos_y = 0.0f;

void move_hori(char _input)
{
    if(_input == 'a')
    {
        pos_x -= 0.0001f;
    }
    if(_input == 'd')
    {
        pos_x += 0.0001f;
    }
}

void move_vert(char _input)
{
    if(_input == 'w')
    {
        pos_y -= 0.0001f;
    }

    if(_input == 's')
    {
        pos_y += 0.0001f;
    }
}

void partial_redraw(void)
{
    int result_x = (int)pos_x;
    int result_y= (int)pos_y;

    print_char_specific('X', result_x, result_y);

    if(result_x != prev_x || result_y != prev_y)
        print_char_specific(' ', prev_x, prev_y);

    prev_x = (int)pos_x;
    prev_y = (int)pos_y;

}
