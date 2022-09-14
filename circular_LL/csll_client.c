#include<stdio.h>
#include<stdlib.h>
#include"csll.h"
int main()
{
    CLIST l1,l2,l3;
    init(&l1);
    init(&l2);
    init(&l3);
    printf("Enter the elements of list\n");
    create(&l1);
    printf("Enter the elements of second list\n");
    create(&l2);
    add(&l1,&l2,&l3);
    display(&l3);
    return 0;
}