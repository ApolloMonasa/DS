/*************************************************************************
	> File Name: 2.P1135.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 11 Jul 2025 11:07:49 PM CST
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
#define MAXn 200
int to[MAXn + 5];
int dist[MAXn + 5] = {0};
int n, a, b;

void dfs(int k, int a) {
    if (dist[a] <= k) return;
    dist[a] = k;
    if(a + to[a] <= n) dfs(k + 1, a + to[a]);
    if(a - to[a] >= 1) dfs(k + 1, a - to[a]);
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1 ; i <= n; i++) cin >> to[i];
    for (int i = 1 ; i <= n; i++) dist[i] = n + 1;
    dfs(0, a);
    cout << (dist[b] == n + 1 ? -1 : dist[b]) << endl;
    return 0;
}
