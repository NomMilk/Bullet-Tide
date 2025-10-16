#pragma once
#include <stdint.h>

extern int prev_x, prev_y;
extern float pos_x, pos_y;

void move_hori(char _input);
void move_vert(char _input);
void partial_redraw(void);