#include<stdio.h>
#include "arrlst_header.h"

int main()
{
    int choice,ele,k;
    ARRLST al;
    init(&al);
    do
    {
        printf(" 1)Append\n 2)Delete an element from the end\n 3)Display\n 4)Prepend\n 5)Delete from the front\n 5)Insert an element in the given position\n 6)Delete an element in the given position\n 7)getter\n 8)setter\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://Append
                printf("Enter the element to be appended");
                scanf("%d",&ele);
                k=append(&al,&ele);
                if(k==0)
                {
                    printf("List is full");
                }
                else
                {
                    printf("Successfully appended %d",ele);
                }
                break;
            case 2://Delete from the End
                k=delLast(&al,&ele);
                if(k==0)
                {
                    printf("The List is empty");
                }
                else 
                {
                    printf("Successfully deleted %d from the end",ele);
                }
                

                

        }
    } while (choice);
    
}