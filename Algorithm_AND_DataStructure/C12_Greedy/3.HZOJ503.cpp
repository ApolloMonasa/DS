/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 20:42:13
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

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int w, n; cin >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int p1 = 0, p2 = n - 1;
    int ans = 0;
    while (p1 < p2) {
        if(a[p1] + a[p2] <= w) {
            p1++, p2--, ans++;
        } else {
            p2--, ans++;
        }
    }
    if (p1 == p2) ans++;
    cout << ans << '\n';
}