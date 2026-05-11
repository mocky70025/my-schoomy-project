#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 


char ask(const char *question, time_t start_time, int time_limit) {
    char q;
    do {int elapsed_time = (int)difftime(time(NULL), start_time);
        int remaining_time = time_limit - elapsed_time;
        if (remaining_time <= 0) {
            printf("\n💥 時間切れ！爆弾が爆発しました！ 💥\n");
            system("afplay explosion.mp3");
            exit(1);
        }
        printf("[残り時間: %d秒] %s (Y/N): ", remaining_time, question);
        scanf(" %c", &q);
        if (q == 'Y' || q == 'y' || q == 'N' || q == 'n') {
            return q; 
        }
        printf("無効な入力です。YまたはNを入力してください。\n");
    } while (1); 
}


void display_bomb_with_wires(const char wires[][5], int wire_count) {
    printf("\n=== 爆弾 ===\n");
    printf("   _______\n");
    printf("  |       |\n");
    printf("  |  💣   |\n");
    printf("  |_______|\n");

    for (int i = 0; i < 3; i++) { 
        printf("   ");
        for (int j = 0; j < wire_count; j++) {
            printf("%s ", wires[j]);
        }
        printf("\n");
    }
}


int solve_three_wires_with_questions(const char wires[][5], time_t start_time, int time_limit) {
    if (ask("赤いワイヤがありますか？", start_time, time_limit) == 'N') {
        
        for (int i = 0; i < 3; i++) {
            if (strcmp(wires[i], "🟥") == 0) {
                printf("\n💥 間違った回答！爆弾が爆発しました！ 💥\n");
                system("afplay explosion.mp3"); 
                exit(1);
            }
        }
        return 2; 
    }
    if (ask("最後のワイヤは白いですか？", start_time, time_limit) == 'Y') {
        if (strcmp(wires[2], "🤍") != 0) {
            printf("\n💥 間違った回答！爆弾が爆発しました！ 💥\n");
            system("afplay explosion.mp3"); 
            exit(1);
        }
        return 3; 
    }
    if (ask("青いワイヤが2本以上ありますか？", start_time, time_limit) == 'Y') {
        int blue_count = 0;
        for (int i = 0; i < 3; i++) {
            if (strcmp(wires[i], "🟦") == 0) blue_count++;
        }
        if (blue_count < 2) {
            printf("\n💥 間違った回答！爆弾が爆発しました！ 💥\n");
            system("afplay explosion.mp3"); 
            exit(1);
        }
        return 3; 
    }
    return 3;
}


int solve_four_wires_with_questions(const char wires[][5], time_t start_time, int time_limit) {
    if (ask("赤いワイヤが2本以上ありますか？", start_time, time_limit) == 'Y') {
        int red_count = 0;
        for (int i = 0; i < 4; i++) {
            if (strcmp(wires[i], "🟥") == 0) red_count++;
        }
        if (red_count < 2) {
            printf("\n💥 間違った回答！爆弾が爆発しました！ 💥\n");
            system("afplay explosion.mp3"); 
            exit(1);
        }
        if (ask("シリアル番号の最後の数字は奇数ですか？", start_time, time_limit) == 'Y') {
            return 4; 
        }
    }
    if (ask("最後のワイヤは黄色ですか？", start_time, time_limit) == 'Y') {
        if (strcmp(wires[3], "🟨") != 0) {
            printf("\n💥 間違った回答！爆弾が爆発しました！ 💥\n");
            system("afplay explosion.mp3"); 
            exit(1);
        }
        if (ask("赤いワイヤはありませんか？", start_time, time_limit) == 'Y') {
            int red_count = 0;
            for (int i = 0; i < 4; i++) {
                if (strcmp(wires[i], "🟥") == 0) red_count++;
            }
            if (red_count > 0) {
                printf("\n💥 間違った回答！爆弾が爆発しました！ 💥\n");
                system("afplay explosion.mp3"); 
                exit(1);
            }
            return 1; 
        }
    }
    return 2; 
}

int main(void) {
    srand(time(NULL)); 

    printf("💣 爆弾解除ゲーム 💣\n\n");


    
    int serial_number = rand() % 10000; 
    printf("シリアルナンバー: %04d\n", serial_number); 
    

    
    const char bomb_1[3][5] = {"🟥", "🟦", "🤍"}; 
    const char bomb_2[4][5] = {"🟥", "🟦", "🟨", "🤍"}; 
    const char bomb_3[3][5] = {"🟦", "🟦", "🤍"}; 
    const char bomb_4[4][5] = {"🟨", "🟥", "🟦", "🤍"}; 

    const char (*bombs[4])[5] = {bomb_1, bomb_2, bomb_3, bomb_4};
    int bomb_wire_counts[4] = {3, 4, 3, 4};

    int bomb_index = rand() % 4;
    const char (*selected_bomb)[5] = bombs[bomb_index];
    int wire_count = bomb_wire_counts[bomb_index];

    display_bomb_with_wires(selected_bomb, wire_count);

   
    int time_limit = 15; 
    time_t start_time = time(NULL);

  
    int correct_wire;
    if (wire_count == 3) {
        correct_wire = solve_three_wires_with_questions(selected_bomb, start_time, time_limit);
    } else {
        correct_wire = solve_four_wires_with_questions(selected_bomb, start_time, time_limit);
    }


    printf("\n切るべきワイヤは %d 番目です！\n", correct_wire);

    
    int wire_choice;
    printf("\nどのワイヤを切りますか？（1〜%d）: ", wire_count);
    scanf("%d", &wire_choice);

  
    if (wire_choice == correct_wire) {
        printf("\n🎉 成功！爆弾を解除しました！ 🎉\n");
        system("afplay success.mp3"); 
    } else {
        printf("\n💥 失敗！爆弾が爆発しました！ 💥\n");
        system("afplay explosion.mp3"); 
    }

    return 0;
}