/*************************************************************************
	> File Name: 12.AC.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 15 Jul 2025 08:19:12 AM CST
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
    int fg;
    Node *next[BASE];
    Node *fail;
    const char *s;
};

Node *getNewNode(int fg) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->fg = fg;
    p->fail = NULL;
    p->s = NULL;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

void insert(Node *rt, const char *s) {
    Node *p = rt;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(0);
        p = p->next[ind];
    }
    p->s = strdup(s);
    p->fg = 1;
}

void build_ac(Node *rt) {
    queue<Node *> q;
    for (int i = 0; i < BASE; i++) {
        if(rt->next[i] == NULL) continue;
        rt->next[i]->fail = rt;
        q.push(rt->next[i]);
    }
    while (!q.empty()) {
        Node *cur = q.front(), *p;
        q.pop();
        for (int i = 0; i < BASE; i++) {
            if (cur->next[i] == NULL) continue;
            p = cur->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            if (!p) p = rt;
            else p = p->next[i];
            cur->next[i]->fail = p;
            q.push(cur->next[i]);
        }
    }
}

void FindAC(Node *rt, const char *s) {
    Node *p = rt, *q;// p is fail
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        while (p && p->next[ind] == NULL) p = p->fail;
        if(!p) p = rt;
        else p = p->next[ind];

        q = p;
        while (q) {
            if (q->fg) {
                int len = strlen(q->s);
                printf("Find[%d, %d] = %s\n", i - len + 1, i, q->s);
            }
            q = q->fail;
        }
    }
}

void clear(Node *rt) {
    if (!rt) return ;
    for (int i = 0; i < BASE; i++) {
        if(rt->next[i]) clear(rt->next[i]);
    }
    free(rt);
}

int main() {
    int n;
    char s[100];
    Node *rt = getNewNode(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(rt, s);
    }
    build_ac(rt);
    scanf("%s", s);
    FindAC(rt, s);

    return 0;
}
