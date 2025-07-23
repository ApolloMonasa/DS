/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 15:04:23
 @Description: AtCoder template
 @Mail:        apollomonasa@gmail.com
*/
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
using i128 = __int128;
using u128 = __uint128_t;

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define N 105
int n;
int dir[8][2] = {
    {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
char g[N][N];
int vis[N][N];
int ans[N][N];
char match[8] = "yizhong";
void get_ans(int x, int y) {
    for (int k = 0; k < 8; k++) {
        int fg = 1;
        for (int j = 0; j < 7; j++) { 
            if (match[j] == g[x + j * dir[k][0]][y + j * dir[k][1]]) continue;
            fg = 0;
            break;
        }
        if (fg == 1)  {
            for (int j = 0; j < 7; j++) {
                ans[x + j * dir[k][0]][y + j * dir[k][1]] = match[j];
            }
        }
    }
}

void dfs(int i, int j) {
    if(g[i][j] == '\0') return;
    if(vis[i][j]) return ;
    if (unlikely(g[i][j] == 'y')) {
        get_ans(i, j);
    }
    vis[i][j] = 1;
    dfs(i + 1, j);
    dfs(i, j + 1);
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] + 1;
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 0) cout << "*";
            else cout << g[i][j];
        }
        cout << '\n';
    }
    return 0;
}