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

/*There are 3 Combinations 
1) Preorder
2) Inorder
3) Postorder
All of the above are done in a recursive manner
*/
//This is BST
/*PREORDER
1)visit the root (V)
2)Traverse the LST in Preorder
3) Traverse the RST in Preorder
Visit the root-
traverse all the left subtree and when there is no left subtree left go back to the 
*/

/*INORDER
1)Traverse the LST in Inorder
2)visit the root (V)
3) Traverse the RST in Inorder
*/

/*POSTORDER
1)Traverse the LST in Postorder
2)Traverse the RST in Postorder
3)visit the root (V)
*/

void init(TREE *pt)
{
    pt->root=NULL;
}

int count(NODE *r)
{
    if(r==NULL) return 0;
    return (1+count(r->left)+count(r->right)) 
}
NODE* create_node(int e)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=e;
    temp-> left=NULL;
    temp->right=NULL;
    return temp;
}
void create(TREE *pt)
{
    NODE *temp,*q,*p;
    int ele,wish;
    printf("Enter the root ele");
    scanf("%d",&ele);
    pt->root=create_node(ele);
    do{
        printf("Enter the element");
        scanf("%d",&ele);
        temp=create_node(ele);
        q=NULL;
        p=pt->root;
        while(p!=NULL)
        {
            q=p;
            if(ele<p->info)
            p=p->left;
            else
            p=p->right;
        }
        if(ele<q->info)
        q->left=temp;
        else
        q->right=temp;
        printf("Do you want to add another node");
        scanf("%d",&wish);
    }while(wish);
}
void preo(NODE *r)
{
    if(r!=NULL)
    {
        printf("%d\t",r->info);
        preo(r->left);
        preo(r->right);
    }
}
void preorder(TREE *pt)
{
    preo(pt->root);
}

void posto(NODE *r)
{
    if(r!=NULL)
    {
        posto(r->left);
        posto(r->right);
        printf("%d\t",r->info);
    }
}
void postorder(TREE *pt)
{
    posto(pt->root);
}

void io(NODE *r)
{
    //  This is the main recursive function
    if(r!=NULL)
    {
        io(r->left);
        printf("%d\t",r->info);
        io(r->right);
    }
}

void inorder(TREE *pt)
{
    //This is acting as a wrapper function 
    io(pt->root);
}

int main()
{
    TREE t;
    int choice;
    init(&t);
    create(&t);
    printf("Which one do you choose\n 1)Inorder traversal\n 2)Preorder traversal\n 3)Postorder traversal\n 4)Count the number of Nodes in the tree");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            inorder(&t);break;
        case 2:
            preorder(&t);break;
        case 3:
            postorder(&t);break;
        case 4:
            count(NODE *r);break;
    }
}

