#define MAX 5
typedef struct Arraylist
{
    int a[MAX];
    int index;
}ARRLST;

//Functions
void init(ARRLST *pal);
int append(ARRLST *pal,int e);
int delLast(ARRLST *pal,int *ele);
void display(ARRLST *pal);
int prepend(ARRLST *pal,int ele);
int deletefront(ARRLST *pal,int* ele);
