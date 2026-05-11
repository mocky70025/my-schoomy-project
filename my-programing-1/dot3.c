#include <stdio.h>
int main (){
    for(int i=0;i<16;i++){
        for (int j=1;j<16;j++){
            int x = j+i*16;
            printf("\e[48;5;%dm",x);
            printf("%3d",x);
            printf("\e[0m");
        }
        printf("\n");
    }
        return 0;
}