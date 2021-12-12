#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <conio.h>
#include   <time.h>
#define max 100

struct Node{
    char name[50];
    int num;
    int time;
    struct Node *next;
};
struct Node head[max];
typedef struct Node node;

node *root;
node *iter;
node *p;
node *q;

int i,j;

node *fillnum(node *root,int data,int k){
    node *added=(node*)malloc(sizeof(node));
    added->time=data;
    added->num=k;
    added->next=NULL;
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->time=data;
        root->num=k;
        root->next=NULL;
        return (root);
    }
    else{
        p=root;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=added;
        return (root);
    }
}

void print(node *root,node *head){
    iter=root;
    i=0;
    p=head;
    while(iter!=NULL){
        printf("NUMBER : %d\tTIME : %d\tNAME : %s\n",iter->num,iter->time,p[i].name);
        iter=iter->next;
        i++;
    }
    printf("\n");
}
void hipodrom(int n){
    srand(time(NULL));
    int k=1;
    for(i=0; i<2*n; i++){
        for(j=0; j<n; j++){
           if(j==i){
               printf("%d ",k);
               k++;
           }
           else{
               printf("| ");
           }
        }
        printf("\n");
    }
}
void hipodromnew(node *root,int n){
    iter=root;
    for(i=0; i<2*n; i++){
        for(j=0; j<n; j++){
            if(j==i){
                printf("%d ",iter->num);
                 iter=iter->next;
            }
            else{
                printf("| ");
            }
        }
        printf("\n");
    }
}
void order(node *root,int n){
    int i,j,k,temp,temp2;
    char *temp3;
    k=n;
    for(i=0; i<n-1; i++, k--){
        iter=root;
        for(j=1; j<k; j++){
            if(iter->time >iter->next->time){
                temp=iter->time;
                iter->time=iter->next->time;
                iter->next->time=temp;

                temp2=iter->num;
                iter->num=iter->next->num;
                iter->next->num=temp2;

                strcpy(temp3,head[i].name);
                strcpy(head[i].name,head[j].name);
                strcpy(head[j].name,temp3);
            }
            iter=iter->next;
        }

    }
    
}
int main(){
    int i,a,distoftime,horses,hipotez,money,k=1;
    char answer[10];
    srand(time(NULL));
    printf("\nENTER MAX TIME FOR DISTANCE OF HIPODROM and NUMBER OF HORSES\n\n");
    scanf("%d %d",&distoftime,&horses);
    printf("\nENTER NAME OF HORSES\n\n");
    for(i=0; i<horses; i++){
        printf("NAME : ");
        scanf("%s",&head[i].name);
    }
    printf("\n\n");
    printf("\nHIPODROM\n\n");
    hipodrom(horses);
    printf("\n\nWHICH HORSES YOUR FAVORITE : "); scanf("%d",&hipotez);
    printf("\n\nHOW MUCH IS YOUR BET : "); scanf("%d",&money);
    for(i=0; i<horses; i++){
       a=1+rand()%distoftime;
       root=fillnum(root,a,k);
       k++;
    }
    printf("\nHORSES INFORMATION\n");
    print(root,head);
    printf("\nRESULT OF RACE\n\n\n");
    order(root,horses);
    hipodromnew(root,horses);
    printf("\n");
    print(root,head);
    printf("\nWON HORSE IS %s\tITS NUMBER IS %d\tITS TIME IS %d\n\n",head[0].name,root->num,root->time);
    if(hipotez==root->num){
        printf("CONGRATULATIONS, YOU WON %d DOLLARS\n\n",money*2);
    }
    else{
        printf("\nUNFORTUNATELY, YOU LOSE %d DOLLARS\n\n",money*5);
    }
    getch();
    return 0;
}

