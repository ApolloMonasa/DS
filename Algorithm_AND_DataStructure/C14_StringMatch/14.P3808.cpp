/*************************************************************************
	> File Name: 14.P3808.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 15 Jul 2025 09:26:30 AM CST
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

#define MAXN 1000000
int node[MAXN + 5][26];
int val[MAXN + 5];
char s[MAXN + 5];
int que[MAXN + 5];
int fail[MAXN + 5];
int ncnt = 1;

void insert(const char *s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (node[p][ind] == 0) node[p][ind] = ++ncnt;
        p = node[p][ind];
    }
    val[p] += 1;
}

void build_ac() {
    int head = 0, tail = 0, p;
    que[tail++] = 1;
    while (head < tail) {
        int cur = que[head++];
        for (int i = 0; i < 26; i++) {
            if (node[cur][i] == 0) {
                if (fail[cur] == 0) node[cur][i] = 1;
                else node[cur][i] = node[fail[cur]][i];
                continue;
            }
            p = fail[cur];
            if (p == 0) p = 1;
            else p = node[fail[cur]][i];
            fail[node[cur][i]] = p;
            que[tail++] = node[cur][i];
        }
    }
}

int find_all(char *s) {
    int ans = 0, p = 1, q;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        p = node[p][ind];

        q = p;
        while (q && val[q] != -1) {
            ans += val[q];
            val[q] = -1;//避免重复统计
            q = fail[q];
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    build_ac();
    scanf("%s", s);
    cout << find_all(s) << endl;

    return 0;
}
