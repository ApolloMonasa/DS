/*************************************************************************
	> File Name: 1.AVL_Tree.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 31 Mar 2025 01:09:04 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

__attribute__((constructor))
void _init_(){
    srand(time(0));
}

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;//技巧：虚拟空节点
    return p;
}
#define H(n) (n->h)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define K(n) (n->key)

void updata_height(Node *root) {
    H(root) = 1 + (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root)));
    return ;
}

Node *left_rotate(Node *root) {
    printf("left rotate : %d\n", root->key);
    Node *new_node = R(root);
    R(root) = L(new_node);
    L(new_node) = root;
    updata_height(root);
    updata_height(new_node);
    return new_node;
}
Node *right_rotate(Node *root) {
    printf("right rotate : %d\n", root->key);
    Node *new_node = L(root);
    L(root) = R(new_node);
    R(new_node) = root;
    updata_height(root);
    updata_height(new_node);
    return new_node;
}

const char *type_str[5] = {
    "",
    "maintain type : LL",
    "maintain type : LR",
    "maintain type : RR",
    "maintain type : RL"
};

Node *maintain(Node *root) {//LL1 LR2 RR3 RL4
    if(abs(H(L(root)) - H(R(root))) <= 1) return root;
    int type = 0;

    if(H(L(root)) > H(R(root))) {
        //L
        if(H(R(L(root))) > H(L(L(root)))) {
            //LR
            L(root) = left_rotate(L(root)); type++;
        }
        root = right_rotate(root); type++;
    } else {
        type = 2;
        //R
        if(H(L(R(root))) > H(R(R(root)))) {
            //RL
            R(root) = right_rotate(R(root)); type++;
        }
        root = left_rotate(root); type++;
    }
    printf("%s\n", type_str[type]);
    return root;
}

Node *insert(Node *root, int key) {
    if(root == NIL) return getNewNode(key);
    if(root->key == key) return root;
    if(key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    //调整
    updata_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *tmp = L(root);
    while (R(tmp) != NIL) tmp = R(tmp);
    return tmp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (key < K(root)) L(root) = erase(L(root), key);
    else if (key > K(root)) R(root) = erase(L(root), key);
    else {
        if(L(root) == NIL ||  R(root) == NIL) {
            Node *tmp = L(root) != NIL ? L(root) : R(root);
            free(root);
            return tmp;
        } else {
            Node *tmp = predecessor(root);
            K(root) = K(tmp);
            L(root) = erase(L(root), K(tmp));
        }
    }
    updata_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if(root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if(root == NIL) return ;
    printf("(%d[%d] | %d, %d)\n", K(root), H(root), K(L(root)), K(R(root)));
    output(L(root));
    output(R(root));
    return ;
}

Node *find(Node *root, int x) {
    if(root == NIL) return root;
    if(x == K(root)) return root;
    if(x > K(root)) return find(R(root), x);
    else return find(L(root), x);
}

int main() {
    Node *root = NIL;
    printf("Insert Begin(-1 to exit):\n");
    int x;
    while(~scanf("%d", &x)) {
        if(x == -1) break;
        printf("Insert %d to AVL tree\n", x);
        root = insert(root, x);
        output(root);
    }
    printf("Erase Begin(-1 to exit):\n");
    while(~scanf("%d", &x)) {
        if(x == -1) break;
        printf("Erase %d from AVL tree\n", x);
        root = erase(root, x);
        output(root);
    }

    printf("Find Begin(-1 to exit):\n");
    while(~scanf("%d", &x)) {
        if(x == -1) break;
        printf("Find %d in AVL tree : %d\n", x, find(root, x) != NIL);

        output(root);
    }

    return 0;
}
