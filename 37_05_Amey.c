#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }

        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return 0;

            char popped = pop();
            if (!isMatching(popped, c))
                return 0;
        }
    }

    return top == -1;
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Parenthesis are balanced\n");
    else
        printf("Parenthesis are NOT balanced\n");

    return 0;
}
