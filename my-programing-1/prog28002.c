#include<stdio.h>

void func2(int *p){
    int i=0;
    while(i<3){
        *p *=2;
        p++;
        i++;
    }
    
    

}

int main(void)
{
int a[3] ={ 1, 2, 3};
func2(&a[0]);
printf("%d %d %d\n", a[0], a[1], a[2]);

return 0;
}


   