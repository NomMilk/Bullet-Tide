#pragma once

#include <stdint.h>


struct enemy_data
{
    int move_x, move_y;
    signed short size;
    int prev_x, prev_y;
    int pos_x, pos_y;
};

extern struct enemy_data enemies[10];
extern size_t enemy_amount;

void create_enemy(void);
void enemy_collided(void);
void enemy_movement(void);
