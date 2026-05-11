#include<stdio.h>
void input_data(int *p){
    int i=0;
    while(i<10){
    printf("入力");
    scanf("%d",p);

    i++;
    p++;
}
}
int sum_data(int *p){
    int i=0;
    int sum=0;
    while(i<10){
        sum=sum+*p;
        p++;
        i++;
    }
    return sum;
}
int main(void)
{
	int a[10];
	input_data(a);
	
	int sum = sum_data(a);
	printf("合計=%d\n", sum);
	return 0;
}