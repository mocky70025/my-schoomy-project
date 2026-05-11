/*#include <stdio.h>

struct character {
    char *name;
    int hp;
    int attack;
    int defense;
};
struct character2 {
    char *name;
    char *attribute;
    int hp;
    int attack;
    int defense;

};


int main() {
    struct character hero = {"勇者", 100, 30, 20};
    struct character wizard ={"魔法使い",80,60,10};
    struct character2 doremi={"どれみ","ふしぎなまもり",1,50,50};
    struct character aaaa={"ああああ",10,10,10};
    struct character2 aaaa2={"ああああ(覚醒)","もはや神",255,255,255};
    printf("名前: %s\n", hero.name);
    printf("HP: %d\n",   hero.hp);
    printf("\n名前: %s\n", wizard.name);
    printf("HP: %d\n",   wizard.hp);
    printf("\n名前: %s\n", doremi.name);
    printf("HP: %d\n",   doremi.hp);
    printf("特性: %s\n",  doremi.attribute);
    printf("\n名前: %s\n", aaaa.name);
    printf("HP: %d\n",   aaaa.hp);
    printf("\n名前: %s\n", aaaa2.name);
    printf("HP: %d\n",   aaaa2.hp);


    return 0;
}
*/

/*#include<stdio.h>
#include <string.h>
typedef struct{
    int studentId;
    int number;
    char name[50];
    float grade;
}Student;

int main(){
    Student student1={2499,299,"神山四角子",88.5};
    printf("学籍番号: %d\n",  student1.studentId);
    printf("出席番号: %d\n",  student1.number);
    printf("氏名: %s\n",      student1.name);
    printf("成績: %.1f\n",    student1.grade);
    return 0;
}*/


#include <stdio.h>
#include <string.h>

typedef struct {
    int studentId;
    int number;
    char name[50];
    float grade;
    char reason_to_live[50];
} Student;
void printStudent(Student name){
    printf("学籍番号：%d 名前：%s 成績；%0.2f 生きる理由：%s\n",name.studentId,name.name,name.grade,name.reason_to_live);
}

int main() {
    Student student1;
    Student student2;
    Student student3;
    Student motoki ={2515,214,"もとき",3.52,"死ぬのが怖いから"};
    Student sachiko ={2519,218,"さちこ",100,"4階から飛び降りるのが怖かったから"};
    Student yuriko ={2521,220,"ゆりこ",36.5,"みかんを食べたいから"};
    printStudent(motoki);
    printStudent(sachiko);
    printStudent(yuriko);

    return 0;
}
