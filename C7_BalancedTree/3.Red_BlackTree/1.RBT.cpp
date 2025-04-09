/*************************************************************************
	> File Name: 1.RBT.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 01 Apr 2025 01:41:32 PM CST
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define K(n) (n->key)
#define C(n) (n->color)

typedef enum COLOR {
    R,//red
    B,//black
    DB//double black
} COLOR;

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
    COLOR color;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void _init_() {
    srand(time(0));
    NIL->key = -1;
    NIL->color = B;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = R;
    p->lchild = p->rchild = NIL;
    return p;
}

bool has_red_node(Node *root) {
    return C(L(root)) == R || C(R(root)) == R;
}

Node *left_r(Node *root) {
    Node *NewRoot = R(root);
    R(root) = L(NewRoot);
    L(NewRoot) = root;
    return NewRoot;
}

Node *right_r(Node *root) {
    Node *NewRoot = L(root);
    L(root) = R(NewRoot);
    R(NewRoot) = root;
    return NewRoot;
}

Node *insert_maintain(Node *root) {
    int flag = 0;
    if(C(L(root)) == R && has_red_node(L(root))) flag = 1;
    if(C(R(root)) == R && has_red_node(R(root))) flag = 2;
    if(flag == 0) return root;
    if(C(L(root)) == C(R(root))) goto red_up_maintain;
    else {
        if (flag == 1) {
            if (C(R(L(root))) == R) {
                L(root) = left_r(L(root));
            }
            root = right_r(root);
        } else {
            if (C(L(R(root))) == R) {
                R(root) = right_r(R(root));
            }
            root = left_r(root);
        }
    }
red_up_maintain:
    C(root) = R;
    C(L(root)) = C(R(root)) = B;
    return root;
}

Node *__insert(Node *root, int key) {
    if(root == NIL) return getNewNode(key);
    if(K(root) == key) return root;
    if(key < K(root)) L(root) = __insert(L(root), key);
    else R(root) = __insert(R(root), key);
    return insert_maintain(root);
}


Node *insert(Node *root, int key) {
    root = __insert(root, key);
    C(root) = B;
    return root;
}

Node *predecessor(Node *root) {
    Node *tmp = L(root);
    while (R(tmp) != NIL) tmp = R(tmp);
    return tmp;
}

Node *erase_maintain(Node *root) {
    if (C(L(root)) != DB && C(R(root)) != DB) return root;
    if (has_red_node(root)) {
        C(root) = R;
        if(C(L(root)) == R) {
            root = right_r(root);
            R(root) = erase_maintain(R(root));
        }
        else {
            root = left_r(root);
            L(root) = erase_maintain(L(root));
        }
        C(root) = B;
        return root;
    }
    if (C(L(root)) == DB && !has_red_node(R(root)) ||
       C(R(root)) == DB && !has_red_node(L(root))) {
        C(root)  = (COLOR)(C(root) + 1);
        C(L(root))  = (COLOR)(C(L(root)) - 1);
        C(R(root))  = (COLOR)(C(R(root)) - 1);
        return root;
    }
    if (C(R(root)) == DB) {
        C(R(root)) = B;
        if (C(L(L(root))) != R) {
            L(root) = left_r(L(root));
        }
        C(L(root)) = C(root);
        root = right_r(root);
    } else {
        C(L(root)) = B;
        if (C(R(R(root))) != R) {
            R(root) = right_r(L(root));
        }
        C(R(root)) = C(root);
        root = left_r(root);
    }
    C(R(root)) = C(L(root)) = B;
    return root;
}

Node *__erase(Node *root, int key) {
    if(root == NIL) return root;
    if(key < K(root)) {
        L(root) = __erase(L(root), key);
    } else if (key > K(root)) {
        R(root) = __erase(R(root), key);
    } else {
        if (L(root) == NIL || R(root) == NIL) {
            Node *tmp = L(root) == NIL ? R(root) : L(root);
            C(tmp) = (COLOR)(C(tmp) + C(root));
            free(root);
            return tmp;
        } else {
            Node *tmp = predecessor(root);
            K(root) = K(tmp);
            L(root) = __erase(L(root), K(tmp));
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    C(root) = B;
    return root;
}


void clear(Node *root) {
    if(root == NIL) return ;
    clear(L(root));
    clear(R(root));
    free(root);
    return ;
}

void output(Node *root) {
    if(root == NIL) return ;
    printf("(%3d<-(%3d|%3d)->%3d)\n",K(L(root)), C(root), K(root), K(R(root)));
    output(L(root));
    output(R(root));
    return ;
}

int main() {
    #define MAX_N 10
    Node *root = NIL;
    printf("INSERT!\n");
    for (int i = 0; i < MAX_N; i++) {
        int val = rand() % 100 + 1;
        printf("insert %d to Red_Black_Tree\n", val);
        root = insert(root, val);
        output(root);
        printf("\n");
    }
    printf("ERASE!\n");
    int x;
    while (~scanf("%d", &x)) {
        printf("\nerase %d from Red_Black_Tree\n", x);
        root = erase(root, x);
        output(root);
    }

    return 0;
}
