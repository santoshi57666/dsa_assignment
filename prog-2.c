#include <stdio.h>
#include <ctype.h>
#define MAX 100
char opStack[MAX];
int topOp = -1;

int valStack[MAX];
int topVal = -1;

void pushOp(char c)
 {
    opStack[++topOp] = c;
}

char popOp() 
{

    return opStack[topOp--];
}

void pushVal(int v) {
    valStack[++topVal] = v;
}

int popVal() {
    return valStack[topVal--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
 {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') 
    {

        if (isdigit(ch)) {
            postfix[k++] = ch;
        }

        else if (ch == '(') {
            pushOp(ch);
        }

        else if (ch == ')') {
            while (topOp != -1 && opStack[topOp] != '(') 
            {
                postfix[k++] = popOp();
            }
            popOp(); 
        }
        else {
            while (topOp != -1 &&
                   precedence(opStack[topOp]) >= precedence(ch)) {
                postfix[k++] = popOp();
            }
            pushOp(ch);
        }
    }

    while (topOp != -1) {
        postfix[k++] = popOp();
    }

    postfix[k] = '\0';
}


int evaluatePostfix(char postfix[]) 
{
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0')
     {

        if (isdigit(ch)) {
            pushVal(ch - '0');
        }

        else {
            int b = popVal();
            int a = popVal();

            switch (ch) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
            }
        }
    }
    return popVal();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}
