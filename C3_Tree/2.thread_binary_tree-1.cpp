/*************************************************************************
	> File Name: 2.thread_binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 06:10:53 PM CST
 ************************************************************************/


#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;

typedef struct Node {
    int key, ltag, rtag;
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

void clear(Node *root) {
    if(!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void pre_order(Node *root){
    if(!root) return ;
    cout << root->key << " ";
    pre_order(root->lchild);
    pre_order(root->rchild);
    return ;
}

void mid_order(Node *root){
    if(!root) return ;
    mid_order(root->lchild);
    cout << root->key << " ";
    mid_order(root->rchild);
    return ;
}
void post_order(Node *root){
    if(!root) return ;
    post_order(root->lchild);
    post_order(root->rchild);
    cout << root->key << " ";
    return ;
}

int main() {
    srand(time(0));
    #define MAX_NODE 10
    Node *root = NULL;
    for(int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100 + 1);
    }
    pre_order(root); printf("\n");
    mid_order(root); printf("\n");
    post_order(root);printf("\n");
    clear(root);
    return 0;
}
