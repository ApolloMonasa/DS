/*************************************************************************
	> File Name: 13.dynamicSegment.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 19 Jul 2025 02:18:20 PM CST
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
//HZOJ222
#define LC(ind) (tree[ind].lc)
#define RC(ind) (tree[ind].rc)
#define C(ind) (tree[ind].c)
struct Node {
    int c, lc, rc;
} tree[20005];
int ncnt = 1;
int n, m, a[10005];

inline void up(int ind) {
    tree[ind].c = max(C(LC(ind)), C(RC(ind)));
}

inline void put() {

}

void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind].c = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    LC(ind) = ++ncnt;
    RC(ind) = ++ncnt;
    build(LC(ind), l, mid);
    build(RC(ind), mid + 1, r);
    up(ind);
}

void mod(int ind , int l, int r, int x, int y) {
    if (l == r) {
        C(ind) = y;
        return ;
    }
    int mid = (l + r) / 2;
    if (x <= mid) mod(LC(ind), l, mid, x, y);
    else mod(RC(ind), mid + 1, r, x, y);
    up(ind);
}
int ask(int ind , int l, int r, int x, int y) {
    if (x <= l && r <= y) return C(ind);
    int mid = (l + r) / 2;
    int ans = INT_MIN;
    if (x <= mid) ans = max(ans, ask(LC(ind), l, mid, x, y)); 
    if (y > mid) ans = max(ans, ask(RC(ind), mid + 1, r, x, y));
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            if (b <= c) mod(1, 1, n, b, c);
        } else {
            if (b <= c) cout << ask(1, 1, n, b, c) << '\n';
            else cout << "-2147483648\n";
        }
    }
    return 0;
}
