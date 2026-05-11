#include "lib_bmp.h"

int main(void) {
    // 480x240 背景白の1bitBMP画像を作成
    bmp1_create(480, 240, 0); // 幅,高さ,背景色(0:白)

    // M
    bmp1_draw_line( 40,  80,  40, 160, 1); // 左の縦線
    bmp1_draw_line( 80,  80,  80, 160, 1); // 右の縦線
    bmp1_draw_line( 40,  80,  60, 120, 1); // 左上→中央
    bmp1_draw_line( 60, 120,  80,  80, 1); // 中央→右上

    // O
    bmp1_draw_line( 90,  80, 130,  80, 1);
    bmp1_draw_line( 90, 160, 130, 160, 1);
    bmp1_draw_line( 90,  80,  90, 160, 1);
    bmp1_draw_line(130,  80, 130, 160, 1);

    // T
    bmp1_draw_line(140,  80, 180,  80, 1);
    bmp1_draw_line(160,  80, 160, 160, 1);

    // O
    bmp1_draw_line(190,  80, 230,  80, 1);
    bmp1_draw_line(190, 160, 230, 160, 1);
    bmp1_draw_line(190,  80, 190, 160, 1);
    bmp1_draw_line(230,  80, 230, 160, 1);

    // K
    bmp1_draw_line(240,  80, 240, 160, 1); // 縦
    bmp1_draw_line(240, 120, 280,  80, 1); // 右上
    bmp1_draw_line(240, 120, 280, 160, 1); // 右下

    // I
    bmp1_draw_line(290,  80, 330,  80, 1); // 上の横棒
    bmp1_draw_line(310,  80, 310, 160, 1); // 中央の縦線
    bmp1_draw_line(290, 160, 330, 160, 1); // 下の横棒

    // BMP画像ファイルを保存する
    bmp1_save("bmp_motoki.bmp");
    bmp1_free();

    // BMP画像を開く（macOS の場合）
    system("open bmp_motoki.bmp");

    return 0;
}
