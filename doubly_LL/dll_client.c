#include<stdio.h>     
#include<stdlib.h>
#include"dll.h"
int main()
{
    DLIST l;
    int choice,ele,k,pos;
    init(&l);
    do{
        printf("Enter your choice\n");
        printf("1.insertfront\n2.deletefront\n3..insertlast\n4.deletelast\n5.insert_position\n6.delete_info\n7.Count_nodes\n8.display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter element to be inserted\n");
               scanf("%d",&ele);
               k=insertfront(&l,ele);
               if(k==0) printf("invalid element\n");
               else printf("Successful insertion\n");
        break;
        case 2:k=deletefront(&l,&ele);
               if(k==0) printf("list empty\n");
               else printf("The element deleted is %d\n",ele);
        break;
        case 3:printf("Enter element to be inserted\n");
               scanf("%d",&ele);
               k=insertlast(&l,ele);
               if(k==0) printf("invalid element\n");
               else printf("Successful insertion\n");
        break;
        case 4:k=deletelast(&l,&ele);
               if(k==0) printf("list empty\n");
               else printf("The element deleted is %d\n",ele);
        break;
        case 5:printf("Enter element to be inserted\n");
               scanf("%d",&ele);
               printf("Enter position to be inserted\n");
               scanf("%d",&pos);
               k=insertposition(&l,ele,pos);
               if(k==0) printf("invalid element\n");
               else printf("Successful insertion\n");
        break;
        case 6:printf("Enter element to be deleted:\n");
              scanf("%d",&ele);
              k=delete_duplicates(&l,ele);
              if(k==0)     printf("Element not found\n");
              else  printf("Successful deletion\n");
              break;

        case 7:k=count_nodes(&l);
              if(k==0)      printf("Number of nodes:0\n");
              else      printf("Number of nodes:%d",k);
        break;
        case 8:display(&l);break;
        }
    }while(choice<9);
    return 0;
}
