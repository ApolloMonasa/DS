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

#define MAX_M 3
#define MAX_OP 10
#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}
#define LOW_BOUND ((MAX_M + 1) / 2 - 1)
#define L(root, pos) (root->next[pos])
#define R(root, pos) (root->next[pos+1])
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

void erase_pos(Node *root, int pos) {
    for (int i = pos + 1; i < root->n; i++) {
        root->key[i-1] = root->key[i];
    }
    return ;
}

void r_r(Node *root, int pos) {
    for (int i = R(root, pos)->n + 1; i >= 0; i--) {
        R(root, pos)->key[i] = R(root, pos)->key[i-1];
        R(root, pos)->next[i] = R(root, pos)->next[i-1];
    }
    R(root, pos)->key[0] = root->key[pos];
    root->key[pos] = LAST_KEY(L(root, pos));
    R(root, pos)->next[0] = LAST_CHILD(L(root, pos));
    LAST_CHILD(L(root, pos)) = NULL;
    R(root, pos)->n += 1;
    L(root, pos)->n -= 1;
    return ;
}

void l_r(Node *root, int pos) {
    LAST_KEY(L(root, pos)) = root->key[pos];
    L(root, pos)->n += 1;

    root->key[pos]  = R(root, pos)->key[0];
    LAST_CHILD(L(root, pos)) = R(root, pos)->next[0];
    for (int i = 0; i < R(root, pos)->n; i++) {
        R(root, pos)->key[i] = R(root, pos)->key[i+1];
        R(root, pos)->next[i] = R(root, pos)->next[i+1];
    }
    LAST_CHILD(R(root, pos)) = NULL;
    R(root, pos)->n -= 1;
    return ;
}

void merge(Node *root, int pos) {
    Node *node = getNewNode();
    for (int i = 0; i < L(root, pos)->n; i++) {
        node->key[i] = L(root, pos)->key[i];
        node->next[i] = L(root, pos)->next[i];
    }
    node->n = L(root, pos)->n + 1;
    LAST_KEY(node) = root->key[pos];

    for (int i = 0; i <= R(root, pos)->n; i++) {
        node->key[i+node->n] = R(root, pos)->key[i];
        node->next[i+node->n] = R(root, pos)->next[i];
    }
    node->n += R(root, pos)->n;
    free(L(root, pos));
    free(R(root, pos));
    for (int i = pos + 1; i <= root->n; i++) {
        root->key[i-1] = root->key[i];
        root->next[i-1] = root->next[i];
    }
    root->next[pos] = node;
    root->n -= 1;
    return ;
}

Node *erase_maintain(Node *root, int pos) {
    if (root->next[pos]->n >= LOW_BOUND) return root;
    if (pos > 0 && root->next[pos - 1]->n > LOW_BOUND) {
        r_r(root,pos - 1);
    } else if (pos < root->n && root->next[pos + 1]->n > LOW_BOUND) {
        l_r(root, pos);
    } else {
        //merge
        if (pos > 0) merge(root, pos - 1);//merge(i, j) : (j and j + 1)
        else merge(root, pos);
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NULL) return NULL;
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos += 1;
    if (root->next[0] == NULL) {
        if (pos < root->n && root->key[pos] == key) erase_pos(root, pos);
        return root;
    } else {
        //not end
        if (pos < root->n && root->key[pos] == key) {
            Node *temp = root->next[pos];
            while (temp->next[temp->n]) temp = temp->next[temp->n];
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
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
        printf("\ninsert %d to BTree : \n", val);
        output(root);
    }
    
    printf("Erase!\n");
    int x;
    while (~scanf("%d", &x)) {
        printf("erase %d from B_Tree :\n", x);
        root = erase(root, x);
        output(root);
    }
    return 0;
}
__attribute__((constructor))
void _init_rand_() {
    srand(time(0));
    return ;
}
