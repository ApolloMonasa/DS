/*
 @Author:      ApolloMonasa
 @Date:        2025-07-24 19:21:04
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
#define N 1005
int n, r, C[N], fa[N], vis[N], sz[N];
double w[N];
ll ans = 0;

int find_x() {
    int x = -1;
    for (int i = 1; i <= n; i++) {
        if (i == r || vis[i] == 1) continue;
        if (x == -1 || w[x] < w[i]) x = i;
    }
    return x;
}

int find_fa(int x) {
    if (vis[fa[x]]) return find_fa(fa[x]);
    return fa[x];
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> C[i], ans += C[i], fa[i] = i, w[i] = C[i];
        sz[i] = 1;
    }
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        fa[b] = a;
    }
    for (int i = 1; i < n; i++) {
        int x = find_x();
        int fa_x = find_fa(x);
        ans += sz[fa_x] * C[x];
        C[fa_x] += C[x];
        sz[fa_x] += sz[x];
        w[fa_x] = 1.0 * C[fa_x] / sz[fa_x];
        vis[x] = 1;
    }
    cout << ans << '\n';
}