/*************************************************************************
	> File Name: 24.P1470.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 03:48:17 PM CST
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
#define MAXN 200000
int ch[MAXN][26];
int val[MAXN], depth[MAXN];
int ncnt = 1;
int dp[MAXN + 5];//合法起始切分位
void insert(const string &s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'A';
        if (ch[p][ind] == 0) {
            ch[p][ind] = ++ncnt;
            depth[ncnt] = depth[p] + 1;
        }
        p = ch[p][ind];
    }
    val[p]++;
} 

void mark(string &s, int pos) {
    int p = 1;
    for (int i = pos; s[i]; i++) {
        int id = s[i] - 'A';
        p = ch[p][id];
        if(p == 0) break;
        if (val[p]) dp[depth[p] + pos] = 1;
    }
}

int main() {
    string s, t = "";
    while(cin >> s) {
        if(s == ".") break;
        insert(s);
    }
    while(cin >> s) t += s;
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; t[i]; i++) {
        if (dp[i] == 0) continue;
        ans = i;
        mark(t, i);
    }
    if(dp[t.size()]) ans = t.size();
    cout << ans << '\n';
    return 0;
}
