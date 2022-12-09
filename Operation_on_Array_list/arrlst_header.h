#define MAX 5
typedef struct Arraylist
{
    int a[MAX];
    int index;
}ARRLST;

//Functions
//Initializing index to -1
void init(ARRLST *pal);
//Appending the entered element to the array list.
int append(ARRLST *pal,int e);
//Deleting the last element in the Array List
int delLast(ARRLST *pal,int *ele);
//Displaying all the elements in the array list
void display(ARRLST *pal);
//Adding Element to the starting of the list
int prepend(ARRLST *pal,int ele);
//Delete from the front
int deletefront(ARRLST *pal,int *ele);
//Inserting the given element at the given position
int insertposition(ARRLST *pal,int ele,int pos);
//Delete the element at a given position
int deleteposition(ARRLST *pal,int *ele,int pos);
//Accessing the element at the given position
int getter(ARRLST *pal,int pos,int *ele);
//Changing the value at pos to ele
int setter(ARRLST *pal,int pos,int ele);



