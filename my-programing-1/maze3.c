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


 void draw_maze(){
    printf("\033[2J");
    printf("\033[H");
    for (int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            if(player_x==x&&player_y==y){
                printf("p");
            }else{
                printf("%c",maze[y][x]);
            }
        }
        printf("\n");
    }
    printf("\n操作: w/a/s/d 移動, q 終了\n");
 }

int main(){
    for(;;){
        draw_maze();
        int ch = getchar();
        switch(ch){
            case 'w':player_y--;break;
            case 'a':player_y--;break;
            case 's':player_y++;break;
            case 'd':player_y++;break;
            case 'q':return 0;
            default: continue;
        }
    }
    return 0;
}