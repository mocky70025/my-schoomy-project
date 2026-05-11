#include <stdio.h>
int main(void){
   int i;
   int y=0;
   int t=0;
   while(t<1){
   printf("数を入力\n");
    scanf("%d",&i);
    y=y+i;
    printf("合計値%d\n",y);
    if(y % 7 == 0){
        t=1;
    }
    }
   
   printf("7の倍数です");
   
return 0;

}