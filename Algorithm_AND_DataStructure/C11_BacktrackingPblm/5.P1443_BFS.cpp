/*************************************************************************
	> File Name: 5.P1443_BFS.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 12 Jul 2025 06:51:47 AM CST
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
#define MAXN 200
int dist[MAXN + 5][MAXN + 5];
int a, b, n, m;
struct COORD {
    int x, y, s;
    COORD(int x, int y, int s) : x(x), y(y), s(s) {}
};

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void bfs(int x, int y) {
    queue<COORD> q;
    q.push(COORD(x, y, 0));
    dist[x][y] = 0;

    while (!q.empty()) {
        COORD now = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m || dist[nx][ny] != -1) continue;
            q.push(COORD(nx, ny, now.s + 1));
            dist[nx][ny] = now.s + 1;
        }
    }
}

int main() {
    cin >> n >> m >> a >> b;
    memset(dist, -1, sizeof(dist));
    bfs(a, b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << left << setw(4) << dist[i][j];
        }
        cout << '\n';
    }
    return 0;
}
