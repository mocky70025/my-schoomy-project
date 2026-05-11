#include <stdio.h>
void binary_str(int num)
{
    char str[9];
    int i = 0;
    int rank = 128;

    while (rank >= 1){
        if(num / rank == 0){
            str[i] = '0';
        } else {
            str[i] = '1';
        }
        num %= rank;
        rank /= 2;
        i++;
    }
    str[i]='\0';
    printf("2進法で表すと%sです。\n", str);
}


int main(void)
{
    int num;
    printf("値を16進法で入力(2桁)=");
    scanf("%x", &num);

    binary_str(num);
    return 0;
}

