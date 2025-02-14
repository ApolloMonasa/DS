/*************************************************************************
	> File Name: 2.queue_linklist.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 07:59:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    int data;
    Node *next;
} Node;

typedef struct Linklist {
    Node head, *tail;
} LinkList;

Node *getNewNode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *initLinkList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->tail = &(l->head);
    return l;
}

void clearLinkList(LinkList *l) {
    Node *p = l->head.next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}

typedef struct Queue {
    LinkList *l;
    int size, count;
} Queue;



Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->l = initLinkList();
    q->count = 0;
    return q;
}

int is_empty_list(Linklist *l) {
    return l->head.next == NULL;
}

int frontList(Linklist *l) {
    if(is_empty_list(l)) return 0;
    return l->head.next->data;
}

int insertTail(Linklist *l, int val) {
    //先把val值封装成一个链表节点
    Node *node = getNewNode(val);
    l->tail->next = node;
    l->tail = node;
    return 1;
}

int eraseHead(Linklist *l) {
    if(is_empty_list(l)) return 0;
    Node *p = l->head.next;
    l->head.next = l->head.next->next;
    //容易忘记tail
    if(p == l->tail) l->tail = &(l->head);
    free(p);
    return 1;
}

int empty(Queue *q) {
    return q->count;
}

int front(Queue *q) {
    if(empty(q)) return 0;
    return frontList(q->l);
}

int push(Queue *q, int val) {
    //链表实现无所谓满不满
    insertTail(q->l, val);
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    eraseHead(q->l);
    q->count -= 1;
    return 1;
}

void clearQueue(Queue *q) {
    if(q == NULL) return ;
    clearLinkList(q->l);
    free(q);
    return ;
}

void outputQueue(Queue *q) {
    printf("Queue:");
    Node *p = q->l->head.next;
    for(int i = 0; i < q->count; i++, p = p->next) {
        printf("%4d", p->data);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(NULL));
    #define MAX_OP 10
    Queue *q = initQueue();
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, val = rand() % 100;//0:pop | 1 2 3 4: push
        switch (op) {
            case 0:
                printf("front of queue : %d\n", front(q));
                pop(q);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("push %d to queue\n", val);
                push(q, val);
                break;
        }
        outputQueue(q);
    }
    clearQueue(q);
    return 0;
}
