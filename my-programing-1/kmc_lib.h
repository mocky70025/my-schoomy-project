// kmc_lib.h 神山まるごと高専プログラミング演習用ライブラリ 0.1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

void kmc_typingmode(void) {
    struct termios t; setbuf(stdout, NULL);
    tcgetattr(STDIN_FILENO, &t); t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int kmc_keypressed(int timeout) {
    struct timeval tv = {timeout, 0};
    fd_set fds; FD_ZERO(&fds); FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}