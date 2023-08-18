#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Прототипи на функциите
int evaluateExpression(const char* expr, int* pos);
int evaluateNumber(const char* expr, int* pos);
int evaluateTerm(const char* expr, int* pos);
int evaluateFactor(const char* expr, int* pos);

// Функция за оценка на израз
int evaluateExpression(const char* expr, int* pos) {
    int result = evaluateTerm(expr, pos);

    while (expr[*pos] == '+' || expr[*pos] == '-') {
        char op = expr[(*pos)++];

        int num = evaluateTerm(expr, pos);

        if (op == '+') {
            result += num;
        } else {
            result -= num;
        }
    }

    return result;
}

// Функция за оценка на число
int evaluateNumber(const char* expr, int* pos) {
    int num = 0;

    while (expr[*pos] >= '0' && expr[*pos] <= '9') {
        num = num * 10 + (expr[(*pos)++] - '0');
    }

    return num;
}

// Функция за оценка на множител
int evaluateTerm(const char* expr, int* pos) {
    int result = evaluateFactor(expr, pos);

    while (expr[*pos] == '*' || expr[*pos] == '/') {
        char op = expr[(*pos)++];

        int num = evaluateFactor(expr, pos);

        if (op == '*') {
            result *= num;
        } else {
            result /= num;
        }
    }

    return result;
}

int evaluateFactor(const char* expr, int* pos) {
    int result;

    if (expr[*pos] == '(') {
        (*pos)++;
        result = evaluateExpression(expr, pos);
        (*pos)++; // Прескачаме затварящата скоба
    } else if (expr[*pos] >= '0' && expr[*pos] <= '9') {
        result = evaluateNumber(expr, pos);
    } else if (expr[*pos] == '^') {
        (*pos)++; // Прескачаме символа '^'
        int base = evaluateFactor(expr, pos); // Оценяваме основата
        int exponent = 0;
        
        // Четем степента като цяло число
        while (expr[*pos] >= '0' && expr[*pos] <= '9') {
            exponent = exponent * 10 + (expr[(*pos)++] - '0');
        }
        
        // Изчисляваме степенуването
        int tempResult = 1;
        for (int i = 0; i < exponent; i++) {
            tempResult *= base;
        }
        
        result = tempResult;
    }

    return result;
}


int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    int pos = 0;
    int result = evaluateExpression(expr, &pos);
    printf("Result: %d\n", result);

    return 0;
}
