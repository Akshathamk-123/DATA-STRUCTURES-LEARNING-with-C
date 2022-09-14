#include<stdio.h>
#include<stdlib.h>
#include"search.h"
int main(){
    DLIST l;
    init(&l);
    int e;
    printf("creating the list\n");
    create(&l);
    //display(&l);
    printf("Enter the element to be searched\n");
    scanf("%d",&e);
    if(search(&l,e))
        printf("Element %d is present",e);
    else
        printf("Element %d is not present",e);
    return 0;
}