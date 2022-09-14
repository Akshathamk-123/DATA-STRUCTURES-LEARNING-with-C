/*#define MAX 10
typedef struct stack
{
    int s[MAX];
    int top;
}STACK;
void init(STACK *ps);
int push(STACK *ps,int e);
int pop(STACK *ps,int *pe);
int peek(STACK *ps,int *pe);
int isEmpty(STACK *ps);
int  isFull(STACK *ps);
void display(STACK *ps);*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}NODE;
typedef struct linkedlist{
    NODE *head;
}LLIST; 
void init(LLIST *pl);
int push(LLIST *pl,int e);
int pop(LLIST *pl,int *e);
int peek(LLIST *pl,int *e);
void display(LLIST *pl);