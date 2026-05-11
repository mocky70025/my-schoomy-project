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
int player_x=1;
int player_y=1;

int main(){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            if(player_x==x&&player_y==y){
                printf("p");
            }else{
                printf("%c",maze[y][x]);
            }
        }
        printf("\n");
    }
    return 0;
}