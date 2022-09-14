//STACK USING ARRAY IMPLEMENTATION
/*#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
void init(STACK *ps){
    ps->top=-1;
}
int push(STACK *ps,int e){
    if(isFull(ps))    return 0;
    ps->top++;
    ps->s[ps->top]=e;
        return 1;
}
int pop(STACK *ps,int *pe){
    if(isEmpty(ps)) return 0;
    *pe=ps->s[ps->top];
    ps->top--;
        return 1;
}
int peek(STACK *ps,int *pe){
    if(isEmpty(ps))  return 0;
    *pe=ps->s[ps->top];
    return 1;
}
int isEmpty(STACK *ps){
   return(ps->top==-1)?1:0;
}
int  isFull(STACK *ps){
    return(ps->top==MAX-1)?1:0;
}
void display(STACK *ps){
    if(isEmpty(ps)) {
        printf("Empty Stack\n");
    }
    else{
    for(int i=0;i<=ps->top;i++){
        printf("%d",ps->s[i]);
    }}
}*/

#include<stdio.h>     
#include<stdlib.h>
#include"stack.h"
void init(LLIST *pl){
    pl->head=NULL;
}
int push(LLIST *pl,int e){
    NODE *temp;
    if(temp==0) return 0;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp->next=pl->head;
    pl->head=temp;
    return 1;
}
int pop(LLIST *pl,int *e){
    NODE *p;
    p=pl->head;
    if(pl->head==NULL)  return 0;
    pl->head=p->next;
    *e=p->info;
    free(p);
    return 1;
}
int peek(LLIST *pl,int *e){
    NODE *p;
    p=pl->head;
    if(pl->head==NULL)  return 0;
    *e=p->info;
    return 1;
}
void display(LLIST *pl){
    NODE *p;
    p=pl->head;
    if(p==NULL) printf("Empty list\n");
    else{
        while(p!=NULL)
        {
            printf("%d\t",p->info);
            p=p->next;
        }
    }
}