#pragma once

#include <stdint.h>
#include <stdbool.h>


struct enemy_data
{
    int move_x, move_y;
    signed short size;
    int prev_x, prev_y;
    int pos_x, pos_y;
};

extern struct enemy_data enemies[10];
extern size_t enemy_amount;

void clear_enemy(void);
void create_enemy(void);
bool enemy_collided(void);
void enemy_movement(void);
