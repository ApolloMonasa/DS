/*************************************************************************
	> File Name: 1.priorityQueue.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 09:01:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROOT 1
#define cmp >
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)
#define swap(a, b) {\
    printf("swap(%d, %d)\n", a, b);\
    __typeof(a) __c = (a);\
    (a) = (b);\
    (b) = __c;\
}

typedef struct PriorityQueue {
    int *__data, *data;
    int size, count;
} PriorityQueue;

PriorityQueue *initPQ(int size) {
    PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    p->__data = (int *)malloc(sizeof(int) * size);
    p->data = p->__data - 1; //1_based
    p->size = size;
    p->count = 0;
    return p;
}

int empty(PriorityQueue *p) {
    return p->count == 0;
}
int full(PriorityQueue *p) {
    return p->count == p->size;
}
int top(PriorityQueue *p) {
    return p->data[1];
}

void up_maintain(int * data, int i) {
    //if(i == ROOT) return ;
    //if(data[i] cmp data[FATHER(i)]){
    //    swap(data[i], data[FATHER(i)]);
    //    up_maintain(data, FATHER(i));
    //}//Recurtion
    printf("\nUP updata: %d\n", data[i]);
    while (i > ROOT && data[i] cmp data[FATHER(i)]) {
        swap(data[i], data[FATHER(i)]);
        i = FATHER(i);
    }
    printf("\n");
    return ;
}

void down_maintain(int *data, int i, int n) {
    int ind;
    printf("\nDOWN updata : %d\n", data[i]);
    while(LEFT(i) <= n) {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if (data[LEFT(i)] cmp data[ind]) ind = l;
        if (r <= n && data[r] cmp data[ind]) ind = r;
        if(ind == i) break;
        swap(data[i], data[ind]);
        i = ind;
    }
    printf("\n");
    return ;
}

int push(PriorityQueue *p, int x) {
    if(full(p)) return 0;
    if(!p) return 0;////////
    p->count += 1;
    p->data[p->count] = x;
    //maintain the quality
    up_maintain(p->data, p->count);
    return 1;
}

int pop(PriorityQueue *p) {
    if(empty(p)) return 0;
    p->data[ROOT] = p->data[p->count];
    p->count -= 1;
    down_maintain(p->data, ROOT, p->count);
    return 1;
}

void clearPQ(PriorityQueue *p) {
    if(!p) return ;
    free(p->data);
    free(p);
    return ;
}

void output(PriorityQueue *p) {
    printf("PQ(%d) :", p->count);
    for(int i = 1; i <= p->count; i++) {
        printf("%d ", p->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int op, x;
    #define MAX_OP 100
    PriorityQueue *p = initPQ(MAX_OP);
    printf("Input 1 and a number to insert\nInput any number else to pop top!\n");
    while(~scanf("%d", &op)) {
        if(op == 1) {
            scanf("%d", &x);
            printf("insert %d to PriorityQueue : \n", x);
            push(p,x);
            output(p);
        } else {
            printf("pop top : %d\n", top(p));
            pop(p);
            output(p);
        }
    }


    return 0;
}
