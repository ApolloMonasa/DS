/*************************************************************************
	> File Name: 4.P1443.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 12 Jul 2025 12:24:09 AM CST
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
#define MAXn 400
int dist[MAXn + 5][MAXn + 5];
int n, m, a, b;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void dfs(int step, int x, int y) {
    if(dist[x][y] != -1 && dist[x][y] <= step) return;
    dist[x][y] = step;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        dfs(step + 1, nx, ny);
    }
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> b;
    memset(dist, -1, sizeof(dist));
    dfs(0, a, b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << left << setw(4) << dist[i][j];
        }
        cout << '\n';
    }
    return 0;
}
