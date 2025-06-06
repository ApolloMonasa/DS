/*************************************************************************
	> File Name: 2.LinkedList.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 07:45:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DL 3
#define STR(n) #n
#define DIGIT_LEN_STR(n) "%" STR(n) "d"

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *GetNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    if(p == NULL) return NULL;
    p->data = val;
    p->next = NULL;
    return p;
}

Node *insert(Node *head, int pos, int val) {
    Node new_head, *p = &new_head, *node = GetNewNode(val);
    new_head.next = head;
    //有个虚拟头之后pos是几，就向后走几步，把两种情况合并了
    for (int i = 0; i < pos; i++) p = p->next;
    node->next = p->next;
    p->next = node;
    return new_head.next;
}

void clear(Node *head) {
    if(head == NULL) return ;
    for (Node *p = head, *q; p; p = q) {
        q = p->next;
        free(p);
    }
}

void output_linkedlist(Node *head, int flag) {
    int n = 0;
    for(Node *p = head; p; p = p->next) n++;
    for(int i = 0; i < n; i++) {
        printf(DIGIT_LEN_STR(DL), i);
        printf("  ");
    }
    printf("\n");
    for(Node *p = head; p; p = p->next) {
        printf(DIGIT_LEN_STR(DL), p->data);
        printf("->");
    }
    printf("\n");
    if (!flag) printf("\n\n");
    return ;
}

int find(Node *head, int val) {
    Node *p = head;
    int n = 0;
    while (p) {
        if(p->data == val) {
            output_linkedlist(head, 1);
            int spase_len = n * (DL + 2) + 2;
            for (int i =0; i < spase_len; i++) printf(" ");
            printf("^\n");
            for(int i = 0; i < spase_len; i++) printf(" ");
            printf("|\n");
            return 1;
        }
        n++;
        p = p->next;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    #define MAX_OP 7
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = (rand() % (i + 1)), val = rand() % 100;
        printf("Insert %d at %d to linkedlist!\n", val, pos);
        head = insert(head, pos, val);
        output_linkedlist(head, 1);
    }
    int val;
    printf("Input What You want to find:");
    while(~scanf("%d", &val)) {
    if (!find(head, val)) {
        printf("Not found!\n");
        }
    }
    clear(head);
    return 0;
}
