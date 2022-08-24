#include<stdio.h>
#include<stdlib.h>
#include "alist.h"



//Initializing the head in the LLIST struct to NULL
//Just a function, not a part of the switch case 
//working status: WORKING PERFECTLY 
void init(LLIST *pl)
{
    pl->head=NULL;
}




//Inserting the element in the front of the list
//The function is called in case 1:
//working status:WORKING PERFECTly
int insertFront(LLIST *pl, int e)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL) return 0;
    temp->info=e;
    temp->next=pl->head;
    pl->head=temp;
    return 1;
}




//Deleting the node from the front of the list
//The function is called in case 2:
//working status:WORKING PERFECTLY
int deleteFront(LLIST *pl, int *pe)
{
    NODE *p;
    p=pl->head;
    if(pl->head==NULL) return 0; //List is empty
    pl->head=p->next;
    *pe=p->info;
    free(p);
    return 1;
}






//Displaying the node status
//The function is called in case 3:
//working status:WORKING PERFECT
void disp(LLIST* pl)
{
    NODE* p=pl->head;
    if(p==NULL)
    printf("list is empty");
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->info);
            p=p->next;
        }
    }

}





//Deleting a node from the end
//The function is called in case 4:
//working status:WORKING PERFECTLY
int deleteLast(LLIST *pl,int *pe)
{
    NODE* p=pl->head;
    NODE* pre;
    if(p==NULL) return 0;
    while(p->next!=NULL)
    {
        pre=p;
        p=p->next;
    }
    pre->next=NULL;
    *pe=p->info;
    free(p);
    return 1;
}





//Inserting an element at the end of the list
//The function is called in case 5:
//working status:WORKING PERFECTLY
int insertLast(LLIST *pl,int ele)
{
    NODE *temp,*p;
    //temp is the pointer to the struct variable which is inserted at the end
    p=pl->head;
    temp=(NODE*)malloc(sizeof(NODE));
    //allocating memory to store the element to be inserted
    temp->info=ele;//assigning the info of temp to the element entered by the user
    //traversing till the last node

       if(pl->head==NULL)
    {
        //if the user entered the position to the front
        temp->next=NULL;
        pl->head=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
        p=p->next;
        }
        //p->next which was NULL is now pointing to temp hence successful insertion
        p->next=temp;
        temp->next=NULL;
    
        return 1;
        //p is the traversing pointer
    }
    
}







//Inserting an element in the given position
//The function is called in case 6:
//working status:WORKING PERFECTLY
int insertposition(LLIST *pl,int pos,int ele)
{   
    //pos is the variable which has the position at which the node has to be inserted
    //ele is the variable which has the information to the be stored in the new node inserted
    NODE *temp;
    //temp is the pointer to the structure variable which stores the info and the link variable of the new node that has to be inserted
    temp=(NODE*)malloc(sizeof(NODE));//allocation of memory
    temp->info=ele;//assigning info of the temp to the element entered by the user
    if(temp==NULL) return 0;//invalid input(UNSUCCESSFUL INSERTING)
    //linking temp
    if(pl->head==NULL || pos==1)
    {
        //if the user entered the position to the front
        temp->next=pl->head;
        pl->head=temp;
    }
    else 
    {
        int cnt=1;//counter variable
        NODE *p=pl->head;//Traversing variable
        NODE *q=NULL;//Traversing variable just behind the p
        //traverse to the given position 
        while(p!=NULL && cnt<pos)
        {
            q=p;
            p=p->next;
            cnt++;
        }
        q->next=temp;
        temp->next=p;
    }
    return 1;
}






//Deleting the node from the given position
//The function is called in case 7:
//working status:NOT WRITTEN
int deleteposition(LLIST *pl,int pos,int *ele)
{
    //pos is the variable which has the position at which the node has to be deleted
    NODE *p;
    p=pl->head;
    NODE *pre;
    int cnt=1;
    if(p==NULL) return 0;
    while(cnt<pos)
    {
        pre=p;
        p=p->next;
        cnt++;
    }
    pre->next=p->next;
    *ele=p->info;
    free(p);
    return 1;
}











//Deleting the element entered from the list if present
//The function is called in case 8:
//working status:MAY BE WORKING 
int deletegivenele(LLIST *pl,int given)
{
    NODE *p,*q;
    if(pl->head==NULL) return 0;
    p=pl->head;
    q=NULL;
    if(p->info==given)
    {
        pl->head=p->next;
        free(p);
    }
    else{
        while(p!=NULL && p->info!=given)
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            printf("given info is not found in the list");
            return 0;
        }
        else
        {
            q->next=p->next;
            free(p);
        }
    }
    return 1;
}
