#include<stdio.h>
int fibonacci(int n);
int main()
{
    printf("Enter the value of n to find the Fibonacci series");
    int n;
    scanf("%d",&n);
    printf("The Fibonacci series is as follows: \t");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",fibonacci(i));
    }
    return 0;
}

int fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==2 || n==1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}