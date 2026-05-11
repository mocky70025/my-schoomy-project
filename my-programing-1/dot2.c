#include <stdio.h>
int main (){
    for (int j=0;j<16;j++){
        int x = j+16;
        printf("\e[48;5;%dm",x);
        printf("%d",x);
        printf("\e[0m");
    }
    printf("\n");
    return 0;
}