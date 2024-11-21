#include<stdio.h>
#include<ctype.h>  // For isdigit()
#define MAX 100

int top = -1;     // Stack for operators
int ptop = -1;    // Stack for postfix expression
int eval_top = -1; // Stack for evaluation

char stack[MAX];  // Operator stack
char infix[MAX];  // Input infix expression
char postfix[MAX]; // Output postfix expression
int eval_stack[MAX]; // Stack for evaluation

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

void eval_push(int val) {
    if (eval_top == MAX - 1) {
        printf("Evaluation Stack Overflow\n");
    } else {
        eval_stack[++eval_top] = val;
    }
}

int eval_pop() {
    if (eval_top == -1) {
        printf("Evaluation Stack Empty\n");
        return 0;  // Return 0 to avoid undefined behavior
    } else {
        return eval_stack[eval_top--];
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

int evaluate_postfix() {
    int i = 0, op1, op2, result;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (isalnum(c)) {  // Operand
            printf("Enter the value of %c: ", c);
            int val;
            scanf("%d", &val);
            eval_push(val);
        } else if (is_operator(c)) {  // Operator
            op2 = eval_pop();  // Second operand
            op1 = eval_pop();  // First operand
            switch (c) {
            case '+': result = op1 + op2; break;
            case '-': result = op1 - op2; break;
            case '*': result = op1 * op2; break;
            case '/': result = op1 / op2; break;
            case '^': 
                result = 1;
                for (int j = 0; j < op2; j++) result *= op1;
                break;
            default: result = 0;  // For safety
            }
            eval_push(result);
        }
        i++;
    }
    return eval_pop();  // Final result
}

int main() {
    printf("Input the infix expression: ");
    scanf("%s", infix);
    int i = 0;
    char a;

    // Convert infix to postfix
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

    // Evaluate the postfix expression
    int result = evaluate_postfix();
    printf("Result of evaluation: %d\n", result);

    return 0;
}
