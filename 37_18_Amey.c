#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET 26  


struct Trie {
    struct Trie* child[ALPHABET];
    bool isEnd;
};

struct Trie* createNode() {
    struct Trie* node = malloc(sizeof(struct Trie));
    node->isEnd = false;
    for (int i = 0; i < ALPHABET; i++)
        node->child[i] = NULL;
    return node;
}
void insert(struct Trie* root, char* word) {
    struct Trie* cur = root;
    int i, idx;

    for (i = 0; word[i] != '\0'; i++) {
        idx = word[i] - 'a';
        if (cur->child[idx] == NULL)
            cur->child[idx] = createNode();
        cur = cur->child[idx];
    }
    cur->isEnd = true;   
}

bool search(struct Trie* root, char* word) {
    struct Trie* cur = root;
    int i, idx;

    for (i = 0; word[i] != '\0'; i++) {
        idx = word[i] - 'a';
        if (cur->child[idx] == NULL)
            return false;
        cur = cur->child[idx];
    }
    return cur->isEnd; 
}

int main() {
    struct Trie* root = createNode();

    insert(root, "cat");
    insert(root, "cap");
    insert(root, "dog");

    printf("Searching 'cat' : %s\n", search(root, "cat") ? "Found" : "Not Found");
    printf("Searching 'cap' : %s\n", search(root, "cap") ? "Found" : "Not Found");
    printf("Searching 'can' : %s\n", search(root, "can") ? "Found" : "Not Found");

    return 0;
}
