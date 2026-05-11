#include "kmc_lib.h" // これで上のファイルを読み込める
int main() {
    printf("タイピングへようこそ!\n");
    kmc_typingmode(); // タイピングモードにする

    // 10秒以内にキーが押されるのを繰り返し待つ
    while (kmc_keypressed(10)) {
        int key = getchar(); // 押されたキーを読む
        if (key == 'a') {
            printf("\xF0\x9F\x8D\xAA"); // クッキー
        } else if (key == 'b') {
            printf("\xF0\x9F\x94\xA8"); // ハンマー
        } else {
            printf("miss!");
            break; // その他のキーを押すと終了する
        }
    }
    // 指定時間を過ぎてキーが押されなかったら終了
    printf("\nGame Over!\n");
    return 0;
}