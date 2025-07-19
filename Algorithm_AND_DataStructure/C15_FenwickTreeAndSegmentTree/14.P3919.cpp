/*************************************************************************
	> File Name: 14.P3919.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 19 Jul 2025 03:00:01 PM CST
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
#define C(ind) (tree[ind].c)
#define L(ind) (tree[ind].l)
#define R(ind) (tree[ind].r)
#define MAXN 25000005
struct Node {
    int c, l, r;
} tree[MAXN];
int ncnt = 1, rt[1000005];
int n, m;
int a[1000005];

int clone(int ind) {
    tree[++ncnt] = tree[ind];
    return ncnt;
}

int build_tree(int l, int r) {
    int ind = ++ncnt;
    if (l == r) {
        C(ind) = a[l];
        return ind;
    }
    int mid = l + (r - l) / 2;
    L(ind) = build_tree(l, mid);
    R(ind) = build_tree(mid + 1, r);
    return ind;
}

int mod(int ind, int l, int r, int x, int y) {
    ind = clone(ind);
    if (l == r) {
        C(ind) = y;
        return ind;
    }
    int mid = (l + r) / 2;
    if (x <= mid) L(ind) = mod(L(ind), l, mid, x, y);
    else R(ind) = mod(R(ind), mid + 1, r, x , y);
    return ind;
}

void ask(int ind, int l, int r, int x) {
    if (l == r) {
        printf("%d\n", C(ind));
        return ;
    }
    int mid = (l + r)/ 2;
    if (x <= mid) ask(L(ind), l, mid, x);
    else ask(R(ind), mid + 1, r, x);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    rt[0] = build_tree(1, n);
    for (int i = 1, v, a, b, c; i <= m; i++) {
        scanf("%d%d%d", &v, &a, &b);
        if (a == 1) {
            //mod
            scanf("%d", &c);
            rt[i] = mod(rt[v], 1, n, b, c);
        } else {
            rt[i] = rt[v];
            ask(rt[v], 1, n, b);
        }
    }
    return 0;
}
