#include<stdio.h>
#include "arrlst_header.h"
void init(ARRLST *pal)
{
    //Initializing index to -1
    //Initially the index will be some random value but we want to initialize to -1 to make sure we can access it easily
    pal->index= -1;
}

//Appending the entered element to the array list.
int append(ARRLST *pal,int e)
{
    //If the index is pointing to the last element in the array list 
    //I has to return 0 as the Array list is full
    if(pal->index==MAX-1)
        return 0;
    //else index has to be incremented to store the value in the 
    pal->index++;
    pal->a[pal->index]=e;
    return 1;
}

int delLast(ARRLST *pal,int *ele)
{
    //This function will be unsuccessfull when the list is empty
    if(pal->index==-1) return 0;
    //ele contains the last element of the Array list
    *ele=pal->a[pal->index];
    //Decrementing so that the last element has lost access.
    pal->index--;
    return 1; 
}

void display(ARRLST *pal)
{
    if(pal->index==-1) return;
    for(int i=0;i<=pal->index;i++)
    {
        printf("%d\t",pal->a[i]);
    }
    printf("\n");
}

//Adding Element to the starting of the list
int prepend(ARRLST *pal,int ele)
{
    //Full condition
    if(pal->index==MAX-1) return 0;
    // Shifting all the elements by one place
    for (int i =pal->index; i>=0; i--)
    {
       pal->a[i+1]=pal->a[i];
    }
    //Increasing the index as one of the elements is inserted
    pal->index++;
    //ele to be stored in the first element
    pal->a[0]=ele;
    return 1;     
}

int deletefront(ARRLST *pal,int *ele)
{
    //Empty cond
    if(pal->index==-1) return 0;
    //ele is the element to be deleted ie first element of the array list
    *ele=pal->a[0];
    //Shifting all the elements down
    for(int i=1; i<=pal->index; i++)
    {
        pal->a[i-1]=pal->a[i];
    }
    //Reducing the index as one of the elements is deleted
    pal->index--;
    return 1;
}

int insertposition(ARRLST *pal,int ele,int pos)
{
    //Full condition
    if(pal->index==MAX-1) return 0;
    //shifting all the elements above the pos by one
    for(int i=pal->index;i>=pos;i--)
    {
        pal->a[i+1]=pal->a[i];
    }
    // a[pos] will be empty
    //at that position insert the element
    pal->a[pos]=ele;
    //As the size of the array list increases index has to be incremented
    pal->index++;
    return 1;
}


int deleteposition(ARRLST *pal,int *ele,int pos)
{
    //Empty condition
    if(pal->index==-1) return 0;
    //ele contains value at the given position
    *ele=pal->a[pos];
    //i=pos+1
    //We are traversing from pos+1 to index and then shifting the values by one thereby automatically deleting the element at that position
    for(int i=pos+1;i<=pal->index;i++)
    {
        pal->a[i-1]=pal->a[i];
    }
    //Reducing the index as one of the elements is deleted
    pal->index--;
}

int getter(ARRLST *pal,int pos,int *ele)
{
    //Empty condition
    if(pal->index==-1) return 0;
    //Accessing and storing it in a pointer
    *ele=pal->a[pos];
    return 1;

}

int setter(ARRLST *pal,int pos,int ele)
{
    //Empty condition
    if(pal->index==-1) return 0;
    //Changing the value at pos to ele
    pal->a[pos]=ele;
    return 1;
}




