#include<stdio.h>
int main (void)
{
int x,y;
printf("0か1を入力=");
scanf("%d", &x);

if(x == 0){
y = 20240401;
} else {
y = 20290331;
}
printf("%d\n", y);
return 0;
}