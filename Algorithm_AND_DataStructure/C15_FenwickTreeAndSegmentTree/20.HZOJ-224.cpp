/*************************************************************************
	> File Name: 20.HZOJ-224.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Jul 2025 07:13:15 AM CST
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
#define L(i) (tree[i].l)
#define R(i) (tree[i].r)
#define S(i) (tree[i].sum)
#define C(i) (tree[i].cnt)
#define X(i) (tree[i].x)
#define Y(i) (tree[i].y)
#define MOD(expr) ((expr) %= p)
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define N 100005
struct Node {
    int l, r;
    ll sum, cnt, x, y;
} tree[N * 2];
int n, m, p, ncnt = 1;
int a[N];

void up(int ind) {
    S(ind) = S(L(ind)) + S(R(ind));
    MOD(S(ind));
}

void putadd(int ind) {
    if (Y(ind) == 0) return ;
    Y(L(ind)) += Y(ind);
    Y(R(ind)) += Y(ind);
    S(L(ind)) += C(L(ind)) * Y(ind);
    S(R(ind)) += C(R(ind)) * Y(ind);

    MOD(Y(L(ind)));
    MOD(Y(R(ind)));
    MOD(S(L(ind)));
    MOD(S(R(ind)));
    Y(ind) = 0;
}

void putmul(int ind) {
    if(X(ind) == 1) return ;
    X(L(ind)) *= X(ind);
    X(R(ind)) *= X(ind);
    Y(L(ind)) *= X(ind);
    Y(R(ind)) *= X(ind);
    S(L(ind)) *= X(ind);
    S(R(ind)) *= X(ind);

    MOD(X(L(ind)));
    MOD(X(R(ind)));
    MOD(Y(L(ind)));
    MOD(Y(R(ind)));
    MOD(S(L(ind)));
    MOD(S(R(ind)));

    X(ind) = 1;
}

void put(int ind) {
    putmul(ind);
    putadd(ind);
}

int build(int ind, int l, int r) {
    tree[ind].x = 1, tree[ind].y = 0;
    tree[ind].cnt = r - l + 1;
    if (l == r) {
        tree[ind].sum = a[l] % p;
        return ind;
    }
    int mid = l + (r - l) / 2;
    tree[ind].l = build(++ncnt, l, mid);
    tree[ind].r = build(++ncnt, mid + 1, r);
    up(ind);
    return ind;
}

void mod(int ind, int l, int r, int x, int y, ll k, int type) {
    if (x <= l && r <= y) {
        if (type == 1) {
            MOD(X(ind) *= k);
            MOD(Y(ind) *= k);
            MOD(S(ind) *= k);
        } else {
            MOD(Y(ind) += k);
            MOD(S(ind) += C(ind) * k);
        }
        return ;
    }
    int mid = l + (r - l) / 2;
    put(ind);
    if (x <= mid) mod(L(ind), l, mid, x, y, k, type);
    if (y > mid) mod(R(ind), mid + 1, r, x, y, k, type);
    up(ind);
}

ll ask(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    put(ind);
    int mid = l + (r - l) / 2;
    ll ans = 0;
    if (x <= mid) MOD(ans += ask(L(ind), l, mid, x, y));
    if (y > mid) MOD(ans += ask(R(ind), mid + 1, r, x, y));
    return ans;
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    ll k;
    for (int i = 1, a, x, y; i <= m; i++) {
        cin >> a >> x >> y;
        if (a == 3) {
            cout << ask(1, 1, n, x, y) << '\n';
        } else {
            cin >> k;
            mod(1, 1, n, x, y, k, a);
        }
    }
    return 0;
}
