#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int pow , coeff;
    char sign;
    struct Node *next;
};


void pushBegin(char s , int co , int p , struct Node **last){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->pow = p;
    temp->coeff = co;
    temp->sign = s;
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
    char s;
    for(int i=0;i<x;i++){
        printf("Enter sign coefficient and power : ");
        scanf(" %s %d %d",&s,&c,&p);
        pushBegin(s,c,p,&(*last));
    }
}

int calc(struct Node **p1 , struct Node **p2 ,struct Node **res){
    if((*p1)->sign == (*p2)->sign){
        int ans = (*p1)->coeff + (*p2)->coeff;
        pushBegin((*p1)->sign , ans , (*p1)->pow , &(*res));      
    }
    else{
        int v1 = (*p1)->coeff;
        int v2 = (*p2)->coeff; 
        char s;
        if(v1 > v2){
            int ans = v1-v2;
            pushBegin((*p1)->sign, ans , (*p1)->pow , &(*res));           
        }
        else{
            int ans = v2-v1;
            pushBegin((*p2)->sign, ans , (*p1)->pow , &(*res));           
        }
    }    
}

void compareEq(struct Node **p1 , struct Node **p2 , struct Node **res){
    struct Node *ptr1 = (*p1)->next;
    struct Node *ptr2 = (*p2)->next;

    do{
        if(ptr1->pow == ptr2->pow){
            calc(&ptr1,&ptr2,&(*res));           
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }        
        else{
            if(ptr1->pow > ptr2->pow){
                pushBegin(ptr1->sign , ptr1->coeff , ptr1->pow , &(*res));
                ptr1 = ptr1->next;
            }                     
            else{
                pushBegin(ptr2->sign , ptr2->coeff , ptr2->pow , &(*res));
                ptr2 = ptr2->next;
            }
        }
    }while(ptr1!=(*p1)->next && ptr2!=(*p2)->next);

}

void viewList(struct Node **last){
    struct Node *temp = (*last)->next;
    do{
        printf("%c%dx^%d  " , temp->sign,temp->coeff , temp->pow);
        temp=temp->next;
    }while(temp!=(*last)->next);
}
int main(){   
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *res = NULL;

    int n1,n2;
    printf("Enter no. of terms for equation 1 and 2 :");
    scanf("%d %d",&n1,&n2);

    generateEquation(n1,&p1);
    generateEquation(n2,&p2);

    compareEq(&p1,&p2,&res);

    viewList(&p1);
    printf("\n");
    viewList(&p2);
    printf("\nAnswer : \n");
    viewList(&res);
}