#include "kmc_lib.h"
int main (){
    kmc_typingmode();
    printf("Usagi to Kame Start!\n");
    int count = 1;
    
    do{
        int key = getchar();
      
        
        if(count%2==1){
            printf("\xF0\x9F\x90\xA1");
            count++;
        }else if(count%10==0){
            printf("\xF0\x9F\x90\xB1");
            count++;
        }else if(count%2==0){
            printf("\xF0\x9F\x90\x81");
            count++;
        }


    }while (kmc_keypressed(1));
    printf("\n score=%d\n",(count-1)*10);
    return 0;
}