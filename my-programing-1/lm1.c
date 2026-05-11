#include <stdio.h>
int main(){
    int num[32];
    int n;
    printf("入力");
    scanf("%d",n);
    for(int i=0;num[i]!='\0';i++){
        if(num[i]%2==1){
            num[i]=1;
        }else{
            num[0]=0;
        }
    }
    for(int i=0;num[i]!='\0';i++){
        printf("%d",num[i]);
    }
    return 0;
}