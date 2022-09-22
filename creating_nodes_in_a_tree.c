#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left,*right;
}NODE;

typedef struct tree
{
    NODE *root;
}TREE;

NODE* create_node(int e)
{
    NODE *temp;
    temp =(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void create(TREE *pt)
{
    NODE *temp,*p,*q;
    int wish;
    q=NULL;
    p=pt->root;
    printf("Enter the element");
    scanf("%d",&ele);
    pt->root=create_node(ele);
    do
    {
        printf("Enter the element");
        scanf("%d",ele);
        temp=create_node(ele);
        while(p!=NULL)
        {
            q=p;
            if(ele<p->info)
            p=p->left;
            else
            p=p->right;
        }
        if(ele<q->info)
        setleft(q,temp);
        else
        setright(q,temp);
        
        printf("Do you want to enter more elements");
        scanf("%d",&wish);

    } while (wish);
    
}
int main()
{
    TREE t;
    init(&t);
    create(&t);
    return 0;
}