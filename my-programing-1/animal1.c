#include <stdio.h>
int main(void) {
char q1;
printf("@動物占い &\n/n");
printf("01： あなたは行動的ですか？（Y/N）：");
scanf(" %c", &q1);
if (q1 =='Y'||q1=='y'){
printf("\n⑥ライオンタイプ\n");
printf("リーダー気質で堂々としており、決断力が高いタイプです。1n");
} else{
printf("\nペンギンタイプ\n");
printf("自分のペースと世界観を大切にする自由なタイプです。\n");
return 0;
}}