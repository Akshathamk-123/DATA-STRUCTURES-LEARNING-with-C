#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char postfix[25];
    int s[20],top=-1,i=0;
    char ch,operand1,operand2,res;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        ch=postfix[i];
        if(isdigit(ch))
            s[++top]=ch-'0';    //push
        else{
            operand2=s[top--];  //pop
            operand1=s[top--];  //pop
            switch (ch)
            {
            case '+':res=operand1+operand2;
                break;
            case '-':res=operand1-operand2;
                break;
            case '*':res=operand1*operand2;
                break;
            case '/':res=operand1/operand2;
                break;
            }
            s[++top]=res;   //push
        }
        i++;
    }
    printf("%f",s[top--]);  //final pop
    printf("%d",res);       //final result
    return 0;
}