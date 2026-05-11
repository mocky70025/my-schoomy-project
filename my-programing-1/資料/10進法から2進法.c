#include <stdio.h>

void binary_str(int num)
{
    char str[9];
    str[8] = '\0';
    int i = 7;
    while (num > 0) {
        if (num % 2 == 1) {
            str[i] = '1';
        } else {
            str[i] = '0';
        }
        num /= 2;
        i--;
    }
    while (i >= 0) {
        str[i] = '0';
        i--;
    }
    printf("%s\n", str);
}

int main(void)
{
    int num;
    printf("値を10進法で入力(255以下)=");
    scanf("%d", &num);

    binary_str(num);
    return 0;
}