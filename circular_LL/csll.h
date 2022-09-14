#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}NODE;
typedef struct list
{
    NODE *head;
}CLIST;
void init(CLIST *cl);
int create(CLIST *cl);
int add(CLIST *cl1,CLIST *cl2,CLIST *cl3);
void display(CLIST *cl);

