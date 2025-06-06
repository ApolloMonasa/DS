/*************************************************************************
	> File Name: 4.serialize_deserialize.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 10:58:55 PM CST
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
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
    if(!root) return getNewNode(key);
    if(rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *getRandomBinaryTree(int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, rand() % 100);
    }
    return root;
}

void clear(Node *root) {
    if(!root) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

char buff[1000];
int len;

void __serialize(Node *root) {
    if(!root) return ;
    //root
    len += sprintf(buff + len,  "%d", root->key);
    if(root->lchild == NULL && root->rchild == NULL) return ;
    len += sprintf(buff + len, "(");
    __serialize(root->lchild);
    if(root->rchild) {
        len += sprintf(buff + len, ",");
        __serialize(root->rchild);
    }
    len += sprintf(buff + len, ")");
    return ;
}



void serialize(Node *root) {
    memset(buff, 0, sizeof(buff));
    len = 0;
    __serialize(root);
    return ;
}

void print(Node *root) {
    printf("%d(%d, %d)\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    return ;
}

void output(Node *root) {
    if(!root) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_NODE 10
    Node *root = getRandomBinaryTree(MAX_NODE);
    serialize(root);
    output(root);
    printf("Buff[] : %s\n", buff);
    return 0;
}
