/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 21:55:15
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
    ll a, b, k;
    cin >> a >> b >> k;
    if(k == 1) {
        cout << (b - a) << '\n';
        return 0;
    }
    if (k == 0) {
        if (b == 0) cout << !!(a) << '\n';
        else cout << b - a << '\n';
        return 0;
    }
    ll ans = 0;
    while (a * k > 0 && a * k <= b) ans += 1 + b % k, b /= k;
    ans += (b - a);
    cout << ans << '\n';
}