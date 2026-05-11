#include <stdio.h>
#include <string.h>
int main(){
    char str[30];
    printf("入力=");
    scanf("%s",str);
    int x=strlen(str);
    while(x>=0){
        printf("%c",str[x]);
        x--;
    }
    return 0;
}