#include <stdio.h>

int main() {
    int n, stack[32], top = -1;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary = 0\n");
        return 0;
    }

    while (n > 0) {
        stack[++top] = n % 2;
        n /= 2;
    }

    printf("Binary = ");
    while (top != -1)
        printf("%d", stack[top--]);

    printf("\n");
    return 0;
}
