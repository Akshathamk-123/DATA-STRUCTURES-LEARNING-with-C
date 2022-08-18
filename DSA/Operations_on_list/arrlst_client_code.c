#include<stdio.h>
#include "arrlst_header.h"

int main()
{
    int choice,ele,k;
    ARRLST al;
    init(&al);
    do
    {
        printf(" 1)Append\n 2)Delete an element from the end\n 3)Display\n 4)Prepend\n 5)Delete from the front\n");
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

        }
    } while (choice);
    
}
