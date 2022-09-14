#include<stdio.h>
#include<stdlib.h>
#include"csll.h"
void init(CLIST *cl)
{
    cl->head=(NODE*)malloc(sizeof(NODE));
    cl->head->info=-1;
    cl->head->next=cl->head;
}
int create(CLIST *cl){
    NODE *p,*temp;int ch;
    p=cl->head;
    fflush(stdin);
    while((ch=getchar())!='\n'){
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=ch-'0';
        p=cl->head;
        temp->next=p->next;
        p->next=temp;
    }
    return 0;
}
void display(CLIST *cl){
    NODE *p;
    p=cl->head->next;
    if(p==NULL){
        printf("Empty list\n");
    }
    while(p->info!=-1){
        printf("%d",p->info);
        p=p->next;
    }
    printf("\n");
}
int add(CLIST *cl1,CLIST *cl2,CLIST *cl3){
    NODE *p,*q,*r,*temp;
    int sum=0,carry=0;
    p=cl1->head->next;
    q=cl2->head->next;
    r=cl3->head->next;
    while(p->info!=-1 && q->info!=-1){
        sum=p->info+q->info+carry;
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=sum%10;
        carry=sum/10;
        r=cl3->head;
        temp->next=r->next;
        r->next=temp;
        p=p->next;
        q=q->next;
    }
    while(p->info!=-1){
        sum=p->info+carry;
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=sum%10;
        carry=sum/10;
        r=cl3->head;
        temp->next=r->next;
        r->next=temp;
        p=p->next;
    }
    while(q->info!=-1){
        sum=q->info+carry;
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=sum%10;
        carry=sum/10;
        r=cl3->head;
        temp->next=r->next;
        r->next=temp;
        q=q->next;
    }
    //last carry
    if(carry){
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=1;
        r=cl3->head;
        temp->next=r->next;
        r->next=temp;
    }
    return 0;
}