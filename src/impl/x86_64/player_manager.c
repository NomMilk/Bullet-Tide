#include <stdint.h>

#include "player_manager.h"
#include "print.h"

int prev_x = 0, prev_y = 0;
int pos_x = 1, pos_y = 1;

int result_x, result_y;

void move_hori(char _input)
{
    if(_input == 'a')
    {
        pos_x -= 2;
    }
    if(_input == 'd')
    {
        pos_x += 2;
    }
}

void move_vert(char _input)
{
    if(_input == 'w')
    {
        pos_y -= 1;
    }

    if(_input == 's')
    {
        pos_y += 1;
    }
}

void partial_redraw(void)
{
    if(pos_y < 0) pos_y = NUM_ROWS;
    if(pos_y > NUM_ROWS) pos_y = 0;
    if(pos_x < 1) pos_x = NUM_COLS - 1;
    if(pos_x > NUM_COLS - 1) pos_x = 1;

    if(pos_x != prev_x || pos_y != prev_y)
        print_char_specific(' ', prev_x, prev_y);
    print_char_specific('X', pos_x, pos_y);

    prev_x = pos_x;
    prev_y = pos_y;
}
