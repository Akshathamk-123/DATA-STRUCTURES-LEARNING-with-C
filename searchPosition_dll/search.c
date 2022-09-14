#include <stdio.h>
#include <stdlib.h>
#include "search.h"
void init(DLIST *p)
{
  p->head = NULL; 
}

void create(DLIST *p) {
  int info,wish;
  NODE *temp;
  do {
    temp = (NODE *)malloc(sizeof(NODE));
    if(temp==NULL) return;
    printf("\nEnter info:");
    scanf("%d", &info);
    temp->info = info;
    temp->next = NULL;
    temp->prev=NULL;
    if(p->head == NULL)
      p->head=temp;
    else if(p->head->info>=temp->info)
    {
      temp->next=p->head;
      temp->next->prev=temp;
      p->head=temp;      
    }
    else
    {
      NODE*cur=p->head;
      while((cur->next)!=NULL && cur->next->info < temp->info)
        cur=cur->next;
      temp->next=cur->next;
      if(cur->next!=NULL)
        temp->next->prev=temp;
      cur->next=temp;
      temp->prev=cur;
    }
    printf("Do you want to enter again(yes-1/no-0):");
    scanf("%d", &wish);
  } while (wish);
}

int search(DLIST* d,int e)
{
  if (d->head == NULL)
    printf("empty");
  else{
    NODE* p=d->head;
    while(p!=NULL)
      {
        if (p->info==e) return 1;
        p=p->next;
      }
    return 0;
    }
}



void display(DLIST *p) {
  if (p->head == NULL)
    printf("empty");
  else {
    NODE* d = p->head;
    while (d != NULL) {
      printf(" %d", d->info);
      d = d->next;
    }
  }
}