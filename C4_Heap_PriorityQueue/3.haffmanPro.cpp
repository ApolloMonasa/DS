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

#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}

typedef struct Node {
    char ch;
    int freq;
    struct Node *lchild, *rchild;
} Node;

typedef struct Heap {
    Node **__data, **data;
    int n, size;
} Heap;

Heap *getNewHeap(int size) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = size;
    h->n = 0;
    h->__data = (Node **)malloc(sizeof(Node *) * size);
    h->data = h->__data - 1;
    return h;
}

int fullHeap(Heap *h) {
    return h->size == h->n;
}

int emptyHeap(Heap *h) {
    return h->n == 0;
}

Node *top(Heap *h) {
    if(emptyHeap(h)) return NULL;
    return h->data[1];
}

int cmpHeap(Heap *h, int i , int j) {
    return h->data[i]->freq < h->data[j]->freq;
}

void up_maintain(Heap *h, int i) {
    while(i > 1 && h->data[i]->freq < h->data[i/2]->freq) {
        swap(h->data[i], h->data[i/2]);
        i = i/2;
    }
    return ;
}

void down_maintain(Heap *h, int i) {
    while(i * 2 <= h->n) {
        int ind = i, l = i * 2, r = l + 1;
        if(cmpHeap(h, l, ind)) ind = l;
        if(r <= h->n && cmpHeap(h, r, ind)) ind = r;
        if(ind == i) return;
        swap(h->data[i], h->data[ind]);
        i = ind;
    }
    return ;
}

int pushHeap(Heap *h, Node *n) {
    if(fullHeap(h)) return 0;
    h->n += 1;
    h->data[h->n] = n;
    up_maintain(h, h->n);
    return 1;
}

int popHeap(Heap *h) {
    if(emptyHeap(h)) return 0;
    h->data[1] = h->data[h->n];
    h->n -= 1;
    down_maintain(h, 1);
    return 1;
}

void clearHeap(Heap *h) {
    if (!h) return ;
    free(h->__data);
    free(h);
    return ;
}

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
    Heap *h = getNewHeap(n);
    for(int i = 0; i < n; i++) pushHeap(h, node_arr[i]);
    for(int i = 1; i < n; i++) {
        Node *node1 = top(h);
        popHeap(h);
        Node *node2 = top(h);
        popHeap(h);
        Node *node3 = getNewNode(node1->freq + node2->freq, 0);
        node3->lchild = node1;
        node3->rchild = node2;
        pushHeap(h, node3);
    }
    return top(h);
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
