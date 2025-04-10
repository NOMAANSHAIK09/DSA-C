#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Define the Stack structure using typedef
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element to the stack
void push(Stack* s, char value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to peek the top element of the stack
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to check if a character is an operand (alphanumeric character)
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Function to perform infix to postfix conversion
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;  // Index for postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isOperand(current)) {
            postfix[j++] = current;  // Add operand to postfix
        } else if (current == '(') {
            push(&s, current);  // Push '(' to stack
        } else if (current == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);  // Pop and add to postfix until '(' is found
            }
            pop(&s);  // Remove '(' from stack
        } else if (isOperator(current)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current)) {
                postfix[j++] = pop(&s);  // Pop operators with higher or equal precedence
            }
            push(&s, current);  // Push current operator to stack
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}



























