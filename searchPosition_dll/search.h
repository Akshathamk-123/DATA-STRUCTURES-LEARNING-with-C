#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
    struct node *prev;
}NODE;
typedef struct list{
    NODE *head;
}DLIST;
void init(DLIST *dl);
void create(DLIST *dl);
int search(DLIST *dl,int ele);
void display(DLIST *dl);
