#include <stdio.h>
int main (void){
int a;
int b;
printf("数値入力");
scanf("%d,%d",&a,&b);
for(a=a;a<=b;a++){
    if (!(a==b)){
    printf("%2d\n",a);
    }
    }
    printf("%2d",b);
}