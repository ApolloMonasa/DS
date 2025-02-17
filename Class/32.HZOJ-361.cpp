/*************************************************************************
	> File Name: 32.HZOJ-361.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 07:30:05 PM CST
 ************************************************************************/

 #include <iostream>
#include <vector>
using namespace std;

const int MAXN = 6005;

int n; // 职员数量
int H[MAXN]; // 每个职员的快乐指数
vector<int> children[MAXN]; // 树的邻接表表示
bool hasParent[MAXN]; // 标记节点是否有父节点
int dp[MAXN][2]; // 动态规划数组

// 深度优先搜索，计算 dp[u][0] 和 dp[u][1]
void dfs(int u) {
    dp[u][0] = 0; // 不选择 u
    dp[u][1] = H[u]; // 选择 u

    for (int v : children[u]) {
        dfs(v); // 递归处理子节点
        dp[u][0] += max(dp[v][0], dp[v][1]); // 不选择 u，子节点可选可不选
        dp[u][1] += dp[v][0]; // 选择 u，子节点不能选
    }
}

int main() {
    // 输入
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    // 建树
    for (int i = 1; i < n; i++) {
        int L, K;
        cin >> L >> K;
        children[K].push_back(L); // K 是 L 的直接上司
        hasParent[L] = true; // L 有父节点
    }

    // 找到根节点（没有父节点的节点）
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (!hasParent[i]) {
            root = i;
            break;
        }
    }

    // 动态规划
    dfs(root);

    // 输出结果
    cout << endl << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
