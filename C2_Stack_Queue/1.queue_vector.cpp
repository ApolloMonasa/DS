/*************************************************************************
	> File Name: 1.queue_vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 06:15:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector {
    int *data;
    int size;
} vector;

vector *initVector(int n) {
    vector *v = (vector *)malloc(sizeof(vector));
    v->size = n;
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

void clearVector(vector *v){
    if(!v) return ;
    free(v->data);
    free(v);
    return ;
}

int vectorSeek(vector *v, int pos) {
    if(pos < 0 || pos >= v->size) return -1;
    return v->data[pos];
}

int insertVector(vector *v, int pos, int val) {
    if(pos < 0 || pos >= v->size) return 0;
    v->data[pos] = val;
    return 1;
}

typedef struct Queue {
    vector *data;
    int size, head, tail, count;
} Queue;

Queue *initQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = initVector(n);
    q->size = n;
    q->head = q->tail = q->count = 0;
    return q;
}

int empty(Queue *q){
    return q->count == 0;
}


int front(Queue *q){
    return  vectorSeek(q->data, q->head);
}

int push(Queue *q, int val){
    if(q->count == q->size) return 0;
    insertVector(q->data, q->tail, val);
    q->tail += 1;
    if(q->tail == q->size) q->tail = 0;
    q->count += 1;
    return 1;
}

int pop(Queue *q){
    if(empty(q)) return 0;
    q->head += 1;
    q->count -= 1;
    return 1;
}

void clearQueue(Queue *q){
    if(q == NULL) return ;
    clearVector(q->data);
    free(q);
    return ;
}

void outputQueue(Queue *q) {
    printf("Queue:");
    for(int i = 0; i < q->count; i++) {
        printf("%4d", vectorSeek(q->data, (q->head + i) % q->size));
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(NULL));
    #define MAX_OP 10
    Queue *q = initQueue(5);
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

