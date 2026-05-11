#include "kmc_lib.h"

int WIDTH = 50;
int HEIGHT = 11;
int alert_mode = 0;
int turn_count = 0;

char maze[11][51] = {
    "##################################################",
    "#p      #          # .        #       .          #",
    "# ##### # ######## # ######## # ################ #",
    "# #   # # #      # # #      # # #              # #",
    "# # # # # # #### # # # #### # # # ############ # #",
    "# . #     C      .   #      .   G .            . #",
    "# # ####### # ###### # ###### # # ############ # #",
    "# #         #      # #        # # #              #",
    "# ########### #### # ######## # # ############## #",
    "# .           # .    # .      # # .              #",
    "##################################################",
};

int player_x = 1; 
int player_y = 1;

typedef struct {
    int x, y, dx, dy, type; 
} Enemy;

Enemy teki[8];

void init_enemies() {
    teki[0] = (Enemy){20, 5,  1, 0, 0};
    teki[1] = (Enemy){48, 1, -1, 0, 1};
    teki[2] = (Enemy){35, 9,  1, 0, 0};
    teki[3] = (Enemy){10, 1,  0, 1, 1};
    teki[4] = (Enemy){40, 7, -1, 0, 1};
    teki[5] = (Enemy){1, 9,   1, 0, 1};
    teki[6] = (Enemy){25, 1,  0, 1, 1};
    teki[7] = (Enemy){48, 5, -1, 0, 0};
}

void move_enemies() {
    int move_count = (alert_mode > 0) ? 2 : 1;
    if (alert_mode > 0) alert_mode--;

    for (int m = 0; m < move_count; m++) {
        for (int i = 0; i < 8; i++) {
            int next_x = teki[i].x + teki[i].dx;
            int next_y = teki[i].y + teki[i].dy;
            if (maze[next_y][next_x] == '#' || maze[next_y][next_x] == 'G') {
                if (teki[i].type == 0) {
                    teki[i].dx *= -1; teki[i].dy *= -1;
                } else {
                    if (teki[i].dx == 1)       { teki[i].dx = 0;  teki[i].dy = 1;  }
                    else if (teki[i].dy == 1)  { teki[i].dx = -1; teki[i].dy = 0;  }
                    else if (teki[i].dx == -1) { teki[i].dx = 0;  teki[i].dy = -1; }
                    else if (teki[i].dy == -1) { teki[i].dx = 1;  teki[i].dy = 0;  }
                }
            } else {
                teki[i].x = next_x; teki[i].y = next_y;
            }
        }
    }
}

void draw_maze(void) {
    int jewelry_count = 0;
    printf("\033[2J\033[H");
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int teki2 = 0;
            for(int i = 0; i < 8; i++) {
                if(teki[i].x == x && teki[i].y == y) teki2 = 1;
            }

            if (player_x == x && player_y == y) printf("🦹"); 
            else if (teki2) printf("🚓");                 
            else if (maze[y][x] == '.') { printf("💎"); jewelry_count++; } 
            else if (maze[y][x] == 'C') printf("📸"); 
            else if (maze[y][x] == 'G') printf("🚧"); 
            else if (maze[y][x] == '#') printf("田"); 
            else printf("　"); 
        }
        printf("\n");
    }

    for(int i = 0; i < 8; i++) {
        if(teki[i].x == player_x && teki[i].y == player_y) {
            printf("\n🚨 警察に逮捕された！ GAME OVER 🚨\n");
            exit(0); 
        }
    }

    printf("\n💎 残り: %d | 🚓 警備: 8体", jewelry_count);
    if (alert_mode > 0) printf(" | \033[31m⚠️ 警察加速中！ ⚠️\033[0m");
    printf("\n[矢印/WASD]:移動  [Q]:終了\n");

    if (jewelry_count == 0) {
        printf("\n✨ MISSION COMPLETE! 全ての宝石を奪取！ ✨\n");
        exit(0);
    }
}

int main(void) {
    init_enemies(); 
    kmc_typingmode();
    for (;;) {
        draw_maze();
        kmc_keypressed(10000); 
        int ch = getchar();
        int old_x = player_x, old_y = player_y;

        if (ch == '\033') {
            getchar();
            switch (getchar()) {
                case 'A': ch = 'w'; break;
                case 'B': ch = 's'; break;
                case 'C': ch = 'd'; break;
                case 'D': ch = 'a'; break;
            }
        }

        switch (ch) {
            case 'w': player_y--; break;
            case 's': player_y++; break;
            case 'a': player_x--; break;
            case 'd': player_x++; break;
            case 'q': return 0;
            default: continue;
        }

        if (maze[player_y][player_x] == '#' || maze[player_y][player_x] == 'G') {
            player_x = old_x; player_y = old_y;
        }

        if (maze[player_y][player_x] == 'C') alert_mode = 5;
        if (maze[player_y][player_x] == '.') maze[player_y][player_x] = ' ';

        turn_count++;
        if (turn_count % 5 == 0) {
            for (int y = 0; y < HEIGHT; y++) {
                for (int x = 0; x < WIDTH; x++) {
                    if (maze[y][x] == 'G') maze[y][x] = 'g';
                    else if (maze[y][x] == 'g') maze[y][x] = 'G';
                }
            }
        }

        move_enemies(); 
    }
    return 0;
}