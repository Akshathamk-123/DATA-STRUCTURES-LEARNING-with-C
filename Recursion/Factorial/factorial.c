#include<stdio.h>
int fact(int n);
int main()
{
    printf("Enter the number for which you want to find the factorial");
    int n;
    scanf("%d",&n);
    printf("The factorial of %d is %d", n,fact(n));
    return 0;
}

int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
        //This is tail recursive
        /*if it was 
        return fact(n-1)*n;
        it would be non-tail recursive.
        */
    }
}