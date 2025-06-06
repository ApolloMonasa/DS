/*************************************************************************
	> File Name: 33.lgP2052.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 07:47:46 PM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

struct Edge {
    int to, nxt, c;
} e[2000005];
int head[1000005], cnt = 0;

void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return;
}

int n, sum = 0;
int ns[1000005];

void dfs(int fa, int ind) {
    ns[ind] = 1; // 当前节点自身
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue; // 避免重复访问父节点
        dfs(ind, to); // 递归遍历子节点
        ns[ind] += ns[to]; // 累加子树大小
        sum += c * abs(2 * ns[to] - n); // 累加 sum
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) { // 树有 n-1 条边
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c); // 添加边 a -> b
        add(b, a, c); // 添加边 b -> a（无向图）
    }
    dfs(0, 1); // 从根节点 1 开始遍历
    cout << sum; // 输出结果
    return 0;
}
