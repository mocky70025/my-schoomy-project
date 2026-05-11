
#include "lib_bmp16.h"

void bmp16_draw_barcode(char bits[], int x1, int y1, int bar, int h, int color) {
    if (!bits) return;

    for (int i = 0; bits[i] != '\0'; i++) {
        char c = bits[i];
        if (c == '1') {
          
            bmp16_fill_rect(x1, y1, x1 + bar - 1, y1 + h - 1, color);
            x1 += bar;
        } else if (c == '0') {
            x1 += bar;
        } else {
       
        }
    }
}


void make_ean8_bits(const char jan8[], char out[]) {
   
    int len = 0;
    while (jan8[len] != '\0') len++;
    if (len != 8) { out[0] = '\0'; return; }
    for (int i = 0; i < 8; i++) {
        if (jan8[i] < '0' || jan8[i] > '9') { out[0] = '\0'; return; }
    }

    
    const char *LEFT[10] = {
        "0001101",
        "0011001", // 1
        "0010011", // 2
        "0111101", // 3
        "0100011", // 4
        "0110001", // 5
        "0101111", // 6
        "0111011", // 7
        "0110111", // 8
        "0001011"  // 9
    };
    // 右側
    const char *RIGHT[10] = {
        "1110010", // 0
        "1100110", // 1
        "1101100", // 2
        "1000010", // 3
        "1011100", // 4
        "1001110", // 5
        "1010000", // 6
        "1000100", // 7
        "1001000", // 8
        "1110100"  // 9
    };

    
    int p = 0;

   
    out[p++] = '1'; out[p++] = '0'; out[p++] = '1';


    for (int i = 0; i < 4; i++) {
        int d = jan8[i] - '0';
        const char *pat = LEFT[d];
        for (int k = 0; k < 7; k++) out[p++] = pat[k];
    }

    // 中央ガード "01010"
    out[p++] = '0'; out[p++] = '1'; out[p++] = '0'; out[p++] = '1'; out[p++] = '0';

    // 右4桁
    for (int i = 4; i < 8; i++) {
        int d = jan8[i] - '0';
        const char *pat = RIGHT[d];
        for (int k = 0; k < 7; k++) out[p++] = pat[k];
    }

    out[p++] = '1'; out[p++] = '0'; out[p++] = '1';


    out[p] = '\0';
}

int main(void) {
    const char jan8[] = "49602302";


    char bits[70]; // 67文字 + 終端
    make_ean8_bits(jan8, bits);
    if (bits[0] == '\0') {
        // 不正入力時は終了
        return 1;
    }

    bmp16_create(640, 240, 15);

   
    bmp16_draw_barcode(bits, 50, 40, 4, 150, 0);

    bmp16_save("bmp_barcode.bmp");
    system("open bmp_barcode.bmp");

    return 0;
}
