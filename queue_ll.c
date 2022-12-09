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
int enqueue(LLIST *pl,int e);
int dequeue(LLIST *pl,int *e);
void display(LLIST *pl);
int main()
{
    LLIST l,l1,l2;
    int choice,ele,k,pos;
    init(&l);
    do{
        printf("Enter your choice\n");
        printf("1.enqueue\n2.dequeue\n3.display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter element to be inserted\n");
               scanf("%d",&ele);
               k=enqueue(&l,ele);
               if(k==0) printf("invalid element\n");
               else printf("Successful insertion\n");
        break;
        case 2:k=dequeue(&l,&ele);
               if(k==0) printf("list empty\n");
               else printf("The element deleted is %d\n",ele);
        break;
        case 3:display(&l);
        break;
        }
    }while(choice<4);
    return 0;
}
void init(LLIST *pl){
    pl->head=NULL;
}
int enqueue(LLIST *pl,int e){
    NODE *p,*temp;
    if(temp==0) return 0;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp->next=NULL;
    p=pl->head;
    if(p==NULL){
        temp->next=pl->head;
        pl->head=temp;
    }
    else{
        //p=pl->head;
    while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
        return 1;
}
int dequeue(LLIST *pl,int *e){
   NODE *p;
    p=pl->head;
    if(pl->head==NULL)  return 0;
    pl->head=p->next;
    *e=p->info;
    free(p);
    return 1;
}
void display(LLIST *pl){
    NODE *p;
    p=pl->head;
    if(p==NULL) printf("Empty queue\n");
    else{
        while(p!=NULL)
        {
            printf("%d\t",p->info);
            p=p->next;
        }
    }
}

