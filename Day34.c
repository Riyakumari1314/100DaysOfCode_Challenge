/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push element into stack
void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop element from stack
int pop() {
    struct Node *temp;
    int value;

    temp = top;
    value = temp->data;
    top = top->next;

    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char expression[]) {
    int i = 0;
    int a, b, result;

    while (expression[i] != '\0') {

        // If operand
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        }

        // If operator
        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/') {

            b = pop();
            a = pop();

            switch (expression[i]) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main() {
    char expression[100];

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    printf("Result: %d\n", evaluatePostfix(expression));

    return 0;
}