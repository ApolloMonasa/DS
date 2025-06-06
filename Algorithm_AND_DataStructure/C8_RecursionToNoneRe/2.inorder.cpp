/*************************************************************************
	> File Name: 1.BST.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 29 Mar 2025 10:09:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>
#include<stdbool.h>
#include<stack>
using namespace std;

#define KEY(n) (n ? n->key : -1)
typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (!root) return getNewNode(key);
    if(key == root->key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node*temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if(root == NULL) return root;
    if(key < root->key) root->lchild = erase(root->lchild, key);
    else if(key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if(root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if(root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void clear(Node *root) {
    if(!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

__attribute__((constructor))
void _init() {
    srand(time(0));
}

void output(Node *root) {
    if(!root) return ;
    printf("(%d ; %d, %d)\n",
        KEY(root),
        KEY(root->lchild),
        KEY(root->rchild)
        );
    output(root->lchild);
    output(root->rchild);
    return ;
}

void in_order(Node *root) {
    if(!root) return ; // code = 0
    in_order(root->lchild);//code = 1
    printf("%d ", root->key);//code = 2
    in_order(root->rchild);//code = 3
    return ;
}

struct Data {
    Node *root;
    int code;
    Data(Node *root) : root(root) {
        code = 0;
    }
};

void unrecursion_inorder(Node *root) {
    stack<Data> s;
    Data d(root);
    s.push(d);
    while(!s.empty()) {
        Data& cur = s.top();
        switch (cur.code) {
            case 0 : {
                if (cur.root == NULL) {
                    s.pop();
                } else {
                    cur.code = 1;
                }
            } break;
            case 1 : {
                Data d(cur.root->lchild);
                s.push(d);
                cur.code = 2;
            } break;
            case 2 : {
                printf("%d ", cur.root->key);
                cur.code = 3;
            } break;
            case 3 : {
                Data d(cur.root->rchild);
                s.push(d);
                cur.code = 4;
            } break;
            case 4 : {
                s.pop();
            } break;
        }
    }
    return ;
}

int main() {
    #define MAX_OP 10
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int key = rand() % 100;
        printf("insert key %d to BST\n", key);
        root = insert(root, key);
    }
    output(root);
    printf("in_order : \n");
    in_order(root);
    printf("\n");
    unrecursion_inorder(root);
    printf("\n");

    int x;
    while(~scanf("%d", &x)) {
        printf("erase %d from BST\n", x);
        root = erase(root, x);
        in_order(root);
        printf("\n");
    }
    
    return 0;
}
