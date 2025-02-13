/*************************************************************************
	> File Name: 1.vector.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 04:22:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector {
    int size, count;
    int *data;
} vector;

vector *GetNewVector(int n) {
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

void clear(vector *v) {
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

int expand(vector *v) {
    if(v == NULL) return 0;
    printf("Expand v from %d to %d!\n", v->size, 2 * v->size);
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
    if(p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

int insert(vector *v, int pos, int val) {
    if(pos < 0 || pos > v->count) return 0;
    if (v->size == v->count && !expand(v)) return 0;
    for (int i = v->count - 1; i >= pos; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[pos] = val;
    v->count += 1;
    return 1;
}

int erase(vector *v, int pos) {
    if(pos < 0 || pos >= v->count) return 0;
    for (int i = pos + 1; i < v->count; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->count -= 1;
    return 1;
}

void output_vector(vector *v) {
    int len = 0;
    for (int i = 0; i < v->size; i++ ) {
        len += printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++){
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < v->count; i++) {
        printf("%5d", v->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    #define MAX_OP 20
    vector *v = GetNewVector(2);
    //vector *v = GetNewVector(MAX_OP);
    if(v != NULL) printf("Successfully Get New Vector!\n");
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, pos, val, ret;
        switch (op) {
            case 0:
            case 1:
            case 2:
                pos = rand() % (v->count + 2);
                val = rand() % 100 + 1;
                ret = insert(v, pos, val);
                printf("insert %d at %d to vector = %d\n", val, pos, ret);
                break;
            case 3: 
                pos = rand() % (v->count + 2);
                ret = erase(v, pos);
                printf("delete item at %d in vector = %d\n", pos, ret);
                break;
        }
        output_vector(v);
    }
    if(v == NULL) printf("Successfully Delete Vector!\n");
    else printf("Delete Error!\n");
    return 0;
}
