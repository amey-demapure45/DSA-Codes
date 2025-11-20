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

int findMin(struct Node* root) {
    if (!root) return -1;
    while (root->left)
        root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    if (!root) return -1;
    while (root->right)
        root = root->right;
    return root->data;
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

    printf("Minimum = %d\n", findMin(root));
    printf("Maximum = %d\n", findMax(root));

    return 0;
}
