char reservation_list[5][100] = { "YAMADA", "SUZUKI", "TANAKA", "SAITO", "KOBAYASHI", };
int column;
char row='X';
int flag;

#include <stdio.h>
#include<string.h>

void check_name(char *name)
{
    int i; 


    for (i = 0; name[i] != '\0'; i++) { 
        
        // str[i]の文字が小文字（'a'から'z'）の範囲にあるか確認する [5, 11, 12]
        if (name[i] >= 'a' && name[i] <= 'z') {
            
            name[i] = name[i] - ('a' - 'A');
            
        } 
    }

   
    

}
int check_reservation(char *name){
    int i=0;
    
        while(i<5){
            if(strcmp(name,reservation_list[i])==0){
            return 1;
        }else{
            return 0;
        }
        
    
    }
    }
void separate(char *input, int *column, char *row){
        
        row=&input[1];
       
        column=&input[0]-'0';
        
    }
    void checked_baggage(void)
    {
        static int count=0;
        count++;
        if(count<3){
            printf("%d個目の荷物を預かりました\n",count);
        }else{
            printf("預けられる上限を超えています\n");
        }
    }
    int main(void)
{
    char name[100];

    printf("名前を入力してください:");
    scanf("%s", name);

    check_name(name);
    int result = check_reservation(name);
    if (result == 1) {
        printf("予約を確認しました\n");
    } else {
        printf("予約を確認できませんでした\n");
    }
    char input[3];
    printf("座席指定(例5A):");
    scanf("%s", input);

    separate(input, &column, &row);

    printf("%d行%c列のお席で承りました。\n", column, row);

    while(1){
        printf("荷物を預けますか yes:1 no:0");
        scanf("%d",&flag);
        if(flag==1){
        checked_baggage();
        }else{
            break;
        }
    }
    return 0;
}