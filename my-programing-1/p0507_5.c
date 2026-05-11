#include <stdio.h>
int main(void){
    int a;
    printf("整数を入力してね");
    scanf("%d",&a);
    if(a==0){
        printf("その数は0です");
    }else if(0>a){
        printf("その数は負の数です");

    }else{
        printf("その数は正の数です");

    }

}