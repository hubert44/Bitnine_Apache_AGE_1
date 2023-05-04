#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    NUM,
} TypeTag;

Node *makeNode(TypeTag type, int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int fibo(int n) {
    if (n < 2) {
        return n;
    }
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

Node *calc(Node *node) {
    if (node->type == NUM) {
        return node;
    } else {
        Node *left = calc(node->left);
        Node *right = calc(node->right);
        switch (node->type) {
            case ADD:
                return makeNode(NUM, left->value + right->value, NULL, NULL);
            case SUB:
                return makeNode(NUM, left->value - right->value, NULL, NULL);
            case MUL:
                return makeNode(NUM, left->value * right->value, NULL, NULL);
            case DIV:
                return makeNode(NUM, left->value / right->value, NULL, NULL);
            default:
                return NULL;
        }
    }
}

int main() {
    Node *add = makeNode(ADD, 10, NULL, makeNode(NUM, 6, NULL, NULL));
    Node *mul = makeNode(MUL, 5, NULL, makeNode(NUM, 4, NULL, NULL));
    Node *sub = makeNode(SUB, 0, mul, add);
    Node *fiboNode = makeNode(SUB, 0, sub, NULL);
    Node *result = calc(fiboNode);
    printf("add : %d\n", calc(add)->value);
    printf("mul : %d\n", calc(mul)->value);
    printf("sub : %d\n", calc(sub)->value);
    printf("fibo : %d\n", fibo(result->value));
    return 0;
}
