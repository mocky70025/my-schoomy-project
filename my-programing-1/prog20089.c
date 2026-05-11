#include<stdio.h>

void func1(float x,int *y,int *z){
    *y=x;
    *z=(x-*y)*10;
}

int main(void)
{
float x;
int y, z;

printf("実数=");
scanf("%f", &x);

func1(x,&y,&z);

printf("%d.%d\n", y, z);
return 0;
}