#include<stdio.h>
#include<string.h>
int main(){
    char input[30];
    printf("入力=");
    scanf("%s",input);
    int i=strlen(input);
    printf("%c",input[i-1]);
    return 0;
}