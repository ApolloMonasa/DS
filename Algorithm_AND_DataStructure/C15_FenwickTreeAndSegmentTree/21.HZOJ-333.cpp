/*************************************************************************
	> File Name: 21.HZOJ-333.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Jul 2025 08:28:12 AM CST
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
#define L(i) (tree[i].l)
#define R(i) (tree[i].r)
#define S(i) (tree[i].sum)
#define M(i) (tree[i].m)
#define LM(i) (tree[i].lm)
#define RM(i) (tree[i].rm)
#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}
int n, m, ncnt = 2, t1 = 0, t2 = 1, fg = 0;
int a[N];
struct Node {
    int l, r;
    ll sum, m, lm, rm;
} tree[N * 2];

void up(int a, int b, int c) {
    S(a) = S(b) + S(c);
    LM(a) = max(LM(b), S(b) + LM(c));
    RM(a) = max(RM(c), S(c) + RM(b));

    M(a) = max(M(b), M(c));
    M(a) = max(M(a), RM(b) + LM(c));
    return;
}

int build(int ind, int l, int r) {
    if (l == r) {
        S(ind) = M(ind) = LM(ind) = RM(ind) = a[l];
        return ind;
    }
    int mid = (l + r) >> 1;
    L(ind) = build(++ncnt, l, mid);
    R(ind) = build(++ncnt, mid + 1, r);
    up(ind, L(ind), R(ind));
    return ind;
}

void mod(int ind, int l, int r, int x, int y) {
    if(l == r) {
        S(ind) = M(ind) = LM(ind) = RM(ind) = y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) mod(L(ind), l, mid, x, y);
    else mod(R(ind), mid + 1, r, x, y);
    up(ind, L(ind), R(ind));
}

void ask(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        if(fg) tree[t2] = tree[ind], fg = 0;
        else {
            up(t1, t2, ind);
            swap(t1, t2);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) ask(L(ind), l, mid, x, y);
    if (y > mid) ask(R(ind), mid + 1, r, x, y);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(2, 1, n);
    for (int i = 0, k, x, y; i < m; i++) {
        scanf("%d%d%d", &k, &x, &y);
        if(k == 1) {
            if(x > y) swap(x, y);
            fg = 1;
            ask(2, 1, n, x, y);
            printf("%lld\n", M(t2));
        } else {
            mod(2, 1, n, x, y);
        }
    }
    return 0;
}
