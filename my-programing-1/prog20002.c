#include <stdio.h>
#include <string.h>
int main(){
    char str[30];
    char str_copy[30];
    printf("入力=");
    scanf("%s",str);
    strncpy(str_copy,str,5);
    printf("%s",str_copy);
    return 0;
}