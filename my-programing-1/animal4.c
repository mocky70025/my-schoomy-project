#include <stdio.h>

int main(void) {
    char q1, q2, q3;
    printf("🦁🐺 動物占い 🐢🐧\n\n");

    do{
        printf("Q1: あなたは行動的ですか？ (Y/N): ");
    scanf(" %c", &q1);
    }while(q1!='Y'&&q1!='N');
    if (q1 == 'Y') {
        do{
            printf("Q2: 初対面の人と話すのは得意ですか？ (Y/N): ");
        scanf(" %c", &q2);
        }while(q2!='Y'&&q2!='N');
        if (q2 == 'Y') {
            printf("\n🦁 ライオンタイプ\n");
            printf("\nリーダー気質で堂々としており、決断力が高いタイプです。\n");
        } else {
            printf("\n🐺 オオカミタイプ\n");
            printf("\n独自の世界観を持ち、個性を大切にするタイプです。\n");
        }

    } else {
        do{
        printf("Q3: 一人で過ごす時間が好きですか？ (Y/N): ");
        scanf(" %c", &q3);
        }while(q3!='Y'&&q3!='N');
        if (q3 == 'Y') {
            printf("\n🐢 カメカメタイプ\n");
            printf("\nコツコツ努力を積み重ねる堅実で着実なタイプです。\n");
        } else {
            printf("\n🐧 ペンギンタイプ\n");
            printf("\n自分のペースと世界観を大切にする自由なタイプです。\n");
        }
    }

    return 0;
}