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
    int key, ltag, rtag;//1:thread, 0: edge
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = p->rtag = 0;
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
    if(root->ltag == 0) clear(root->lchild);
    if(root->rtag == 0) clear(root->rchild);
    free(root);
}

void pre_order(Node *root){
    if(!root) return ;
    cout << root->key << " ";
    if(root->ltag == 0) pre_order(root->lchild);
    if(root->rtag == 0) pre_order(root->rchild);
    return ;
}

void mid_order(Node *root){
    if(!root) return ;
    if(root->ltag == 0) mid_order(root->lchild);
    cout << root->key << " ";
    if(root->rtag == 0) mid_order(root->rchild);
    return ;
}
void post_order(Node *root){
    if(!root) return ;
    if(root->ltag == 0) post_order(root->lchild);
    if(root->rtag == 0) post_order(root->rchild);
    cout << root->key << " ";
    return ;
}

Node *pre_node = NULL, *inorder_root = NULL;
void __build_inorder_thread(Node *root) {
    if(!root) return ;
    if(root->ltag == 0) __build_inorder_thread(root->lchild);
    //原本我们在中序遍历的这个位置可以依次访问到中序遍历序列的每一个节点

    if(inorder_root == NULL) inorder_root = root;

    if(root->lchild == NULL) {
        root->lchild = pre_node;
        root->ltag = 1;
    }
    if(pre_node && pre_node->rchild == NULL) {
        pre_node->rchild = root;
        pre_node->rtag = 1;
    }
    pre_node = root;
    if(root->rtag == 0) __build_inorder_thread(root->rchild);
    return ;
}

void build_inorder_thread(Node *root) {
    __build_inorder_thread(root);
    pre_node->rchild = NULL;
    pre_node->rtag = 1;
    return ;
}

Node *getNext(Node *root){
    if(root->rtag == 1) return root->rchild;
    root = root->rchild;
    while(root->ltag == 0 && root->lchild) root = root->lchild;
    return root;
}

int main() {
    srand(time(0));
    #define MAX_NODE 10
    Node *root = NULL;
    for(int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100 + 1);
    }

    pre_node = inorder_root = NULL;
    build_inorder_thread(root);

    pre_order(root); printf("\n");
    mid_order(root); printf("\n");
    post_order(root);printf("\n");
    //like linklist
    Node *node = inorder_root;
    while(node){
        printf("%d ", node->key);
        node = getNext(node);
    }
    cout << endl;
    clear(root);
    return 0;
}
