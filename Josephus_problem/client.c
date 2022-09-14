#include<stdio.h>
//This is for input and output 
#include<stdlib.h>
//This is for malloc, rand()

typedef struct node
{
    int info;
    struct node *next;
}NODE;
typedef struct client
{
    NODE *head;
}CLIST;

void init(CLIST *pcl)
{
    pcl->head=NULL;
}
int create(CLIST *pcl)
{NODE *temp,*p;int size=0,wish;
    do
    {
        temp=(NODE*)malloc(sizeof(NODE));
        printf("Enter the element to be inserted");
        scanf("%d",&temp->info);
        size++;
        if(pcl->head==NULL)//List is empty 
        {
            pcl->head=temp; temp->next=temp;
        }
        else{//Non-empty condition 
            p=pcl->head;
            while(p->next!=pcl->head)
            {
                p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
        printf("do you want to add another number");
        scanf("%d",&wish);
    }while(wish);
    return size;
}
void disp(CLIST *pcl)
{
    NODE *p;
    p=pcl->head;
    if(pcl->head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while(p->next!=pcl->head)
        {
            printf("%d\t",p->info);
            p=p->next;
        }
        printf("%d\n",p->info);
    }
}
int winner(CLIST *pcl,int start,int skip)
{
    int cnt=1,cnt1=1;
    NODE *p=pcl->head;
    NODE *q=NULL;
    while(cnt!=start)
    {
        q=p;
        p=p->next;cnt++;
    }
    while(p->next!=p)
    {
        while(cnt1!=skip)
        {
            q=p;
            p=p->next;
            cnt1++;
        }
        q->next=p->next;
        free(p);
        p=q->next;
    }
    return p->info;
}


int main()
{
    CLIST cl;
    init(&cl);
    int s= create(&cl);
    disp(&cl);
    int start=rand()%s;
    int skip= rand()%s;
    printf("%d\n",winner(&cl,start,skip));
    return 0;
}