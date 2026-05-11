#include <stdio.h>

int ean8_checkdigit(char buffer[]) {

int sum = 0;
/*ここを書いて*/
int i = 0;

while(i<=8){
    if(i%2==1){
    sum=sum+3*(buffer[i]-48);
    i++;
}else{
    sum=sum+buffer[i]-48;
    i++;
}
}
int mod = sum % 10;
int cd = (10 - mod) % 10;
return cd;

}

int main(void)
{

char buffer[] = "4507546x";
int cd = ean8_checkdigit(buffer);
printf("%s:%d\n", buffer, cd); // 4507546x:9

}