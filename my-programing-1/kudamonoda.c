#include "kmc_lib.h"
int main(){
    kmc_typingmode();
    int x,i;
    char words[][99] = {
        "apple","banana","orange","danger"};
    char emoji[][99] = {
        "\xF0\x9F\x8D\x8E","\xF0\x9F\x8D\x8C","\xF0\x9F\x8D\x8A","\xE2\x98\xA3\xEF\xB8\x8E"};
         printf("Kudamono da Start!\n");
        
        for (int x = 0; x < 4; x++) {
            printf("%s %s\n", words[x], emoji[x]); 
        
            for (int i = 0; words[x][i] != '\0'; i++) { 
                if (kmc_keypressed(2)) { 
                    int key = getchar(); 
                    if (key == words[x][i]) {
                        printf("%c", key); 
                    } else {
                        i--; 
                        continue;
                    }
                } else { 
                    printf("\nGame over! \n"); 
                    return 1;
                }
            }
        
            printf(" %s\n", emoji[x]); 
        }
        
        printf("\nGame clear! \n"); 
        return 0;
    }