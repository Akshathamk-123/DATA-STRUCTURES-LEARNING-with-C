#include<stdio.h>     
#include<stdlib.h>
#include"dll.h"
void init(DLIST *pdl){
    pdl->head=NULL;
}
int insertfront(DLIST *pdl,int e){
    NODE *p,*q,*temp;
    p=pdl->head;q=NULL;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp->next=temp->prev=NULL;
    if(temp==0) return 0;
    else{if(p==NULL){
        pdl->head=temp;
    }
    else
    {
        temp->next=p;
        p->prev=temp;
        pdl->head=temp;
    }
    return 1;
    }
}
int deletefront(DLIST *pdl,int *e){
    NODE *p;
    p=pdl->head;
    if(p==NULL) return 0;
    else{
        if(p->prev==NULL && p->next==NULL){
            pdl->head=NULL;
            free(p);
        }
        else{
            pdl->head=p->next;
            pdl->head->prev=NULL;
            p->next=NULL;
            free(p);
        }
        return 1;
    }
}
int insertlast(DLIST *pdl,int e){
    NODE *p,*q,*temp;
    p=pdl->head;q=NULL;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp->next=temp->prev=NULL;
    if(temp==0) return 0;
    else{if(p==NULL){
        pdl->head=temp;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
}
}
int deletelast(DLIST *pdl,int *e){
    NODE *p,*q;
    p=pdl->head;
    q=NULL;
    if(p==NULL)  return 0;
    else{
     if(p->prev==NULL && p->next==NULL){
            pdl->head=NULL;
             *e=p->info;
            free(p);
        }
        else{
            while(p->next!=NULL){
                q=p;
                p=p->next;
            }
             *e=p->info;
            q->next=NULL;
            p->prev=NULL;
            free(p);
        }
        return 1;   
    }
}
int insertposition(DLIST *pdl,int e,int pos){
    NODE *p,*q,*temp;int wish,count=1;
    q=NULL;
    p=pdl->head;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp->next=temp->prev=NULL;
    if(temp==0)  return 0;
    if(p==NULL || pos==1){
        pdl->head=temp;
    }
    else if(p==NULL && pos>1){
        printf("List is empty\nDo you want to insert at front(y-1/n-0)\n");
        scanf("%d",&wish);
        if(wish){
            pdl->head=temp;
        }
    }
    else{
        if(pos==1){
            temp->next=p;
            p->prev=temp;
            pdl->head=temp;
        }
        else{
            while(p!=NULL && count<pos){
                q=p;
                p=p->next;
                count++;
            }
            q->next=temp;
            temp->next=p;
            temp->prev=q;
            p->prev=temp;
        }
        return 1;
    }

}
int deleteposition(DLIST *pdl,int pos,int *e){

}
int delete_duplicates(DLIST *pdl,int e){
    NODE *p,*q;
    p=pdl->head;
    if(p==NULL)  return 0;
    else{
        while(p!=NULL && p->info!=e){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        p->next->prev=q;
        p->prev=p->next=NULL;
        free(p);
        return 1;
    }
}
int count_nodes(DLIST *pdl){
    NODE *p;int count=0;
    p=pdl->head;
    if(p==NULL) return 0;
    else{
        while(p!=NULL)
        {
            p=p->next;
            count++;
        }
    return count;
    }
}
void display(DLIST *pdl){
    NODE *p;
    p=pdl->head;
    if(p==NULL) printf("Empty list\n");
    else{
        while(p!=NULL)
        {
            printf("%d\t",p->info);
            p=p->next;
        }
    }
}
