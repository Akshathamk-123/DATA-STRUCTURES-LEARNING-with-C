#include<stdio.h>
#include "arrlst_header.h"

int main()
{
    int choice,ele,k,pos;
    int *pe;
    ARRLST al;
    //Initializing index to -1
    //Initially the index will be some random value but we want to initialize to -1 to make sure we can access it easily
    init(&al);
    do
    {   //Asking for choice through print statements
        printf(" 1)Append\n 2)Delete an element from the end\n 3)Display\n 4)Prepend\n 5)Delete from the front\n 6)Insert an element in the given position\n 7)Delete an element in the given position\n 8)getter\n 9)setter\n");
        printf("Enter your choice");
        //Taking in inputs and storing it in variable "choice"
        scanf("%d",&choice);
        //Checking for condition
        switch(choice)
        {
            case 1://Append
                //Asking for the element to be appended into the arraylist
                printf("Enter the element to be appended");
                //Storing it in variable "ele"
                scanf("%d",&ele);
                //Appending the entered element to the array list.
                //Calling the function present in arrlst_implementation.c file
                k=append(&al,ele);
                if(k==0)
                {
                    //That function will return 0 if the arrlst is full so have to print it
                    printf("List is full\n");
                }
                else
                {
                    //The function will return 1 for successful appending
                    printf("Successfully appended %d\n",ele);
                }
                break;
                //End of Case 1
            case 2://Delete from the End
                k=delLast(&al,&ele);
                if(k==0)
                {
                    //This function will be unsuccessfull when the list is empty
                    printf("The List is empty\n");
                }
                else 
                {
                    printf("Successfully deleted %d from the end\n",ele);
                }
                break;
                //End of case 2
            case 3://Display
                display(&al);
                break;
                //End of case 3
            case 4://Prepend
                //Adding Element to the starting of the list
                printf("Enter the element to be prepended");
                scanf("%d",&ele);
                k=prepend(&al,ele);
                if(k==0) 
                {
                    //Returns 0 if the list is full
                    printf("The list is full");
                }
                
                else
                {
                    printf("Successfully prepended %d",ele);
                }
                break;
                //End of case 4
            case 5://Delete from the front
                k=deletefront(&al,&ele);
                if(k==0)
                {
                    //Empty condition
                    printf("The list is Empty");
                }
                else
                {
                    printf("Deleted %d from the front of the list\n",ele);
                }
                break;
                //End of case 5
            case 6:
               //Asking for element to be inserted and thhe position at which it has to be inserted
                printf("Enter the element to be inserted and the position in which it has to be inserted");
                scanf("%d %d",&ele,&pos);
                k=insertposition(&al,ele,pos);
                if(k==0)
                {
                    //Full cond
                printf("The List is full");
                }
                else
                {
                    printf("%d is successfully inserted at %d",ele,pos);
                }
                break;
                //End of case 6
            case 7:
                //Asking for position only
                printf("Enter the position from which the element has to be deleted");
                scanf("%d",&pos);
                k=deleteposition(&al,&ele,pos);
                if(k==0)
                {
                    //Empty condition
                    printf("The list is empty");
                }
                else
                {
                    printf("%dis deleted from %d succesfully",&ele,pos);
                }
                break;
                //End of case 7
            case 8://getter
                //Accessing the element at the given position
                printf("Enter the position of the element you want to get");
                scanf("%d",&pos);
                k=getter(&al,pos,&ele);
                if(k==0)
                {
                    //Empty condition
                    printf("The list is Empty");
                }
                else
                {
                    printf("The element in the position %d is %d",pos,ele);
                }
                break;
            case 9://setter
                //Changing the value at pos to ele
                printf("Enter the position and element to be set and the position at which it has to set");
                scanf("%d %d",&pos,&ele);
                k=setter(&al,pos,ele);
                if(k==0)
                {
                    //Empty condition
                    printf("The list is empty");
                }
                else{
                    printf("The element is successfully set into the list");
                }
                break;
            case 10: 
            //Exit condition
                break;

        }
    } while (choice);
    //This is for asking more than one choice
}