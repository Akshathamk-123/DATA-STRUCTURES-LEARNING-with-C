typedef struct node
{
    int info;
    struct node *next;
}NODE;

typedef struct LinkedList
{
    NODE *head;
}LLIST;

void init(LLIST *pl);
int insertFront(LLIST *pl, int e);//case 1
int deleteFront(LLIST *pl, int *pe);//case 2
void disp(LLIST *pl);//case 3
int deleteLast(LLIST *pl,int *pe);//case 4
int insertLast(LLIST *pl,int ele);//case 5
int insertposition(LLIST *pl,int pos,int ele);//case 6
int deleteposition(LLIST *pl,int pos,int *ele);//case  7
int deletegivenele(LLIST *pl,int given);//case 8
/*
//Not done yet
int movembackwardbynfrombeg(LLIST *pl, int m,int n);//case 10 
int create();//Just a funtion not a part of the switch case
int noofnodes(LLIST *pl);//case 9
int movemforwardbynfrombeg(LLIST *pl, int m,int n);//case 11
int mergeol(LLIST *pl1,LLIST *pl2);//case 12

*/
