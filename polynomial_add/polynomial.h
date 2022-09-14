typedef struct node
{
    int coeff;
    int pow;
    struct node* next;
}NODE;
typedef struct list{
    NODE *head;
}LIST;
void init(LIST *pl);
int create(LIST *pl);
int add(LIST *pl1,LIST *pl2,LIST *pl3);
void display(LIST *pl);
