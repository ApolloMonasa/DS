/*************************************************************************
	> File Name: 9.trie.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 14 Jul 2025 06:36:11 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<numeric>
using namespace std;
#define BASE 26
struct Node {
    Node *next[BASE];
    int flag;
};

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE; i++) p->next[i] = NULL;
    p->flag = 0;
    return p;
}

void insert(Node *rt, const char *s) {
    Node *p = rt;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (!p->next[ind]) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
}

int find(Node *rt, const char *s) {
    Node *p = rt;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        p = p->next[ind];
        if (p == NULL) return 0;
    }
    return p->flag;
}


void clear (Node *rt) {
    if(!rt) return ;
    for (int i = 0; i < BASE; i++) clear(rt->next[i]);
    free(rt);
    return ;
}

void output(Node *rt, int k, char *buff) {
    buff[k] = 0;
    if (rt->flag) printf("find : %s\n", buff);
    for (int i = 0; i < BASE; i++) {
        if (!rt->next[i]) continue;
        buff[k] = i + 'a';
        output(rt->next[i], k + 1, buff);
    }
    return ;
}

int main() {
    int op;
    char s[100];
    Node *root = getNewNode();
    do {
        cin >> op;
        if (op == 3) break;
        cin >> s;
        switch (op) {
            case 1: {
                printf("Insert %s to trie\n", s);
                insert(root, s);
            } break;
            case 2: {
                printf("Find %s in trie : %d\n", s, find(root, s));
            } break;
        }
    } while(1);
    printf("按照字典序输出:\n");
    output(root, 0, s);
    clear(root);
    return 0;
}
