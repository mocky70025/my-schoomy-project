#include <stdio.h>
#include <string.h>
int main(){
    char str[30];
    char str_copy[30];
    printf("入力=");
    scanf("%s",str);
    printf("入力=");
    scanf("%s",str_copy);

    strcat(str,str_copy);
    printf("%s",str);
    return 0;
}