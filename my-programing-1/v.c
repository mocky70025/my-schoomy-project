#include "kmc_lib.h"

int WIDTH = 50;
int HEIGHT = 11;

char maze[11][51] = {
    "##################################################",
    "#p      #          # .        #       .          #",
    "# ##### # ######## # ######## # ################ #",
    "# #   # # #      # # #      # # #              # #",
    "# # # # # # #### # # # #### # # # ############ # #",
    "# . #     .      .   #      .   # .            . #",
    "# # ####### # ###### # ###### # # ############ # #",
    "# #         #      # #        # # #              #",
    "# ########### #### # ######## # # ############## #",
    "# .           # .    # .      # # .              #",
    "##################################################",
};

int player_x = 1, player_y = 1;
int jewelry_count = 0;

typedef struct {
    int x, y, dx, dy, type; 
} Enemy;

Enemy enemies[8];

void init_enemies() {
    enemies[0] = (Enemy){20, 5,  1, 0, 0};
    enemies[1] = (Enemy){48, 1, -1, 0, 1};
    enemies[2] = (Enemy){35, 9,  1, 0, 0};
    enemies[3] = (Enemy){10, 1,  0, 1, 1};
    enemies[4] = (Enemy){40, 7, -1, 0, 1};
    enemies[5] = (Enemy){1, 9,   1, 0, 1};
    enemies[6] = (Enemy){25, 1,  0, 1, 1};
    enemies[7] = (Enemy){48, 9, -1, 0, 0};
}

void move_enemies() {
    for (int i = 0; i < 8; i++) {
        int next_x = enemies[i].x + enemies[i].dx;
        int next_y = enemies[i].y + enemies[i].dy;
        if (maze[next_y][next_x] == '#') {
            if (enemies[i].type == 0) {
                enemies[i].dx *= -1; enemies[i].dy *= -1;
            } else {
                if (enemies[i].dx == 1)       { enemies[i].dx = 0;  enemies[i].dy = 1;  }
                else if (enemies[i].dy == 1)  { enemies[i].dx = -1; enemies[i].dy = 0;  }
                else if (enemies[i].dx == -1) { enemies[i].dx = 0;  enemies[i].dy = -1; }
                else if (enemies[i].dy == -1) { enemies[i].dx = 1;  enemies[i].dy = 0;  }
            }
        } else {
            enemies[i].x = next_x; enemies[i].y = next_y;
        }
    }
}

void draw_maze(void) {
    jewelry_count = 0;
    printf("\033[2J\033[H");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int is_enemy = 0;
            for(int i = 0; i < 8; i++) if(enemies[i].x == x && enemies[i].y == y) is_enemy = 1;
            if (player_x == x && player_y == y) printf("🦹"); 
            else if (is_enemy) printf("🚓");                 
            else if (maze[y][x] == '.') { printf("💎"); jewelry_count++; } 
            else if (maze[y][x] == '#') printf("田"); 
            else printf("　"); 
        }
        printf("\n");
    }
    for(int i = 0; i < 8; i++) {
        if(enemies[i].x == player_x && enemies[i].y == player_y) {
            printf("\n🚨 警察に逮捕された！ GAME OVER 🚨\n");
            exit(0); 
        }
    }
    printf("\n💎 残り: %d | 🚓 警察: 8体 | 矢印キーまたはWASDで移動\n", jewelry_count);
    if (jewelry_count == 0) { printf("\n✨ MISSION COMPLETE! ✨\n"); exit(0); }
}

int main(void) {
    init_enemies(); 
    kmc_typingmode();
    for (;;) {
        draw_maze();
        kmc_keypressed(10000); 
        int ch = getchar();
        int old_x = player_x, old_y = player_y;

        // --- 矢印キー判定の追加 ---
        if (ch == '\033') { // エスケープ文字
            getchar(); // '[' を読み飛ばす
            switch (getchar()) {
                case 'A': ch = 'w'; break; // 上矢印
                case 'B': ch = 's'; break; // 下矢印
                case 'C': ch = 'd'; break; // 右矢印
                case 'D': ch = 'a'; break; // 左矢印
            }
        }

        switch (ch) {
            case 'w': player_y--; break;
            case 's': player_y++; break;
            case 'a': player_x--; break;
            case 'd': player_x++; break;
            case 'q': return 0;
        }

        if (maze[player_y][player_x] == '#') {
            player_x = old_x; player_y = old_y;
        }
        maze[player_y][player_x] = ' '; 
        move_enemies(); 
    }
    return 0;
}