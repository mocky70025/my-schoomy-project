#include<stdio.h>
/*int main(){
    char x;
    char *p;
    p=&x;
    *p='A';
    
    printf("xのアドレス=%p\nxのサイズ=%lu\nxの値=%c",p,sizeof(p),*p);
}*/


/*int main(){
    int x,y;
    int *p;
    p=&y;
    printf("y=");
    scanf("%d",&x);
    *p=x;
    printf("%d,%d",x,y);
}*/
int main(){
    int x,y;
    int *p=&x;
    int *q=&y;
    printf("入力");
    scanf("%d",&x);
    printf("入力");
    scanf("%d",&y);
    printf("%d,%d",x,y);
    
    
    printf("%d,%d",x,y);

}