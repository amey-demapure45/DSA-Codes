#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* root = NULL;

struct Node* newNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}

void inorder(struct Node* r){ if(!r) return; inorder(r->left); printf("%d ",r->data); inorder(r->right); }
void preorder(struct Node* r){ if(!r) return; printf("%d ",r->data); preorder(r->left); preorder(r->right); }
void postorder(struct Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ",r->data); }

void bfs(struct Node* r){
    if (!r) return;
    struct Node* q[100]; int f = 0, b = 0;
    q[b++] = r;
    while (f < b) {
        struct Node* t = q[f++];
        printf("%d ", t->data);
        if (t->left) q[b++] = t->left;
        if (t->right) q[b++] = t->right;
    }
}

void dfs(struct Node* r){
    if (!r) return;
    struct Node* st[100]; int top = -1;
    st[++top] = r;
    while (top != -1) {
        struct Node* t = st[top--];
        printf("%d ", t->data);
        if (t->right) st[++top] = t->right;
        if (t->left) st[++top] = t->left;
    }
}

struct Node* mirror(struct Node* r){
    if (!r) return NULL;
    struct Node* temp = r->left;
    r->left = mirror(r->right);
    r->right = mirror(temp);
    return r;
}

void children(struct Node* r, int x){
    if (!r) return;
    if (r->data == x) {
        printf("Children of %d: ", x);
        if (r->left) printf("%d ", r->left->data);
        if (r->right) printf("%d ", r->right->data);
        if (!r->left && !r->right) printf("No children");
        printf("\n");
        return;
    }
    children(r->left, x);
    children(r->right, x);
}

void parent(struct Node* r, int x){
    if (!r) return;
    if ((r->left && r->left->data == x) || (r->right && r->right->data == x)) {
        printf("Parent of %d is %d\n", x, r->data);
        return;
    }
    parent(r->left, x);
    parent(r->right, x);
}

void sibling(struct Node* r, int x){
    if (!r) return;
    if (r->left && r->right) {
        if (r->left->data == x) { printf("Sibling of %d = %d\n", x, r->right->data); return; }
        if (r->right->data == x) { printf("Sibling of %d = %d\n", x, r->left->data); return; }
    }
    sibling(r->left, x);
    sibling(r->right, x);
}

void grandparent(struct Node* r, int x){
    if (!r) return;
    if (r->left) {
        if (r->left->left && r->left->left->data == x) { printf("GP of %d = %d\n", x, r->data); return; }
        if (r->left->right && r->left->right->data == x) { printf("GP of %d = %d\n", x, r->data); return; }
    }
    if (r->right) {
        if (r->right->left && r->right->left->data == x) { printf("GP of %d = %d\n", x, r->data); return; }
        if (r->right->right && r->right->right->data == x) { printf("GP of %d = %d\n", x, r->data); return; }
    }
    grandparent(r->left, x);
    grandparent(r->right, x);
}
void uncle(struct Node* r, int x){
    if (!r) return;
    if (r->left && r->right) {
        struct Node *L = r->left, *R = r->right;

        if (L->left && L->left->data == x) { printf("Uncle = %d\n", R->data); return; }
        if (L->right && L->right->data == x) { printf("Uncle = %d\n", R->data); return; }

        if (R->left && R->left->data == x) { printf("Uncle = %d\n", L->data); return; }
        if (R->right && R->right->data == x) { printf("Uncle = %d\n", L->data); return; }
    }
    uncle(r->left, x);
    uncle(r->right, x);
}

int main() {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    printf("BFS: "); bfs(root); printf("\n");
    printf("DFS: "); dfs(root); printf("\n");

    children(root, 30);
    parent(root, 40);
    sibling(root, 40);
    grandparent(root, 20);
    uncle(root, 20);

    root = mirror(root);
    printf("Mirror Inorder: "); inorder(root); printf("\n");

    return 0;
}
