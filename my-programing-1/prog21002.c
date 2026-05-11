#include<stdio.h>
#include<string.h>
int main(){
    printf("入力");
    char input[30];
    char input2[30];
    scanf("%s",input);
    printf("入力");
    scanf("%s",input2);
    int x = strcmp(input,input2);
    if(x>0){
        printf("1つ目が大きいです");
    }else if(x<0){
        printf("2つ目が大きいです");
    }else{
        printf("???");
    }
    return 0;
}