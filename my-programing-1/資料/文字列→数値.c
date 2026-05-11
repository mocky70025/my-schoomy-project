#include <stdio.h>

int main(void)
{
    char str[10];
    int n = 0;
    int i = 0;

    printf("整数(文字列)=");
    scanf("%s", str);

    while (str[i] != '\0'){
        n = n * 10 + (str[i] - '0');
        i++;
    }
    printf("整数=%d\n", n);
    return 0;
}