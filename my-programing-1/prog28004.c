#include<stdio.h>

#define num_data 10

void input_data(int *p){
    int *end = p + num_data;
    while(p < end){
        printf("入力");
        scanf("%d", p);
        p++;
    }
}

int guusuu_num(int *data,int num_data){
    int count = 0;
    int *end = data + num_data;
    while(data < end){
        int value = *data;
        if(value != 0 && value % 2 == 0){
            count++;
        }
        data++;
    }
    return count;
}


int main(void)
{
	int data[100];
	input_data(data); //前の練習問題の関数
	
	int num = guusuu_num(data,num_data);
	printf("偶数の数は%d です\n", num);
	return 0;
}
