#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"
void init(LIST *pl){
    pl->head=NULL;
}
int create(LIST *pl){
    NODE *temp;
    int co,po,choice;
    do{
        printf("Enter the coefficient and power in ascending order\n");
        scanf("%d %d",&co,&po);
        temp=(NODE*)malloc(sizeof(NODE));
        temp->coeff=co;
        temp->pow=po;
        temp->next=NULL;
        temp->next=pl->head;
        pl->head=temp;
        printf("Do you want to enter another term(yes-1/no-0)\n");
        scanf("%d",&choice);
    }while(choice);
}
int add(LIST *pl1,LIST *pl2,LIST *pl3){
    NODE *p,*q,*s;
    p=pl1->head;
    q=pl2->head;
    while((p!=NULL)&&(q!=NULL)){
        s=(NODE*)malloc(sizeof(NODE));
        //s->next=NULL;
    if(p->pow==q->pow){
           s->coeff= p->coeff+q->coeff;
           s->pow=p->pow;
           p=p->next;
            q=q->next;
        }
        //s=s->next;
    else if((p->pow)>(q->pow)){
       s=(NODE*)malloc(sizeof(NODE));
        s->coeff=p->coeff;
        s->pow=p->pow;
        s->next=pl1->head;
        pl1->head=s;
        p=p->next;
    }
    else{
        s=(NODE*)malloc(sizeof(NODE));
        s->coeff=q->coeff;
        s->pow=q->pow;
        s->next=pl2->head;
        pl2->head=s;
        q=q->next;
    }
    //link to third list
    s->next=pl3->head;
    pl3->head=s;
    }//end while
    while(p!=NULL){
        s=(NODE*)malloc(sizeof(NODE));
        s->coeff=p->coeff;
        s->pow=p->pow;
        p=p->next;
        s->next=pl3->head;
        pl3->head=s;
    }
    while(q!=NULL){
        s=(NODE*)malloc(sizeof(NODE));
        s->coeff=q->coeff;
        s->pow=q->pow;
        q=q->next;
        s->next=pl3->head;
        pl3->head=s;
    }
}
void display(LIST *pl){
    NODE *p;
    p=pl->head;
    if(p==NULL){
        printf("Empty list\n");
    }
    else{
        while(p!=NULL){
            printf("(%d,%d)\t",p->coeff,p->pow);
            p=p->next;
        }
    }
}
