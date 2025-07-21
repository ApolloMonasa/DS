/*************************************************************************
	> File Name: 7.P1433.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 12 Jul 2025 07:33:40 AM CST
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
const int N = 21;
int n;
double x[N], y[N];
double dis[N][N];
#define S(i) ((i) * (i))
double __dis(int i, int j) {
    return sqrt(S(x[i] - x[j]) + S(y[i] - y[j]));
}
double dp[70000][20];
double ans = 1e9 + 7;
int ind[70000];
#define MUSK(i) ((1 << i + 1) - 2)

void dfs(int t, int now, double s) {
    if (t == 0) {
        ans = min(ans, s);
        return ;
    }
    for (int k = t; k; k &= k - 1){
        int to = ind[k & -k], next_t = t - (1 << to);
        double l = s + dis[now][to];
        if (dp[next_t][to] != 0 && dp[next_t][to] <= l) continue;
        dp[next_t][to] = l;
        if (ans <= l) continue;
        dfs(next_t, to, l);
    }
    return ;
}

int main() {
    scanf("%d", &n);
    x[0] = y[0] = 0;
    double a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &a, &b);
        x[i] = a;
        y[i] = b;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dis[i][j] = dis[j][i]  = __dis(i, j);
        }
    }
    for (int k = 1, i = 0; i <= 16; i++, k <<= 1) ind[k] = i;
    dfs(MUSK(n), 0, 0);
    printf("%.2lf\n", ans);
    return 0;
}
