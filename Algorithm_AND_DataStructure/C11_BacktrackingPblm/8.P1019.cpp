/*************************************************************************
	> File Name: 8.P1019.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Jul 2025 08:30:46 PM CST
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
using ll = long long;
using ull = unsigned long long;

#define MAXN 25
string s[MAXN], head;
int d[MAXN][MAXN] = {0};
int n, ans = 0, vis[MAXN];

int f(int i, int j) {
    string &s1 = s[i], &s2 = s[j];
    for (int i = s1.size() - 1; i >= 1; i--) {
        int fg = 1;
        for (int j = 0; j < s1.size() - i; j++) {
            if (s1[i + j] == s2[j]) continue;
            fg = 0;
            break;
        }
        if(fg == 1) return s1.size() - i;
    }
    return 0;
}

void dfs(int x, int L) {
    vis[x]++;
    if (L > ans) ans = L;
    for (int y = 0; y < n; y++) {
        if (d[x][y] == 0) continue;
        if (vis[y] == 2) continue;
        dfs(y, L + s[y].size() - d[x][y]);
    }
    vis[x]--;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> head;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = f(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i][0] != head[0]) continue;
        dfs(i, s[i].size());
    }
    cout << ans << '\n';
    return 0;
}
