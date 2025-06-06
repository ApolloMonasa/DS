/*************************************************************************
	> File Name: 35.lgP1131.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 08:11:00 PM CST
 ************************************************************************/

 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

struct Edge {
    int to, c, nxt;
} e[1000005];
int head[500005], cnt = 0;

void add(int a, int b, int c) {
    e[++cnt] = {b, c, head[a]};
    head[a] = cnt;
}

int n, s;
int t[500005], dp[500005];

void getDP(int fa, int ind) {
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue;
        getDP(ind, to);
        t[ind] = max(t[ind], t[to] + c);
    }
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue;
        dp[ind] += t[ind] - (t[to] + c) + dp[to];
    }
}

int32_t main() {
    cin >> n >> s;
    for (int i = 0, a, b, t; i < n - 1; i++) {
        cin >> a >> b >> t;
        add(a, b, t);
        add(b, a, t);
    }

    getDP(-1, s); // 从激发器开始 DFS
    cout << dp[s] << endl; // 输出需要使用的道具次数

    return 0;
}
