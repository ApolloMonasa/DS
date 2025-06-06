/*************************************************************************
	> File Name: 3.finall.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 09 Apr 2025 11:33:23 PM CST
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define MAX_M 3
#define MAX_OP 10
#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b, b = __c; \
}
#define LOW_BOUND ((MAX_M + 1) / 2 - 1)
#define L(root, pos) (root->next[pos])
#define R(root, pos) (root->next[pos + 1])
#define LAST_KEY(root) (root->key[root->n - 1])
#define LAST_CHILD(root) (root->next[root->n])

typedef struct Node {
    int n;
    int key[MAX_M + 1];
    struct Node *next[MAX_M + 1];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->n = 0;
    memset(p->next, 0, sizeof(Node *) * (MAX_M + 1));
    return p;
}

Node *insert_key(Node *root, int key) {
    if (root == NULL) {
        root = getNewNode();
        root->key[(root->n)++] = key;
        return root;
    }
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos++;
    if (pos < root->n && root->key[pos] == key) return root;
    for (int i = root->n - 1; i >= pos; i--) {
        root->key[i + 1] = root->key[i];
    }
    root->key[pos] = key;
    root->n += 1;
    return root;
}

Node *insert_maintain(Node *root, Node *child, int pos) {
    if (child->n < MAX_M) return root;
    
    int split_pos = child->n / 2;
    Node *node1 = getNewNode();
    Node *node2 = getNewNode();
    
    node1->n = split_pos;
    for (int i = 0; i < split_pos; i++) {
        node1->key[i] = child->key[i];
        node1->next[i] = child->next[i];
    }
    node1->next[split_pos] = child->next[split_pos];
    
    node2->n = child->n - split_pos - 1;
    for (int i = 0; i < node2->n; i++) {
        node2->key[i] = child->key[i + split_pos + 1];
        node2->next[i] = child->next[i + split_pos + 1];
    }
    node2->next[node2->n] = child->next[child->n];
    
    int promoted_key = child->key[split_pos];
    
    for (int i = root->n; i > pos; i--) {
        root->key[i] = root->key[i - 1];
        root->next[i + 1] = root->next[i];
    }
    
    root->key[pos] = promoted_key;
    root->next[pos] = node1;
    root->next[pos + 1] = node2;
    root->n += 1;
    
    free(child);
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NULL || root->next[0] == NULL) {
        return insert_key(root, key);
    }
    
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos++;
    if (pos < root->n && root->key[pos] == key) return root;
    
    root->next[pos] = __insert(root->next[pos], key);
    return insert_maintain(root, root->next[pos], pos);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    if (root->n >= MAX_M) {
        Node *new_root = getNewNode();
        new_root->next[0] = root;
        root = insert_maintain(new_root, root, 0);
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i <= root->n; i++) {
        clear(root->next[i]);
    }
    free(root);
}

void print_node(Node *root) {
    printf("%d(keys): ", root->n);
    for (int i = 0; i < root->n; i++) {
        printf("%4d", root->key[i]);
    }
    printf(" | ");
    if (root->next[0] == NULL) goto output_end;
    for (int i = 0; i <= root->n; i++) {
        printf("%4d", root->next[i]->key[0]);
    }
output_end:
    printf("\n");
}

void output(Node *root) {
    if (root == NULL) return;
    print_node(root);
    for (int i = 0; i <= root->n; i++) {
        output(root->next[i]);
    }
}

void erase_pos(Node *root, int pos) {
    for (int i = pos + 1; i < root->n; i++) {
        root->key[i - 1] = root->key[i];
    }
    root->n -= 1;
}

void right_rotate(Node *root, int pos) {
    Node *left = L(root, pos);
    Node *right = R(root, pos);
    
    for (int i = right->n; i > 0; i--) {
        right->key[i] = right->key[i - 1];
        right->next[i + 1] = right->next[i];
    }
    right->next[1] = right->next[0];
    
    right->key[0] = root->key[pos];
    right->next[0] = LAST_CHILD(left);
    right->n += 1;
    
    root->key[pos] = LAST_KEY(left);
    LAST_CHILD(left) = NULL;
    left->n -= 1;
}

void left_rotate(Node *root, int pos) {
    Node *left = L(root, pos);
    Node *right = R(root, pos);
    
    left->key[left->n] = root->key[pos];
    left->next[left->n + 1] = right->next[0];
    left->n += 1;
    
    root->key[pos] = right->key[0];
    right->next[0] = right->next[1];
    
    for (int i = 1; i < right->n; i++) {
        right->key[i - 1] = right->key[i];
        right->next[i] = right->next[i + 1];
    }
    right->n -= 1;
}

void merge_nodes(Node *root, int pos) {
    Node *left = L(root, pos);
    Node *right = R(root, pos);
    
    left->key[left->n] = root->key[pos];
    left->n += 1;
    
    for (int i = 0; i < right->n; i++) {
        left->key[left->n + i] = right->key[i];
        left->next[left->n + i] = right->next[i];
    }
    left->next[left->n + right->n] = right->next[right->n];
    left->n += right->n;
    
    for (int i = pos + 1; i < root->n; i++) {
        root->key[i - 1] = root->key[i];
        root->next[i] = root->next[i + 1];
    }
    root->n -= 1;
    
    free(right);
}

Node *erase_maintain(Node *root, int pos) {
    if (root->next[pos]->n >= LOW_BOUND) return root;
    
    if (pos > 0 && root->next[pos - 1]->n > LOW_BOUND) {
        right_rotate(root, pos - 1);
    } else if (pos < root->n && root->next[pos + 1]->n > LOW_BOUND) {
        left_rotate(root, pos);
    } else {
        if (pos > 0) {
            merge_nodes(root, pos - 1);
        } else {
            merge_nodes(root, pos);
        }
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NULL) return NULL;
    
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos++;
    
    if (root->next[0] == NULL) {
        if (pos < root->n && root->key[pos] == key) {
            erase_pos(root, pos);
        }
        return root;
    } else {
        if (pos < root->n && root->key[pos] == key) {
            Node *temp = root->next[pos];
            while (temp->next[temp->n]) {
                temp = temp->next[temp->n];
            }
            swap(root->key[pos], temp->key[temp->n - 1]);
        }
        root->next[pos] = __erase(root->next[pos], key);
    }
    return erase_maintain(root, pos);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    if (root->n == 0) {
        Node *temp = root->next[0];
        free(root);
        root = temp;
    }
    return root;
}

int main() {
    srand(time(0));
    Node *root = NULL;
    
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
        printf("\nInsert %d to BTree:\n", val);
        output(root);
    }
    
    printf("\nErase operation:\n");
    int x;
    while (scanf("%d", &x) != EOF) {
        printf("Erase %d from BTree:\n", x);
        root = erase(root, x);
        output(root);
    }
    
    clear(root);
    return 0;
}
