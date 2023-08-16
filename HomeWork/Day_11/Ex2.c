#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct {
    double data[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(Stack *stack, double value) {
    if (isFull(stack)) {
        fprintf(stderr, "Stack is full\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++(stack->top)] = value;
}

double pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[(stack->top)--];
}

double performOperation(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            fprintf(stderr, "Invalid operator: %c\n", op);
            exit(EXIT_FAILURE);
    }
}

double evaluateRPN(const char *expression) {
    Stack operands;
    initStack(&operands);

    size_t len = strlen(expression);
    for (size_t i = 0; i < len; i++) {
        char token = expression[i];
        if (isdigit(token) || (token == '-' && isdigit(expression[i + 1]))) {
            push(&operands, atof(&expression[i]));
            while (isdigit(expression[i + 1]) || expression[i + 1] == '.') {
                i++;
            }
        } else if (strchr("+-*/", token) != NULL) {
            double operand2 = pop(&operands);
            double operand1 = pop(&operands);
            double result = performOperation(operand1, operand2, token);
            push(&operands, result);
        }
    }

    return pop(&operands);
}

int main() {
    char expression[100];
    printf("Enter an expression in RPN: ");
    fgets(expression, sizeof(expression), stdin);

    double result = evaluateRPN(expression);
    printf("Result: %lf\n", result);

    return 0;
}
