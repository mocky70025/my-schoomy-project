#include "kmc_lib.h" // これで上のファイルを読み込める

int main() {
    const char words[] = "sure here is a shorter version that still follows the same rule and keeps flowing without commas or periods so it feels like one long breath and the words just keep linking together while the image shifts from the sound of rain to the glow of streetlights to the quiet feeling of walking alone at night under the sky";
    printf("タイピングへようこそ!以下の文字を入力してください\n");
    printf("%s\n",words);
    printf("(何かキーを押したら開始します)\n");
    kmc_typingmode(); // タイピングモードにする
    getchar();
    printf("Game Start!\n");
    int i =0;
    for(i=0;words[i]!=0;i++){
        if(!kmc_keypressed(1)){
            break;
        }
        int key = getchar();
        if(key!=words[i]){
            printf("miss!\n");
            break;
        }
        if (key == 'a') {
            printf("\xF0\x9F\x8D\xBB"); 
        } else if (key == 'b') {
            printf("\xF0\x9F\x8D\xBA "); 
        } else if (key == 'c') {
            printf("\xF0\x9F\x9A\xAC "); 
        } else if (key == 'd') {
            printf("\xE2\x98\x95 "); 
        } else if (key == 'e') {
            printf("\xF0\x9F\x95\xBA ");
        } else if (key == 'f') {
            printf("\xF0\x9F\x8E\xA4 "); 
        } else if (key == 'g') {
            printf("\xF0\x9F\x92\xB4 "); 
        } else if (key == 'h') {
            printf("\xF0\x9F\x8D\x9C ");
        } else if (key == 'i') {
            printf("\xF0\x9F\x8E\xB0 ");
        } else if (key == 'j') {
            printf("\xF0\x9F\x93\xB1");
        } else if (key == 'k') {
            printf("\xF0\x9F\x92\x83"); 
        } else if (key == 'l') {
            printf("\xF0\x9F\x8D\xA3"); 
        } else if (key == 'm') {
            printf("\xF0\x9F\x8E\xAB"); 
        } else if (key == 'n') {
            printf("\xF0\x9F\x97\xA3\xEF\xB8\x8F"); 
        } else if (key == 'o') {
            printf("\xF0\x9F\x98\x86");
        } else if (key == 'p') {
            printf("\xF0\x9F\x92\xB5"); 
        } else if (key == 'q') {
            printf("\xF0\x9F\x8C\x84");
        } else if (key == 'r') {
            printf("\xF0\x9F\x8E\xA1"); 
        } else if (key == 's') {
            printf("\xF0\x9F\xA5\x82"); 
        } else if (key == 't') {
            printf("\xF0\x9F\xA5\xAD");
        } else if (key == 'u') {
            printf("\xF0\x9F\x8E\xB6"); 
        } else if (key == 'v') {
            printf("\xF0\x9F\xA5\xB3"); 
        } else if (key == 'w') {
            printf("\xF0\x9F\x93\xB8");
        } else if (key == 'x') {
            printf("\xF0\x9F\x9A\xAC"); 
        } else if (key == 'y') {
            printf("\xF0\x9F\x93\xB7"); 
        } else if (key == 'z') {
            printf("\xF0\x9F\x92\xA4\n");
        } else if (key == ' ') {
            printf(" ");
        } else {
            printf("miss!");
            break; // その他のキーを押すと終了する
        }
    }
    if(words[i]==0){
        printf("\n(絵文字)Game Clear(絵文字)\n");
    } else {
        printf("\nGame Over!\n");
    }
    return 0;
}