#include <stdio.h>

char ask(const char *question) {
    char q;
    do {
        printf("%s (Y/N): ", question);
        scanf(" %c", &q);
        if (q == 'Y' || q == 'y' || q == 'N' || q == 'n') {
            return q; 
        }
    } while (1); 
}

int main(void) {
    printf("🦁🐺 動物占い 🐢🐧\n\n");

    if (ask("Q1: あなたは行動的ですか？") == 'Y') {
        if (ask("Q2: 初対面の人と話すのは得意ですか？") == 'Y') {
            if (ask("Q3: 計画を立ててから動くほうですか？") == 'Y') {
                printf("\n🦁 ライオンタイプ\n");
                printf("リーダー気質で堂々としており、決断力が高いタイプです。\n");
            } else {
                printf("\n🐺 オオカミタイプ\n");
                printf("独自の世界観を持ち、個性を大切にするタイプです。\n");
            }
        } else {
            if (ask("Q4: 思いついたらすぐ行動に移しますか？") == 'Y') {
                printf("\n🐒 サルタイプ\n");
                printf("明るく好奇心旺盛で、ムードメーカーになりやすいタイプです。\n");
            } else {
                printf("\n🐼 パンダタイプ\n");
                printf("穏やかで調和を大切にし、誰とでも仲良くできるタイプです。\n");
            }
        }
    } else {
        if (ask("Q5: 一人で過ごす時間が好きですか？") == 'Y') {
            if (ask("Q6: コツコツと同じ作業を続けられますか？") == 'Y') {
                printf("\n🐢 カメタイプ\n");
                printf("コツコツ努力を積み重ねる堅実で着実なタイプです。\n");
            } else {
                printf("\n🦌 シカタイプ\n");
                printf("品があり、落ち着きがあり、周囲から信頼されるタイプです。\n");
            }
        } else {
            if (ask("Q7: 気分によって行動が変わりやすいほうですか？") == 'Y') {
                printf("\n🦊 キツネタイプ\n");
                printf("感性が鋭く、ひらめきや表現力に優れるタイプです。\n");
            } else {
                printf("\n🐧 ペンギンタイプ\n");
                printf("自分のペースと世界観を大切にする自由なタイプです。\n");
            }
        }
    }

    return 0;
}