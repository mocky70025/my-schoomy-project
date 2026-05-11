#include<stdio.h>


int main(){
    int x;
    int sum=0;
    printf("整数入力");
    scanf("%d",&x);
    do{
        x=x/10;
        sum++;
    }while(x!=0);
    printf("%d桁です。",sum);
}