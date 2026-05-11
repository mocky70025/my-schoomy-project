#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 外部コマンドを実行してIDmを取得する
    FILE *fp = popen("/usr/bin/python3 nfc_scan.py", "r");
    if (fp == NULL) {
        perror(NULL); // エラーの詳細を表示
        return 1;
    }
    // "IDm: 0123456789abcdf" の右側だけを取得する
    char idm[17];
    if (fscanf(fp, "IDm: %16s", idm) != 1) {
        fprintf(stderr, "Failed to scan IDm\n");
        pclose(fp);
        return 1;
    }
    // 取得した IDm を表示する
    printf("Succeed to scan IDm: %s\n", idm);
    pclose(fp);

    // IDm:学籍番号:名前のデータベース
    const char *database[] = {
        "012E5CE5D8107067:2201:神山まるこ",
        "012E5CE5D8107988:2202:神山いでこ",
        "012E5CE5D8107467:2203:神山たろう",
        "012E5CE5D8104799:2204:神山じろう",
        "012E5CE5D81090B9:2205:神山はなこ",
        "012E5CE5D8105A89:2206:神山ひでみ",
        "012E5CE5D81079BA:2207:神山ひでお",
        "012E5CE5D81099AF:2208:神山さらだ",
        "012E5CE5D81043B9:2209:神山すだち",
        "012E5CE5D8103971:2210:神山うめこ",
        "X" // ←最後の行はXにしておく
    };
    // idmの文字列が存在するデータベースの行を検索する
    int found = -1;
    for (int i = 0; database[i][0] != 'X'; i++) {
        if (strstr(database[i], idm) != NULL) {
            found = i;
            break;
        }
    }
    // 検索結果を表示する
    if (found == -1) {
        printf("No match found for IDm: %s\n", idm);
    } else {
        printf("Found: %s\n", database[found]);
    }

    // sayコマンドを実行してしゃべらせる
    FILE *speech = popen("say", "w");
    if (speech == NULL) {
        perror(NULL); // エラーの詳細を表示
        return 1;
    }
    if (found == -1) {
        fprintf(speech, "誰ですか？ %sは、", idm);
        fprintf(speech, "登録されていないIDmです。\n");
    } else {
        fprintf(speech, "学籍番号%sさん、", database[found] + 17);
        fprintf(speech, "おかえりなさい。\n");
    }
    pclose(speech);

    return 0;
}
