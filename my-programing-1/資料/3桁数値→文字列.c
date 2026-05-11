#include <stdio.h>

int main(void)
{
    char str[3];
    int n;
    int rank = 100;

    printf("3桁の整数=");
    scanf("%d", &n);
    int i = 0;
    
    //ループ文出する場合。
    for (int j = 0; j <= 3; j++){
        if(n % rank != n){
            str[i] = n / rank +'0';
            i++;
        }
        n %= rank;
        rank /= 10;
    }
    str[i] = '\0';

    printf("整数(文字列)=%s\n", str);
    return 0;
}