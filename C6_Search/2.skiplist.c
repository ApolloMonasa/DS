/*************************************************************************
	> File Name: 2.skiplist.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 20 Mar 2025 01:21:44 PM CST
 ************************************************************************/
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>

typedef struct Node {
    int key, level;
    struct Node *next, *down, *up;
} Node;



typedef struct Skiplist {
    Node *head, *tail;
    int max_level;
} Skiplist;

Node *getNewNode(int key, int n) {
    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        nodes[i].key = key;
        nodes[i].level = i;
        nodes[i].next = NULL;
        nodes[i].down = (i ? nodes + (i - 1) : NULL);
        nodes[i].up = (i < n - 1 ? nodes + (i + 1) : NULL);
    }
    return nodes + n - 1;
}

Skiplist *getNewSkiplist(int n) {
    Skiplist *s = (Skiplist *)malloc(sizeof(Skiplist));
    s->head = getNewNode(INT32_MIN, n);
    s->tail = getNewNode(INT32_MAX, n);
    s->max_level = n;
    Node *p = s->head, *q = s->tail;
    while (p) {
        p->next = q;
        p = p->down, q = q->down;
    }
    while (s->head->level) s->head = s->head->down;
    return s;
}

Node *find(Skiplist *s, int x) {
    Node *p = s->head;
    while (p && p->key != x) {
        if(p->next->key <= x) p = p->next;
        else p = p->down;
    }
    return p;
}

double randDouble() {
    #define MAX_RAND_N 1000000
    return (rand() % MAX_RAND_N) * 1.0 / MAX_RAND_N;
    #undef MAX_RAND_N
}

int randLevel(Skiplist *s) {
    int level = 1;
    double p = 0.5;
    while (randDouble() < p) level++;
#define min(a, b) ((a) < (b) ? (a) : (b))
    return min(s->max_level, level);
#undef min
}

void insert(Skiplist *s, int x) {
    int level = randLevel(s);
    while (s->head->level + 1 < level) s->head = s->head->up;
    Node *node = getNewNode(x, level);
    Node *p = s->head;
    while (p->level != node->level) p = p->down;
    while (p) {
        while (p->next->key < node->key) p = p->next;

        node->next = p->next;
        p->next = node;

        p = p->down;
        node = node->down;
    }
    return ;
}

void clearNode(Node *p) {
    if(!p) return;
    free(p);
    return ;
}

void clearSkiplist(Skiplist *s) {
    Node *p = s->head, *q;
    while (p->level != 0) p = p->down;
    while (p) {
        q = p->next;
        clearNode(p);
        p = q;
    }
    free(s);
    return ;
}


void output(Skiplist *s) {
    Node *p = s->head;
    int len = 0;
    for (int i = 0; i < s->head->level; i++) {
        len += printf("%6d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("=");
    printf("\n");
    while (p->level > 0) p = p->down;
    while(p) {
        _Bool flag = (p->key != INT32_MIN && p->key != INT32_MAX);
        for (Node *q = p; flag && q; q = q->up) {
            printf("%6d", q->key);
        }
        if(flag) printf("\n");
        p = p->next;
    }
    return ;
}


int main() {
    srand(time(0));
    int x;
#define MAX_LEVEL 32
    Skiplist *s = getNewSkiplist(MAX_LEVEL);
#undef MAX_LEVEL
    while (printf("Input Node Key To Insert(-1 exit):\n") && (~scanf("%d", &x))) {
        if (x == -1) break;
        insert(s, x);
    }
    output(s);
    //find
    while (printf("Input Node Key To Find(-1 exit):\n") && (~scanf("%d", &x))) {
        if (x == -1) break;
        Node *p = find(s, x);
        printf("Find Result : \n");
        if (p) {
            printf("[Find It] : ");
            printf("key = %d, level = %d\n", p->key, p->level);
        } else {
            printf("[NULL]\n");
        }
    }
    clearSkiplist(s);
    return 0;
}
