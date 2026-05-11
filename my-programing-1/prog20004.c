#include <stdio.h>
#include <string.h>

int main() {
    char str[30];
    char str2[60] = "<"; // 初期値として"<"を設定

    printf("入力=");
    scanf("%s", str);

    strcat(str2, str);  // 入力された文字列を結合
    strcat(str2, ">");  // ">"を追加

    printf("%s\n", str2); // 結果を出力

    return 0;
}