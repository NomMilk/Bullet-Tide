#include <stdbool.h>

#include "print.h"
#include "input_manager.h"

void kernel_main()
{
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
"                        PRESS ANY KEY TO PLAY"
    );

    while(true)
    {
        if(detect_char() != '\0')
        {
            print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLUE);
            print_clear();
            break;
        }
    }

}