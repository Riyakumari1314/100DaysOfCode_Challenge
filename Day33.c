/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push into stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop from stack
char pop() {
    return stack[top--];
}

// Check precedence
int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // Opening bracket
        else if (ch == '(') {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }

        // Operator
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}