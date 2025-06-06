/*************************************************************************
	> File Name: 5.HZOJ-636.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 15 Apr 2025 08:16:22 PM CST
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

#define MAX_N 100000
int indeg[MAX_N + 5] = {0};
int ans[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N + 5);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        indeg[y] += 1;
        g[x].push_back(y);
    }
    queue<int> q;
    for (int i = 0; i <= n; i++) {
        if (indeg[i]) continue;
        q.push(i);
        ans[i] = 1;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0, I = g[now].size(); i < I; i++) {
            int t = g[now][i];
            indeg[t] -= 1;
            if (indeg[t] == 0) q.push(t);
            //important
            ans[t] = max(ans[now] + 1, ans[t]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
