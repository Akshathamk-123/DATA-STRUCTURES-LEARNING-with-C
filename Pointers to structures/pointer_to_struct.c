/*Pointers to Structures
If the structures have the instance one which is a pointer and one that is a variable, then to access the data elements inside of the structure for the variable, is by using a dot 

For pointer, the -> (arrow) is used.*/

#include<stdio.h>

struct student 
{
    int age;
    int marks;
    int srn;
};

int main()
{
    struct student s1;
    struct student *s2;
    printf("Enter the age,marks and srn");
    scanf("%d %d %d",&s1.age,&s1.marks,&s1.srn);
    s2=&s1;
    printf("The age marks and srn are: %d %d %d",s2->age,s2->marks,s2->srn);
    return 0;
}