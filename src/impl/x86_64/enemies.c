#include <stdint.h>

#include "print.h"
#include "enemies.h"
#include "player_manager.h"

struct enemy_data enemies[10] = {0};
size_t enemy_amount = 0;

void create_enemy(void)
{
    enemies[enemy_amount++] = (struct enemy_data){ 
        .pos_x = 0,
        .pos_y = 0,
        .prev_x = 0,
        .prev_y = 0,
        .move_x = 1,
        .move_y = 1,
        .size = 2 
    };
}

void enemy_collided(void)
{
    for (size_t I = 0; I < enemy_amount; ++I)
    {
        if(pos_x == enemies[I].pos_x && pos_y == enemies[I].pos_y)
            break;
    }
}

void enemy_movement(void)
{
    for (size_t I = 0; I < enemy_amount; ++I)
    {
        enemies[I].pos_x += enemies[I].move_x;
        enemies[I].pos_y += enemies[I].move_y;

        if(enemies[I].pos_y < 0) enemies[I].pos_y = NUM_ROWS;
        if(enemies[I].pos_y > NUM_ROWS) enemies[I].pos_y = 0;
        if(enemies[I].pos_x < 1) enemies[I].pos_x = NUM_COLS - 1;
        if(enemies[I].pos_x > NUM_COLS - 1) enemies[I].pos_x = 1;

        if(enemies[I].pos_x != enemies[I].prev_x || enemies[I].pos_y != enemies[I].prev_y)
            print_char_specific(' ', enemies[I].prev_x, enemies[I].prev_y);
        print_char_specific_color('V', enemies[I].pos_x, enemies[I].pos_y, PRINT_COLOR_LIGHT_RED, PRINT_COLOR_BLUE);

        enemies[I].prev_x = enemies[I].pos_x;
        enemies[I].prev_y = enemies[I].pos_y;
    }
}