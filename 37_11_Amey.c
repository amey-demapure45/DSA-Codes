#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int operandStack[MAX];
char operatorStack[MAX];
int topOperand = -1, topOperator = -1;

void pushOperand(int val) {
    operandStack[++topOperand] = val;
}

int popOperand() {
    return operandStack[topOperand--];
}

void pushOperator(char op) {
    operatorStack[++topOperator] = op;
}

char popOperator() {
    return operatorStack[topOperator--];
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}


int evaluate(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {

        if (expr[i] == ' ') continue;

       
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; 
            pushOperand(num);
        }
        else if (expr[i] == '(') {
            pushOperator(expr[i]);
        }
        else if (expr[i] == ')') {
            while (topOperator != -1 && operatorStack[topOperator] != '(') {
                int b = popOperand();
                int a = popOperand();
                char op = popOperator();
                pushOperand(applyOperation(a, b, op));
            }
            popOperator(); 
        }
        else { 
            while (topOperator != -1 &&
                   precedence(operatorStack[topOperator]) >= precedence(expr[i])) {

                int b = popOperand();
                int a = popOperand();
                char op = popOperator();
                pushOperand(applyOperation(a, b, op));
            }
            pushOperator(expr[i]);
        }
    }


    while (topOperator != -1) {
        int b = popOperand();
        int a = popOperand();
        char op = popOperator();
        pushOperand(applyOperation(a, b, op));
    }

    return popOperand();
}

int main() {
    char expression[MAX];

    printf("Enter arithmetic expression: ");
    fgets(expression, MAX, stdin);

    int result = evaluate(expression);

    printf("Result = %d\n", result);

    return 0;
}

