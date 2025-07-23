/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 16:06:50
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

#define N 25
#define MX 1205
int s[10], ans;
int t[10][N];

void dfs(int k, int x, int l, int r) {
    if (k == s[x]) {
        ans = min(ans, max(l, r));
        return ;
    }
    //TODO
    l += t[x][k];
    dfs(k + 1, x, l, r);
    l -= t[x][k];
    //TODO
    r += t[x][k];
    dfs(k + 1, x, l, r);
    r -= t[x][k];
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
        }
    }
    int total = 0;
    for (int i = 0; i < 4; i++) {
        ans = MX;
        dfs(0, i, 0, 0);
        total += ans;
    }
    cout << total << '\n'; 
}