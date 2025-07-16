/*************************************************************************
	> File Name: 17.P5410.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 16 Jul 2025 03:26:03 PM CST
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
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = __uint128_t;
std::vector<ll> getZ(const std::string &s) {
    ll n = s.size(), l = 0, r = 0;
    std::vector<ll> Z(n);
    for (ll i = 1; i < n; i++) {
        if (i <= r) Z[i] = std::min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
    if (n > 0) Z[0] = n;
    return Z;
}
int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    std::string a, b;
    std::cin >> a >> b;
    std::vector<ll> z = getZ(b);
    ll l = -1, r = -1;
    std::vector<ll> p(a.size());
    for (ll i = 0, n = a.size(); i < n; i++) {
        if (i <= r) p[i] = std::min(z[i - l], r - i + 1);
        while (i + p[i] < n && b[p[i]] == a[i + p[i]]) p[i]++;
        if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
    }
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; b[i]; i++) {
        ans1 ^= (i + 1) * (z[i] + 1);
    }
    for (int i = 0; a[i]; i++) {
        ans2 ^= (i + 1) * (p[i] + 1);
    }
    std::cout << ans1 << '\n' << ans2 << '\n';
    
}
