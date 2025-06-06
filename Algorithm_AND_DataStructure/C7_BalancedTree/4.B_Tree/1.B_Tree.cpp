/*************************************************************************
	> File Name: 1.B_Tree.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 06 Apr 2025 02:19:46 PM CST
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>

#define MAX_M 5
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
    if(root == NULL) {
        root = getNewNode();
        root->key[(root->n)++] = key;
        return root;
    }
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos++;
    if (root->key[pos] == key) return root;
    for (int i = root->n-1; i >= pos; i--) {
        root->key[i+1] = root->key[i];
    }
    root->key[pos] = key;
    root->n += 1;
    return root;
}

Node *insert_maintain(Node *root, Node *child, int pos) {
    if (child->n < MAX_M) return root;
    int splitpos = MAX_M / 2;
    Node *node1 = getNewNode();
    Node *node2 = getNewNode();
    node1->n = splitpos;
    node2->n = MAX_M - 1 - splitpos;
    for (int i = 0; i <= splitpos; i++) {
        node1->key[i] = child->key[i];
        node1->next[i] = child->next[i];
    }
    for (int i = 0; i <= node2->n; i++) {
        node2->key[i] = child->key[i+splitpos+1];
        node2->next[i] = child->next[i+splitpos+1];
    }
    for (int i = root->n; i >= pos; i--) {
        root->key[i+1] = root->key[i];
        root->next[i+1] = root->next[i];
    }

    root->key[pos] = child->key[splitpos];
    root->next[pos] = node1;
    root->next[pos+1] = node2;
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
    root = __insert(root, key);//可能产生失衡根
    if(root->n >= MAX_M) {
        Node *p = getNewNode();
        p->next[0] = root;
        root = insert_maintain(p, root, 0);
    }
    return root;
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < root->n; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

void print_node(Node *root) {
    printf("%d(keys) : ", root->n);
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
    if (root == NULL) return ;
    print_node(root);
    for (int i = 0; i <= root->n; i++) {
        output(root->next[i]);
    }
    return ;
}

int main() {
    #define MAX_OP 25
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
        printf("\ninsert %d to BTree : \n", val);
        output(root);
    }
    
    return 0;
}
__attribute__((constructor))
void _init_rand_() {
    srand(time(0));
    return ;
}
