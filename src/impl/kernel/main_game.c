#include <stdbool.h>

#include "print.h"
#include "input_manager.h"
#include "player_manager.h"
#include "utils.h"

const static size_t UPDATE_DELAY = 500;

//game states
void game_over(void);

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
"                Don't get hit by the evil v!!!\n\n"
"                        PRESS ANY KEY TO PLAY"
    );

    delay(UPDATE_DELAY * 20);
    while(true)
    {
        if(detect_char() != '\0')
        {
            print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLUE);
            print_clear();
            break;
        }
        delay(UPDATE_DELAY);
    }

    //game loop
    while(true)
    {
        char current_char = detect_char();
        move_hori(current_char);
        move_vert(current_char);
        partial_redraw();
        delay(UPDATE_DELAY);
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
"                          Press a key to play again!!"
    );

    delay(UPDATE_DELAY * 20);
    while(true)
    {
        if(detect_char() != '\0')
        {
            kernel_main();
        }
        delay(UPDATE_DELAY);
    }
}