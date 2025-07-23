/*************************************************************************
	> File Name: 24.HZOJ-334.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Jul 2025 10:48:30 AM CST
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
#define N 500005
int n, m, ncnt = 1;
ll a[N], ans;
ll val[N * 2], c[N * 2];
int L[N * 2], R[N * 2], LC[2 * N], RC[2 * N];

void up(int ind) {
    val[ind] = val[LC[ind]] + val[RC[ind]];
    c[ind] = __gcd(c[LC[ind]], c[RC[ind]]);
}

int build(int ind, int l, int r) {
    L[ind] = l, R[ind] = r;
    if(l == r) {
        c[ind] = val[ind] = a[l] - a[l - 1];
        return ind;
    }
    int mid = (l + r) >> 1;
    LC[ind] = build(++ncnt, l, mid);
    RC[ind] = build(++ncnt, mid + 1, r);
    up(ind);
    return ind;
}

void mod(int ind, int l, int r, int x, ll y) {
    if(l == r) {
        val[ind] += y;
        c[ind] += y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) mod(LC[ind], l, mid, x, y);
    else mod(RC[ind], mid + 1, r, x, y);
    up(ind);
}

ll ask(int ind) {
    return 1;
}

ll ask(int ind, int l, int r, int x, int y) {
    if(x <= l && r <= y) {
        return val[ind];
    }
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (x <= mid) ans += ask(LC[ind], l, mid, x, y);
    if (y > mid) ans += ask(RC[ind], mid + 1, r, x, y);
    return ans;
}

void GCD(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        ans = __gcd(ans, c[ind]);
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) GCD(LC[ind], l, mid, x, y);
    if (y > mid) GCD(RC[ind], mid + 1, r, x, y);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        char op[5];
        int l, r;
        ll d;
        scanf("%s%d%d", op, &l, &r);
        if (op[0] == 'C') {
            scanf("%lld", &d);
            mod(1, 1, n, l, d);
            if(r < n) mod(1, 1, n, r + 1, -d);
        } else {
            ans = ask(1, 1, n, 1, l);
            if(l < r) GCD(1, 1, n, l + 1, r);
            printf("%lld\n", abs(ans));
        }
    }
    return 0;
}
