#include "kmc_lib.h"
int main (){
    kmc_typingmode();
    printf("Kame Start!\n");
    int count = 0;
    do{
        int key = getchar();
        printf("\xF0\x9F\x90\xA2");
        count++;

    }while (kmc_keypressed(2));
    printf("\n score=%d\n",count);
    return 0;
}