/*************************************************************************
	> File Name: 15.P3796.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 16 Jul 2025 09:51:02 AM CST
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
int n;

char s[1000006], t[200][100];
int tcnt[200];


#define MAXN 20005
int Next[MAXN][26];
int fail[MAXN];
vector<int> ind[MAXN];
int ncnt = 1;
void insert(const char *s, int k) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int idx = s[i] - 'a';
        if (Next[p][idx] == 0) Next[p][idx] = ++ncnt;
        p = Next[p][idx];
    }
    ind[p].push_back(k);
}

void AC() {
    queue<int> que;
    que.push(1);
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        if (fail[cur]) {
            int p = fail[cur];
            for (int i = 0, I = ind[p].size(); i < I; i++) {
                ind[cur].push_back(ind[p][i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (Next[cur][i] == 0) {
                if (fail[cur] == 0) Next[cur][i] = 1;
                else Next[cur][i] = Next[fail[cur]][i];
                continue;
            }
            int p = fail[cur];
            if (p == 0) p = 1;
            else p = Next[fail[cur]][i];
            fail[Next[cur][i]] = p;
            que.push(Next[cur][i]);
        }
    }
}

void find_all(char *s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int idx = s[i] - 'a';
        p = Next[p][idx];
        for (int i = 0, I = ind[p].size(); i < I; i++) {
            tcnt[ind[p][i]] += 1;
        }
    }
}

void init() {
    ncnt = 1;
    memset(Next, 0, sizeof(Next));
    memset(fail, 0, sizeof(fail));
    memset(tcnt, 0, sizeof(tcnt));
    for (int i = 0; i < MAXN; i++) ind[i].clear();
}

void slv() {
    init();

    for (int i = 0; i < n; i++) {
        scanf("%s", t[i]);
        insert(t[i], i);
    }
    AC();
    scanf("%s", s);
    find_all(s);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < tcnt[i]) ans = tcnt[i];
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        if(tcnt[i] == ans) printf("%s\n", t[i]);
    }
}

int main() {
    while(scanf("%d", &n)) {
        if(n == 0) break;
        slv();
    }
}
