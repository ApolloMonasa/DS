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
#define MAX_NODE 10


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

Node *deserialize(char *buff, int n){
    Node **s = (Node **)malloc(sizeof(Node *) * MAX_NODE);
    int top = -1, flag = 0, scode = 0;
    Node *p = NULL, *root = NULL;//p指向最后一个生成的节点, root 记录最后一个弹出的节点即根节点
    for (int i = 0; buff[i]; i++) {
        switch (scode) {
            case 0: {//任务分发
                if (buff[i] >= '0' && buff[i] <= '9') scode = 1;
                else if (buff[i] == '(') scode = 2;
                else if (buff[i] == ',') scode = 3;
                else scode = 4;
                i--;
            } break;
            case 1: {
                int key = 0;
                while(buff[i] <= '9' && buff[i] >= '0') {
                    key = key * 10 + (buff[i] - '0');
                    i++;
                }
                i--;
                p = getNewNode(key);
                if(top >= 0 && flag == 0) s[top]->lchild = p;
                if(top >= 0 && flag == 1) s[top]->rchild = p;
                scode = 0;
            } break;
            case 2: {
                s[++top] = p;
                flag = 0;
                scode = 0;
            } break;
            case 3: {flag = 1; scode = 0; } break;
            case 4: {
                root = s[top];
                top -= 1;
                scode = 0;
            } break;
        }
    }
    return root;
}


int main() {
    srand(time(0));
    Node *root = getRandomBinaryTree(MAX_NODE);
    serialize(root);
    output(root);
    printf("Buff[] : %s\n", buff);
    Node *new_root = deserialize(buff, len);
    output(new_root);
    return 0;
}
