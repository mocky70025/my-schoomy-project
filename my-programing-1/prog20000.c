#include <stdio.h>

int main(){
    char input[31];
    char output[33];
    int j=0;
    output[0] = '<' ;
    printf("入力してください(30文字以内)");
    scanf("%s",input);
    for(int i=0;input[i]!='\0';i++){
        j++;
        output[j]=input[i];
    }
    output[j+1]='>';
    output[j+2]='\0';
    printf("%s",output);
    return 0;
}