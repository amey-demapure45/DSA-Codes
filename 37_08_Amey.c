#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int precedence(char op) {
    if (op=='^') return 3;
    if (op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return 0;
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len/2; i++) {
        char t = exp[i];
        exp[i] = exp[len-i-1];
        exp[len-i-1] = t;
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c))
            postfix[j++] = c;

        else if (c == '(')
            push(c);

        else if (c == ')') {
            while (peek() != '(') postfix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(peek()) > precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix: %s\n", prefix);

    return 0;
}
