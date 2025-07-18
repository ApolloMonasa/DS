/*************************************************************************
	> File Name: 26.P2292.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 04:39:43 PM CST
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

#define MAXN 500
int ch[MAXN][26];
int ncnt = 1;
int val[MAXN], dep[MAXN];
int dp[2000000], len;

void insert(string &s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (ch[p][ind] == 0) {
            ch[p][ind] = ++ncnt;
            dep[ncnt] = dep[p] + 1;
        }
        p = ch[p][ind];
    }
    val[p]++;
}

void mark(string &s, int pos) {
    int p = 1;
    for (int i = pos; s[i]; i++) {
        int ind = s[i] - 'a';
        p = ch[p][ind];
        if (p == 0) return;
        if (val[p]) dp[pos + dep[p]] = 1;
    }
}

void query(string &s) {
    for (int i = 0; i <= len; i++)dp[i] = 0;
    int ans = 0, n = 0;
    dp[0] = 1;
    for (; s[n]; n++) {
        if(dp[n] == 0) continue;
        ans = n;
        mark(s, n);
    }
    len = n;
    if(dp[n]) ans = n;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        query(s);
    }
    return 0;
}
