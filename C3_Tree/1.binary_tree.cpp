/*************************************************************************
	> File Name: 1.binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 05:24:39 PM CST
 ************************************************************************/

#include<time.h>
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node* GetNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}
//随机插入
Node *insert(Node *root, int key) {
    if(root == NULL) return GetNewNode(key);
    if(rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

void clear(Node *root) {
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

#define MAX_NODE 10
Node *queue[MAX_NODE + 5];
int head, tail;

void bfs(Node *root) {
    head = tail = 0;
    queue[tail++] = root;
    while(head < tail) {
        Node *node = queue[head];
        printf("\nnode : %d\n",node->key);
        if(node->lchild) {
            queue[tail++] = node->lchild;
            printf("\t%d->%d (left)\n", node->key, node->lchild->key);
        }
        if(node->rchild) {
            queue[tail++] = node->rchild;
            printf("\t%d->%d (rchild)\n", node->key, node->rchild->key);
        }
        //处理完弹出
        head++;
    }
    return ;
}
int tot = 0;

void dfs(Node *root) {
    if(root == NULL) return ;
    int start, end;
    tot++;
    start = tot;
    if(root->lchild) dfs(root->lchild);
    if(root->rchild) dfs(root->rchild);
    tot++;
    end = tot;
    printf("%d :[%d, %d]\n", root->key, start, end);
    return ;
}

int main() {
    srand(time(0));
    Node *root = NULL;
    for(int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100 + 1);
    }
    //广度优先遍历bfs(Breadth-First Search)
    bfs(root);
    //深度优先遍历dfs(Depth-First Search)
    dfs(root);
    return 0;
}
