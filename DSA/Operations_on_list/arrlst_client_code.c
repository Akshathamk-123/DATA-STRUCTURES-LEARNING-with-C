#include<stdio.h>
#include "arrlst_header.h"

int main()
{
    int choice,ele,k,pos;
    ARRLST al;
    init(&al);
    do
    {
        printf(" 1)Append\n 2)Delete an element from the end\n 3)Display\n 4)Prepend\n 5)Delete from the front\n 6)Insert an element in the given position\n 7)Delete an element in the given position\n 8)getter\n 9)setter\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://Append
                printf("Enter the element to be appended");
                scanf("%d",&ele);
                k=append(&al,ele);
                if(k==0)
                {
                    printf("List is full\n");
                }
                else
                {
                    printf("Successfully appended %d\n",ele);
                }
                break;
            case 2://Delete from the End
                k=delLast(&al,&ele);
                if(k==0)
                {
                    printf("The List is empty\n");
                }
                else 
                {
                    printf("Successfully deleted %d from the end\n",ele);
                }
                break;
            case 3://Display
                display(&al);
                break;
            case 4://Prepend
                printf("Enter the element to be prepended");
                scanf("%d",&ele);
                k=prepend(&al,ele);
                if(k==0) 
                {
                    printf("The list is full");
                }
                
                else
                {
                    printf("Successfully prepended %d",ele);
                }
                break;
            case 5://Delete from the front
                k=deletefront(&al,&ele);
                if(k==0)
                {
                    printf("The list is Empty");
                }
                else
                {
                    printf("Deleted %d from the front of the list\n",ele);
                }
                break;
            case 6:
                printf("Enter the element to be inserted and the position in which it has to be inserted");
                scanf("%d %d",&ele,&pos);
                k=insertposition(&al,ele,pos);
                if(k==0)
                {
                printf("The List is full");
                }
                else
                {
                    printf("%d is successfully inserted at %d",ele,pos);
                }
                break;
            case 7:
                printf("Enter the position from which the element has to be deleted");
                scanf("%d",&pos);
                k=deleteposition(&al,ele,pos);
                if(k==0)
                {
                    printf("The list is empty");
                }
                else
                {
                    printf("%dis deleted from %d succesfully",ele,pos);
                }
                break;
            case 8://getter
                printf("Enter the position of the element you want to get");
                scanf("%d",&pos);
                k=getter(&al,pos,ele);
                if(k==0)
                {
                    printf("The list is Empty");
                }
                else
                {
                    printf("The element in the position %d is %d",pos,ele);
                }
                break;
            case 9://setter
                printf("Enter the position and element to be set and the position at which it has to set");
                scanf("%d %d",&ele,&pos);
                k=setter(&al,pos,ele);
                if(k==0)
                {
                    printf("The list is empty");
                }
                else{
                    printf("The element is successfully set into the list");
                }

        }
    } while (choice);
    
}
