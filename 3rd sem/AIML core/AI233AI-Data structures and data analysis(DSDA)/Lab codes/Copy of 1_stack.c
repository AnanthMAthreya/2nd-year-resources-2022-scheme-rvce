#include<stdio.h>
#define MAX 100

int top = -1;     // Stack for operators
int ptop = -1;    // Stack for postfix expression
char a;

char stack[MAX];  // Operator stack
char infix[MAX];  // Input infix expression
char postfix[MAX]; // Output postfix expression

char pop() {
    if (top == -1) {
        printf("Stack Empty\n");
        return '\0';  // Return null character to avoid undefined behavior
    } else {
        return stack[top--];
    }
}

void push(char val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

int precedence(char opt) {
    switch (opt) {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case '^':
        return 3;  
    default:
        return 0;  
    }
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    printf("Input the infix expression: ");
    scanf("%s", infix);
    int i = 0;

    while (infix[i] != '\0') {
        a = infix[i];

        // Operand directly to postfix
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
            postfix[++ptop] = a;
        }
        // Left parenthesis is pushed to stack
        else if (a == '(') {
            push(a);
        }
        // Right parenthesis - pop until '(' is found
        else if (a == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[++ptop] = pop();
            }
            pop();  // Pop '(' from the stack
        }
        // Operator
        else if (is_operator(a)) {
            while (top != -1 && precedence(stack[top]) >= precedence(a)) {
                postfix[++ptop] = pop();
            }
            push(a);
        }

        i++;
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[++ptop] = pop();
    }

    postfix[++ptop] = '\0';  // Null-terminate the postfix string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
