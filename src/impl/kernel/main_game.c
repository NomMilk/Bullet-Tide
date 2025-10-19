#include <stdbool.h>

//nessary
#include "print.h"
#include "utils.h"
#include "input_manager.h"

//game
#include "player_manager.h"
#include "enemies.h"
#include "score.h"

//game states
void game_over(void);
void start_game(void);

void kernel_main(void)
{
    disable_cursor();
    print_clear();
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
    print_str(
"__________      .__  .__          __    ___________.__    .___      \n"
"\\______   \\__ __|  | |  |   _____/  |_  \\__    ___/|__| __| _/____  \n"
" |    |  _/  |  \\  | |  | _/ __ \\   __\\   |    |   |  |/ __ |/ __ \\ \n"
" |    |   \\  |  /  |_|  |_\\  ___/|  |     |    |   |  / /_/ \\  ___/ \n"
" |______  /____/|____/____/\\___  >__|     |____|   |__\\____ |\\___  >\n"
"        \\/                     \\/                          \\/    \\/ \n"
"\n\n\n\n"
"                You are a little x use WASD to move around\n"
"                Don't get hit by the evil red blocks!!!\n\n"
"                        PRESS ANY KEY TO PLAY"
    );

    delay(UPDATE_DELAY * 20);
    while(true)
    {
        if(detect_char() != '\0')
        {
            break;
        }
        delay(UPDATE_DELAY);
    }

    start_game();
}

void start_game(void)
{
    //init
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE);
    print_clear();

    score = 0;
    clear_enemy();
    pos_x = (int)(NUM_COLS/2);
    pos_y = (int)(NUM_ROWS/2);

    //game loop
    while(true)
    {
        for(size_t i = 0; i < (int)(UPDATE_DELAY / 8); ++i)
        {
            for(size_t i = 0; i < (int)(4); ++i)
            {
                char current_char = detect_char();
                move_hori(current_char);
                move_vert(current_char);
                partial_redraw();
                delay(UPDATE_DELAY);
                display_score();

                if(enemy_collided())
                    game_over();
            }
            enemy_movement();
        }

        create_enemy();
        update_score();
    }
}

void game_over(void)
{
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_clear();
    print_str(
"  ________                        ________                    ._._.\n"
" /  _____/_____    _____   ____   \\_____  \\___  __ ___________| | |\n"
"/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\ | |\n"
"\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/\\|\\|\n"
" \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   ____\n"
"        \\/     \\/      \\/     \\/          \\/          \\/       \\/\\/\n"
"\n\n\n\n"
"                          Press a q to play again!!"
    );

    delay(UPDATE_DELAY * 20);
    while(true)
    {
        if(detect_char() == 'q')
        {
            start_game();
        }
        delay(UPDATE_DELAY);
    }
}