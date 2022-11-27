#include<stdio.h>
#include<stdlib.h>

struct Node{
    int pow , coeff;
    struct Node *next;
};


void pushBegin(int co , int p , struct Node **last){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->pow = p;
    temp->coeff = co;
    if(*last==NULL){
        temp->next = temp;
        (*last) = temp;
    }
    else{
        temp->next = (*last)->next;
        (*last)->next = temp;
    }
}

void generateEquation(int x , struct Node **last){
    int p,c;
    for(int i=0;i<x;i++){
        printf("Enter coefficient and power : ");
        scanf("%d %d",&c,&p);
        pushBegin(c,p,&(*last));
    }
}

void viewList(struct Node **last){
    struct Node *temp = (*last)->next;
    do{
        printf("%dx^%d  " , temp->coeff , temp->pow);
        temp=temp->next;
    }while(temp!=(*last)->next);
}
int main(){
    // pushBegin(1,3,&last);
    // pushBegin(2,4,&last);
    // pushBegin(3,3,&last);
    // viewList(&last);

    struct Node *p1 = NULL;
    struct Node *p2 = NULL;

    int n1,n2;
    printf("Enter no. of terms for equation 1 and 2 :");
    scanf("%d %d",&n1,&n2);

    generateEquation(n1,&p1);
    generateEquation(n2,&p2);

    viewList(&p1);
    printf("\n");
    viewList(&p2);
}