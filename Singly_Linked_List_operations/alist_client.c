#include<stdio.h>
#include<stdlib.h>
#include "alist.h"

int main()
{
    int choice,ele,k;
    int pos;
    LLIST al;
    init(&al);//Initializing the head in the LLIST struct to NULL
    do
    {
        //The loop for asking the User what operations to do
        printf("\n 1)Insert in the front of the list \n 2)Delete in the front \n 3)Display\n 4)Delete from the last\n 5)Insert from the last\n 6)Insert in the given position\n 7)Delete at the given position\n 8)Delete the given element\n 9)Count the number of nodes\n 10)Move nth node backward by m positions from the beginning\n 11)Move mth node foward by n positions from the beginning\n 12)Merge two ordered List\n");
        //The choice is taken from the user and stored in the variable choice
        printf("Enter your choice");
        scanf("%d",&choice);
        //working on the basis of the user input
        switch(choice)
        {
            case 1://1)Insert in the front of the list
                printf("Enter the element to be Inserted");
                //The element entered will be will be stored in the variable ele
                //The ele has the input which has to be inserted to the front of the list 
                scanf("%d",&ele);
                //Function prototype:
                //int insertFront(LLIST *pl, int e)
                k=insertFront(&al,ele);
                if(k==0) //Unsuccessful
                {
                    printf("Unsuccessful insertion\n");
                    //check once
                }
                else //Successful function execution
                {
                    printf("The element %d is inserted successfully inserted at the front of the list\n",ele);
                }
                break;
            case 2://2)Delete in the front
                //We just have to delete from the front therefore input from the user 
                //But we have to pass the variable as the parameter as we have to store the value of the node that is deleted
                //Function prototype:
                //int deleteFront(LLIST *pl, int *pe)
                //just the pointer of the element is passed therefore we have to use &
                k=deleteFront(&al,&ele);
                if(k==0)
                {
                    printf("The List is empty\n");
                }
                else 
                {
                    printf("Successfully deleted %d from the end\n",ele);
                }
                break;
            case 3://3)Display
                //We have to just pass the list as the argument for the display function
                //Function prototype:
                //void disp(LLIST *pl)
                disp(&al);
                break;
            case 4://4)Delete from the end 
                //We just have to delete from the end therefore input from the user 
                //But we have to pass the variable as the parameter as we have to store the value of the node that is deleted
                //Function prototype:
                //int deleteLast(LLIST *pl, int *pe)
                //just the pointer of the element is passed therefore we have to use &
                k=deleteLast(&al,&ele);
                if(k==0)
                {
                    printf("The list is Empty");
                } 
                else
                {
                    printf("The last node %d Successfully deleted.",ele);    
                }
                break;
            case 5://5)Insert from the last
                //The element entered will be will be stored in the variable ele
                //The ele has the input which has to be inserted to the end of the list 
                printf("Enter the element to be Inserted");
                scanf("%d",&ele);
                k=insertLast(&al,ele);
                if(k==0)
                {
                    printf("Unsuccessful");
                }
                else
                {
                    printf("Successfully inserted %d at the end");
                }
                break;
            case 6://6)Insert at the given position
                printf("Enter the position at which you wan to insert and the element itself");
                scanf("%d %d",&pos,&ele);
                k=insertposition(&al,pos,ele);
                if(k==0)
                {
                    printf("The position is invalid");
                }
                else 
                {
                    printf("The node is successfully inserted at %d",pos);
                }
                break;
            case 7://7)Delete at the given position 
                printf("Enter the position of the element to be deleted");
                scanf("%d",&pos);
                k=deleteposition(&al,pos,&ele);
                if(k==0)
                {
                    printf("The list is either empty or the position entered is invalid\n");
                }
                else
                {
                    printf("The element %d is deleted from %d\n",ele,pos);
                }
                break;
            case 8:// 8)Delete the given element
                printf("Enter the element tobe deleted");
                scanf("%d",&ele);
                k=deletegivenele(&al,ele);
                if(k==0)
                {
                    printf("Unsuccessful deletion");
                }
                else
                {
                    printf("Successful deletion of %d",ele);
                }
                break;
            case 9: //9)Count the number of nodes
                k=noofnodes(&al);
                printf("Number of nodes in the list is %d",k);
                break;
            /*
            case 10://10)Move nth node backward by m positions from the beginning
                break;
            case 11://11)Move mth node forward by n positions from the beginning
                break;
            
            case 12://12)Merge two ordered List 
                break;
            */
            
        }
    } while (choice); 
}

