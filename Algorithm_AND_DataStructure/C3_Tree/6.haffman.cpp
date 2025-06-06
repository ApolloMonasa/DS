/*************************************************************************
	> File Name: 6.haffman.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 02:53:02 PM CST
 ************************************************************************/

#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX_CHAR_NUM 128
using namespace std;

typedef struct Node {
    char ch;
    int freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int freq, char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if(!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void swap_node(Node **node_arr, int i, int j) {
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
}

int find_min_node(Node **node_arr, int n) {
    int ind = 0;
    for(int j = 1; j <= n; j++) {
        if(node_arr[ind]->freq > node_arr[j]->freq) ind = j;
    }
    return ind;
}

Node *buildHaffmanTree(Node **node_arr, int n) {
    for(int i = 1; i < n; i++) {//n-1轮
        //find tow nodes
        int ind1 = find_min_node(node_arr, n - i);
        swap_node(node_arr, ind1, n - i);
        int ind2 = find_min_node(node_arr, n - i - 1);
        swap_node(node_arr, ind2, n - i - 1);
        //add
        int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
        Node *node = getNewNode(freq, 0);
        node->lchild = node_arr[n - i - 1];
        node->rchild = node_arr[n - i];
        node_arr[n - i - 1] = node;
    }
    return node_arr[0];
}

char *char_code[128] = {0};


void extractHaffmanCode(Node *root, char *buff, int k) {
    buff[k] = 0;
    if(root->lchild == 0 && root->rchild == NULL) {
        char_code[root->ch] = strdup(buff);//////////////////////////new
        printf("%c : %s\n", root->ch, buff);
        return ;
    }
    buff[k] = '0';
    extractHaffmanCode(root->lchild, buff, k+1);
    buff[k] = '1';
    extractHaffmanCode(root->rchild, buff, k+1);
    return ;
}

int main() {
    int n, freq;
    char ch;
    scanf("%d", &n);
    Node **node_arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &ch, &freq);
        node_arr[i] = getNewNode(freq, ch);
    }
    Node *root = buildHaffmanTree(node_arr, n);
    char buff[1000];
    extractHaffmanCode(root, buff, 0);
    cout << endl;
    for(int i = 0; i < 128; i++) {
        if(char_code[i] == 0) continue;
        printf("%c : %s\n", i, char_code[i]);
    }
    clear(root);
    return 0;
}
