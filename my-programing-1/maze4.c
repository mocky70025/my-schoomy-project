#include "kmc_lib.h"
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

int WIDTH  = 21; // 横幅
int HEIGHT = 11; // 高さ

// プレイヤー位置
int player_x = 1;
int player_y = 1;

void draw_maze(void) {
    printf("\033[2J"); // 画面全消去
    printf("\033[H");  // カーソルを左上へ
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (player_x == x && player_y == y) {
                printf("p"); // プレイヤーの表示
            } else {
                printf("%c", maze[y][x]); // 1文字毎
            }
        }
        printf("\n"); // 改行
    }
    printf("\n操作: w/a/s/d 移動, q 終了\n");
}

int main(void) {
    kmc_typingmode(); // タイピングモードに
    for (;;) {
        draw_maze(); // 迷路を描く
        kmc_keypressed(10000); // 文字が押されるまで待つ
        int ch = getchar(); // 入力文字の読み込み
        switch (ch) {
            case 'w': player_y--; break; // ↑上
            case 's': player_y++; break; // ↓下
            case 'a': player_x--; break; // ←左
            case 'd': player_x++; break; // →右
            case 'q': return 0; // 終了
            default: continue; // それ以外の文字は無視
        }

        // 移動方向に壁がある場合は進めないようにする
        if (maze[player_y][player_x] == '#') {
            switch (ch) {
                case 'w': player_y++; break; // 戻る
                case 's': player_y--; break; // 戻る
                case 'a': player_x++; break; // 戻る
                case 'd': player_x--; break; // 戻る
            }
        }
    }
    return 0;
}