(a) Data Structures Used

A stack is used in this program.
Two stacks are implemented using arrays:

Operator stack to store operators and parentheses

Value stack to store operands during evaluation
An integer variable top is used to track the top of each stack.

(b) Functions Implemented

push() – inserts an element into the stack

pop() – removes the top element from the stack

precedence() – returns operator priority

infixToPostfix() – converts infix expression to postfix

evaluatePostfix() – evaluates the postfix expression

(c) Organization of main()

The main() function reads an infix expression, converts it to postfix, evaluates it, and prints the result.

(d) Sample Output
Enter infix expression: 34*45
Postfix expression: 3445*
Evaluation result: 20