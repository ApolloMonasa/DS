/*************************************************************************
	> File Name: 6.P1605.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 12 Jul 2025 07:05:34 AM CST
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
#define MAXN 5
int g[MAXN + 5][MAXN + 5] = {0};
int n, m, t;
int a, b, c, d;
long long ans = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    if(x == c && y == d) {
        ans++;
        return ;
    }
    g[x][y] = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (g[nx][ny]) dfs(nx, ny);
    }
    g[x][y] = 1;
}

int main() {
    cin >> n >> m >> t >> a >> b >> c >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) g[i][j] = 1;
    }
    for (int i = 0, x, y; i < t; i++) {
        cin >> x >> y;
        g[x][y] = 0;
    }
    dfs(a, b);
    cout << ans << endl;
    return 0;
}
