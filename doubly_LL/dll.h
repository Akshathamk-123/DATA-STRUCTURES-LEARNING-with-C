typedef struct  node
{
    int info;
    struct node *next;
    struct node *prev;
}NODE;
typedef struct linkedlist{
    NODE *head;
}DLIST; 
void init(DLIST *pdl);
int insertfront(DLIST *pdl,int e);
int deletefront(DLIST *pdl,int *e);
int insertlast(DLIST *pdl,int e);
int deletelast(DLIST *pdl,int *e);
int insertposition(DLIST *pdl,int e,int pos);
int deleteposition(DLIST *pdl,int pos,int *e);
int delete_duplicates(DLIST *pdl,int ele);
int count_nodes(DLIST *pdl);
void display(DLIST *pdl);


//implement all above functions using a tail pointer


