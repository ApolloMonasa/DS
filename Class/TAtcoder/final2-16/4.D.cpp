/*************************************************************************
	> File Name: 4.D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 03:08:26 PM CST
 ************************************************************************/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
const int mod = 1e9 + 7;

int fact[N], inv_fact[N];

// 快速幂计算
int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘和逆阶乘
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[N - 1] = power(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}

// 计算组合数 C(all, in)
int comb(int all, int in) {
    if (in > all) return 0;
    return fact[all] * inv_fact[in] % mod * inv_fact[all - in] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    int min_val = a[k - 1];
    int all = upper_bound(a.begin(), a.end(), min_val, greater<int>()) - lower_bound(a.begin(), a.end(), min_val, greater<int>());
    int in = k - (lower_bound(a.begin(), a.end(), min_val, greater<int>()) - a.begin());

    cout << comb(all, in) << endl;
}

signed main() {
    precompute();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
