#include <stdio.h>
int main(void){
 int a; 
 printf("整数を入力してください\n");
 scanf("%d",&a);
 if (a>=0 && a<=10){
    printf("aは0以上10以下です\n");

 }
return 0;

}
int main(void){
    int a; 
    printf("整数を入力してください\n");
    scanf("%d",&a);
    if (a>=0 || a<=10){
       printf("aは0以上10以下です\n");
   
    }
   return 0;
   
   }