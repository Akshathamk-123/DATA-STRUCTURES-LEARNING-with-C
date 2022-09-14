#include<stdio.h>
#include<ctype.h>
#include<string.h>
int precedence(char sp,char curr);
int main()
{
    char postfix[25],infix[25],s[25],ch;    //ch is current character
    int top=-1,i=0,k=0;     //i->index of infix k->index of postfix top->index of stack arrays respectively
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(isalnum(ch))      //operand
            postfix[k++]=ch; //push
        else //operator
        {
            while((top!=-1) && (precedence(s[top],ch)))
            {
                //pop and add to postfix;
                postfix[k]=s[top];
                k++;
                top--;
            }
            if(ch==')') //pop and discard
                top--;
            else    //push the current character
                s[++top]=ch;
        }
        i++;}
        while(top!=-1)
        {
            postfix[k++]=s[top--];
        }
        postfix[k]='\0';
    
    printf("The postfix expression is:");
    for(int j=0;j<=strlen(postfix);j++){
        printf("%c",postfix[j]);
    }
}
int precedence(char sp,char curr)
{
    switch (curr)
    {
    case '(': return 0; 
        break;
    case ')': if(sp=='(')   return 0;
                else    return 1;
    case '*': if(sp=='+' || sp=='-' || sp=='(') return 0;
                else    return 1;
    case '/': if(sp=='+' || sp=='-' || sp=='(') return 0;
                else    return 1;
    case '+': if(sp=='(')   return 0;
                else    return 1;
    case '-': if(sp=='(')   return 0;
                else    return 1;
    }
}
