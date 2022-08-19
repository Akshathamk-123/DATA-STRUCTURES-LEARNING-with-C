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
int insertposition(ARRLST *pal,int ele,int pos);
int deleteposition(ARRLST *pal,int ele,int pos);
int getter(ARRLST *pal,int pos,int ele);
int setter(ARRLST *pal,int pos,int ele);
