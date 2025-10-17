#include "print.h"
#include "score.h"

int score = 0;

void update_score(void) {
    ++score;
}

void display_score(void) {
    char output[20] = "SCORE: ";
    int i = 7;

    if (score == 0) {
        output[i++] = '0';
    } else {
        char temp[10];
        int t = 0;
        int n = score;

        while (n > 0) {
            temp[t++] = '0' + (n % 10);
            n /= 10;
        }

        while (t > 0) {
            output[i++] = temp[--t];
        }
    }

    print_str(output);
}