#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int x) {
    if (root == NULL) return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void printRange(struct Node* root, int L, int R) {
    if (root == NULL) return;

    if (root->data > L)
        printRange(root->left, L, R);

    if (root->data >= L && root->data <= R)
        printf("%d ", root->data);

    if (root->data < R)
        printRange(root->right, L, R);
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder (BST): ");
    inorder(root);

    int L = 30, R = 65;
    printf("\n\nNodes in range [%d, %d]: ", L, R);
    printRange(root, L, R);

    return 0;
}
