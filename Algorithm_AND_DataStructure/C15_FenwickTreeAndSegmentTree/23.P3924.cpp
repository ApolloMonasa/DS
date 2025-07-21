/*************************************************************************
	> File Name: 23.P3924.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Jul 2025 10:16:49 AM CST
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
using ll = long long;
using ull = unsigned long long;
#define N 1000005
int n, m, qwq, a[N], maxd = 1;
ll ans = 0, s[N];

void build(int l, int r, int k) {
    if(l == r) {
        s[l] = 2 * maxd - maxd / k;
        ans += (ll)a[l] * s[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2);
}

int main() {
    scanf("%d%d%d", &n, &m, &qwq);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    while (maxd <= n) maxd <<= 1;
    build(1, n, 1);
    int k = __gcd(maxd, qwq);
    maxd /= k, qwq /= k;
    for (int i = 2; i <= n; i++) s[i] += s[i - 1];
    for (int i = 1, l, r, x; i <= m; i++) {
        scanf("%d%d%d", &l, &r, &x);
        ans += (ll)(x * (s[r] - s[l - 1]));
        printf("%lld\n", ans / maxd * qwq);
    }
    return 0;
}
