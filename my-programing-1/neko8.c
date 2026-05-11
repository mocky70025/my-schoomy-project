#include<stdio.h>
#include<unistd.h>
int main(){
    for(int x=0;x<50;x++){
        printf("\e[H\e[J\e[?7l");
        printf("%*s /\\_/\\ \n",x,"");
        if(x%2==0){
            printf("%*s( o.o )\n",x,"");
            printf("%*s > ~ < \n",x,"");
        }else{
        printf("%*s( -.- )\n",x,"");
        printf("%*s > o < \n",x,"");
        }
        usleep(100000);
    }
    for(int x=50;x>0;x--){
        printf("\e[H\e[J\e[?7l");
        printf("%*s /\\_/\\ \n",x,"");
        if(x%2==0){
            printf("%*s( o.< )\n",x,"");
            printf("%*s > ? < \n",x,"");
        }else{
        printf("%*s( n.n )\n",x,"");
        printf("%*s > = < \n",x,"");
        }
        usleep(100000);
    }

}