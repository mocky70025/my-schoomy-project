#include <stdio.h>

int main(void) {
    char c = 'a';

    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }

    printf("%c\n", c);  // A
    return 0;
}
