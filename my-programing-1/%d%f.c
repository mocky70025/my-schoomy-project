#include <stdio.h>
int main(void){
    int x=1;
    int sum=0;
    while(sum<50000){
    sum = sum + 1;
    printf("%d",sum);
    }
    printf("終了\n");
    return 0;
}