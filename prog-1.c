#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push (char c)
{
    stack [++top]=c;
}
char pop()
{
    return stack [top--];
}
int isMatching (char open,char close)
{
    if(open=='(' && close==')')
        return 1;
    if(open=='{' && close=='}')
        return 1;
    if(open=='[' && close==']')
        return 1;
}
int main()
{
    char exp[MAX];
    int i,balanced=1;
    printf("Enter an expression: ");
    fgets(exp, MAX, stdin);
    for(i=0;i<strlen(exp);i++)
    {
        char ch=exp[i];
        if(ch=='(' || ch=='{' || ch=='[')
            push(ch);
        else if(ch==')' || ch=='}' || ch==']')
        {
            if(top==-1)
            {
                balanced=0;
                break;
            }
            char open=pop();
            if(!isMatching(open,ch))
            {
                balanced=0;
                break;
            }
        }
    }
    if(top!=-1)
        balanced=0;
    if(balanced)
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");
    return 0;
}