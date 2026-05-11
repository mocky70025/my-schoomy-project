#include "lib_bmp16.h"


int main(void)
{
    int green = 10; // 緑のパレット番号
    int black = 0;  // 黒のパレット番号

    bmp16_create(80, 80, green); // 80x80 背景色：緑

    bmp16_palette_set_rgb( 84,140, 53, green); // 緑:10 クリーパーっぽい色に
    bmp16_palette_set_rgb(  9,  9,  9, black); // 黒: 0 濃い目の黒

    bmp16_fill_rect(10, 20, 30-1, 40-1, black); // 左目
    bmp16_fill_rect(50, 20, 70-1, 40-1, black); // 右目
    bmp16_fill_rect(20, 50, 60-1, 70-1, black); // 口
    bmp16_fill_rect(30, 40, 50-1, 50-1, black); // 口
    bmp16_fill_rect(20, 70, 30-1, 80-1, black); // 口
    bmp16_fill_rect(50, 70, 60-1, 80-1, black); // 口

    bmp16_save("bmp_creeper.bmp");
    system("open bmp_creeper.bmp");
    return 0;
}