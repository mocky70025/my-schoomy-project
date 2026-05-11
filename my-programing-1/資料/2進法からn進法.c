#include <stdio.h>

int main(void)
{
    char binary[4];
    int decimal = 0;
    int rank = 8;
    printf("値を2進法で入力してください(4桁)=");
    scanf("%s", binary);

    for (int i = 0; i < 4; i++){
        if(binary[i] == '1'){
            decimal += rank;
        }
        rank /= 2;
    }

    printf("10進法で表すと%dです。\n", decimal);
    printf("16進法で表すと%xです。\n", decimal);
    printf("8進法で表すと%oです。\n", decimal);
    return 0;
}