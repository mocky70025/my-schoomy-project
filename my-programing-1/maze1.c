#include <stdio.h>
char *maze[]={
     "#####################",
     "#                   #",
     "# ### # ### # ### # #",
     "# #     # #     # # #",
     "# # ##### ### ### # #",
     "#      #      #   # #",
     "##### ##### ##### # #",
     "#       #         # #",
     "# ######## ######## #",
     "#          #        #",
     "#####################",
};
int WIDTH = 21;
int HEIGHT = 11;

int main(){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            printf("%c",maze[y][x]);
        }
        printf("\n");
    }
    return 0;
}