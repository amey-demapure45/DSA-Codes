#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {  
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); 
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
