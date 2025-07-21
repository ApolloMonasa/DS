/*************************************************************************
	> File Name: 22.P1438.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Jul 2025 09:18:06 AM CST
 ************************************************************************/
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

#define N 100005
#define L(i) (tree[i].l)
#define R(i) (tree[i].r)
#define S(i) (tree[i].sum)
#define X(i) (tree[i].x)
#define C(i) (tree[i].cnt)
struct Node {
    int l, r;
    ll sum, x, cnt;
} tree[N * 2];
int n, m, ncnt = 1;
int a[N];

void up(int ind) {
    S(ind) = S(L(ind)) + S(R(ind));
}

void put(int ind) {
    if(X(ind)) {
        X(L(ind)) += X(ind);
        X(R(ind)) += X(ind);
        S(L(ind)) += X(ind) * C(L(ind));
        S(R(ind)) += X(ind) * C(R(ind));
        X(ind) = 0;
    }
}

int build(int ind, int l, int r) {
    X(ind) = 0, C(ind) = (r - l + 1);
    if (l == r) {
        S(ind) = a[l] - a[l - 1];
        return ind;
    }
    int mid = (l + r) >> 1;
    L(ind) = build(++ncnt, l, mid);
    R(ind) = build(++ncnt, mid + 1, r);
    up(ind);
    return ind;
}

ll ask(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return S(ind);
    }
    int mid = (l + r) >> 1;
    ll ans = 0;
    put(ind);
    if (x <= mid) ans += ask(L(ind), l, mid, x, y);
    if(y > mid) ans += ask(R(ind), mid + 1, r, x, y);
    return ans;
}

void mod(int ind, int l, int r, int x, int y, int k) {
    //if(l > r || x > r || y < l) break;
    if (x <= l &&  r <= y) {
        X(ind) += k;
        S(ind) += C(ind) * k;
        return;
    }
    put(ind);
    int mid = (l + r) >> 1;
    if (x <= mid) mod(L(ind), l, mid, x, y, k);
    if (y > mid) mod(R(ind), mid + 1, r, x, y, k);
    up(ind);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    for (int i = 0, op; i < m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            ll l, r, k, d;
            scanf("%lld%lld%lld%lld", &l, &r, &k, &d);
            mod(1, 1, n, l, l, k);
            if (l < r) mod(1, 1, n, l + 1, r, d);
            if (r < n) mod(1, 1, n, r + 1, r + 1, -(k + (r - l) * d));
        } else {
            int p;
            scanf("%d", &p);
            printf("%lld\n", ask(1, 1, n, 1, p));
        }
    }
    return 0;
}
