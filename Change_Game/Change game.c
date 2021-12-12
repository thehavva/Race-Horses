#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int i,j;
int calculate(int *str,int size);
void change(int *str,int a);
int main(){
    srand(time(NULL));
    int *arr,a,b,toplam1=0,toplam2=0;
    char answer[10];
    arr=(int*)malloc(sizeof(int)*5);
    do{
    for(i=0; i<5; i++){
        arr[i]=rand()%53;
    }
    printf("Your card numbers :\n\n");
    for(i=0; i<5; i++){
        printf("%d\t",*(arr+i));
    }
    toplam1=calculate(arr,5);
    printf("\nYour score is %d",toplam1);
    printf("\n\nwhich index of your array you want to throw?\n\n");
    scanf("%d",&a);
    printf("\n%d.index will be thrown.\n",a);
    change(arr,a);
    b=rand()%53;
    arr[4]=b;
    printf("\n%d is your new card number\n",b);
    printf("\n\nNew your card numbers :\n\n");
    for(i=0; i<5; i++){
        printf("%d\t",*(arr+i));
    }
    toplam2=calculate(arr,5);
    printf("\nNew your score is %d\n",toplam2);
    if(toplam1==toplam2){
        printf("\n\nThank God you didn't lose money, go home!");
    }
    else if(toplam1>toplam2){
        printf("\n\nYou took a risk and unfortunately lost, please pay %d dollars!",(toplam1-toplam2)*1000);
    }
    else if(toplam2>toplam1){
        printf("\n\nCongratulations you have earned % d dollars.",(toplam2-toplam1)*500);
    }
        printf("\nDo you want to continue,yes or no?\n");
        scanf("%s",answer);
    }while(strcmp(answer,"no")!=0);
    
    free(arr);
    getch();
    return 0;
}
int calculate(int *str,int size){
    int result=0;
    for(i=0; i<5; i++){
        if(*str>=1 && *str<=10){
            result+=(*str);
        }
        else if(*str>=11 && *str<=20){
            result+=3;
        }
        else if(*str>=21 && *str<=45){
            result+=5;
        }
        else if(*str>=46 && *str<=52){
            result+=10;
        }
        str++;
    }
    return result;
}
void change(int *str,int a){
    for(i=0; i<5; i++){
        if(i==(a-1)){
            continue;
        }
        printf("%d\t",str[i]);
    }
}
