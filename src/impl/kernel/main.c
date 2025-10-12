#include "print.h"

void kernel_main()
{
    print_clear();
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
     print_str(
"    _______      __       ____  _____\n"
"   / ____(_)____/ /_     / __ \\/ ___/\n"
"  / /_  / / ___/ __ \\   / / / /\\__ \\ \n"
" / __/ / (__  ) / / /  / /_/ /___/ / \n"
"/_/   /_/____/_/ /_/   \\____//____/  \n"
    );
}