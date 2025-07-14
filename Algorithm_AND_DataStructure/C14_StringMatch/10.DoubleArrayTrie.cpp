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

struct DATNode {
    int base, check;  
};
#define MAXN 100000
DATNode trie[MAXN + 5];
int rt = 1;

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

int get_base(Node *root, int rt, DATNode *trie) {
    int base = 2;
    do {
        int flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        if (flag == 1) break;
        base++;
    } while (1);
    return base;
}

void convert_to_double_array_trie(Node *root, int rt, DATNode *trie) {
    trie[rt].base = get_base(root, rt, trie);
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        trie[trie[rt].base + i].check = (root->next[i]->flag ? -rt : rt);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        convert_to_double_array_trie(root->next[i], trie[rt].base + i, trie);
    }
}

int find(DATNode *trie, const char *s) {
    int p = rt;
    for (int i = 0; s[i]; i++) {
        int ind = trie[p].base + s[i] - 'a';
        if (abs(trie[ind].check) != p) return 0;
        p = ind;
    }
    return trie[p].check < 0;
}

int main() {
    int n;
    char s[100];
    cin >> n;
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(root, s);
    }
    
    convert_to_double_array_trie(root, rt, trie);
    while (~scanf("%s", s)) {
        printf("Find %s from double array trie : %d\n", s, find(trie, s));
    }
    clear(root);
    return 0;
}
