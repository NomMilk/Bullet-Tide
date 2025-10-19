#include <stdint.h>

#include "print.h"
#include "enemies.h"
#include "player_manager.h"
#include "score.h"

struct enemy_data enemies[10] = {0};
size_t enemy_amount = 0;

static inline size_t rdtsc(void)
{
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((size_t)hi << 32) | lo;
}

void clear_enemy()
{
    enemy_amount = 0;

    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE + (score % 8));
    print_clear();
}

void create_enemy(void)
{
    if(enemy_amount >= 9) clear_enemy();
    size_t t = rdtsc();

    enemies[enemy_amount++] = (struct enemy_data){ 
        .pos_x  = (t >> 0)  % 800,
        .pos_y  = (t >> 8)  % 600,
        .prev_x = 0,
        .prev_y = 0,
        .move_x = ((t >> 16) & 1) ? 1 : -1,
        .move_y = ((t >> 17) & 1) ? 1 : -1,
        .size   = ((t >> 24) % 5) + 1,
    };
}

bool enemy_collided(void)
{
    for (size_t I = 0; I < enemy_amount; ++I)
    {
        if(pos_x >= enemies[I].pos_x && pos_x <= enemies[I].pos_x + enemies[I].size)
            if(pos_y >= enemies[I].pos_y && pos_y <= enemies[I].pos_y + enemies[I].size)
            {
                {
                    return true;
                }
            }
    }
    return false;
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
        {
            for(size_t II = 0; II < enemies[I].size; ++II)
                {
                    for(size_t III = 0; III < enemies[I].size; ++III)
                    {
                        print_char_specific(' ', enemies[I].prev_x + II, enemies[I].prev_y + III);
                    }
                }
        }

        for(size_t II = 0; II < enemies[I].size; ++II)
        {
            for(size_t III = 0; III < enemies[I].size; ++III)
            {
                print_char_specific_color(' ', enemies[I].pos_x + II, enemies[I].pos_y + III, PRINT_COLOR_LIGHT_RED, PRINT_COLOR_LIGHT_RED);
            }
        }

        enemies[I].prev_x = enemies[I].pos_x;
        enemies[I].prev_y = enemies[I].pos_y;
    }
}