#include <stdio.h>
#include <string.h>
int main(){
    char str[20];
    printf("入力=");
    scanf("%s",str);
    int x= strlen(str);
    printf("文字列長は%dです",x);
    return 0;
}