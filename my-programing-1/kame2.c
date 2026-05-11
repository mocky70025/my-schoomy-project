#include "kmc_lib.h"
int main (){
    kmc_typingmode();
    printf("Usagi to Kame Start!\n");
    int count = 0;
    do{
        int key = getchar();
        if(count%2==1){
            printf("\xF0\x9F\x90\x87");
            count++;
        }else if(count%2==0 && count%10!=0){
            printf("\xF0\x9F\x90\xA2");
            count++;
        }else if(count%10==0 && count != 0){
            printf("\xF0\x9F\x90\xB0");
            count++;
        }else if(count==0){
            printf("\xF0\x9F\x90\xA2");
            count++;
        }

    }while (kmc_keypressed(1));
    printf("\n score=%d\n",count*10);
    return 0;
}