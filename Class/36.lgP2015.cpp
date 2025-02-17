/*************************************************************************
	> File Name: 36.lgP2015.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 02:17:58 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int MAXQ = 110;

vector<pair<int, int>> tree[MAXN]; // 邻接表表示树
int dp[MAXN][MAXQ]; // dp[u][k] 表示以u为根的子树中保留k条树枝时的最大苹果数量
int N, Q;

void dfs(int u, int parent) {
    for (auto& edge : tree[u]) {
        int v = edge.first;
        int apple = edge.second;
        if (v == parent) continue;
        dfs(v, u);
        
        // 更新dp[u][k]
        for (int k = Q; k >= 0; --k) {
            for (int j = 0; j <= k - 1; ++j) {
                dp[u][k] = max(dp[u][k], dp[u][k - j - 1] + dp[v][j] + apple);
            }
        }
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i < N; ++i) {
        int u, v, apple;
        cin >> u >> v >> apple;
        tree[u].push_back({v, apple});
        tree[v].push_back({u, apple});
    }
    
    dfs(1, -1);
    
    cout << dp[1][Q] << endl;
    
    return 0;
}
