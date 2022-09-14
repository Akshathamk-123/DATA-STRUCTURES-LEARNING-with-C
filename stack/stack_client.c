#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
/*int main(){
    STACK s;
    int choice,ele,k,op;
    init(&s);
    do{
        printf("\nSelect the operation\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Check if stack is empty\n5.Check if stack is full\n6.display\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:printf("Enter element to be pushed\n");
               scanf("%d",&ele);
               k=push(&s,ele);
               if(k==0) printf("stack full\n");
               else printf("Successfully pushed\n");
            break;
        case 2:k=pop(&s,&ele);
               if(k==0) printf("stack empty\n");
               else printf("The element popped is %d\n",ele);
               break;
        case 3:k=peek(&s,&ele);
               if(k==0) printf("stack empty\n");
               else printf("The element popped is %d\n",ele);
            break;
        case 4:k=isEmpty(&s);
                if(k==1)    printf("Stack empty");
                else    printf("Stack is not empty");
        break;
        case 5:k=isFull(&s);
                if(k==1)    printf("Stack full");
                else    printf("Stack is not full");
        break;
        case 6:display(&s);
        break;
        }
    }while(choice<7);

    return 0;
}*/

int main()
{
    LLIST l,l1,l2;
    int choice,ele,k,pos;
    init(&l);
    do{
        printf("Enter your choice\n");
        printf("1.push\n2.pop\n3.peek\n4.display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter element to be pushed\n");
               scanf("%d",&ele);
               k=push(&l,ele);
               if(k==0) printf("invalid element\n");
               else printf("Successfully pushed\n");
        break;
        case 2:k=pop(&l,&ele);
               if(k==0) printf("stack empty\n");
               else printf("The element poped is %d\n",ele);
        break;
        case 3:k=peek(&l,&ele);
               if(k==0) printf("stack empty\n");
               else printf("The element peeked is %d\n",ele);
        break;
        case 4:display(&l);
        break;
        }
    }while(choice<5);
    return 0;
}