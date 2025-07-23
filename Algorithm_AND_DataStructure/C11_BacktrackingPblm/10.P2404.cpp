/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 14:16:20
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
int ans[20];

void printone(int k) {
    for (int i = 0; i < k; i++) {
        if(i) cout << "+";
        cout << ans[i];
    }
    cout << '\n';
}

void dfs(int k, int x, int n) {
    if(n == 0 && k > 1) {
        printone(k);
        return;
    }
    if(x > n) return;
    for (int i = x; i <= n; i++) {
        ans[k] = i;
        dfs(k + 1, i, n - i);
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int n; cin >> n;
    dfs(0, 1, n);
}