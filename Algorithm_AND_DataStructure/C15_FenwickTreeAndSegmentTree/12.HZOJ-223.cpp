/*************************************************************************
	> File Name: 12.HZOJ-223.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 19 Jul 2025 12:34:51 PM CST
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
//美德被这题骗了，10005过不了
#define N 100005
#define LC(n) (2 * (n))
#define RC(n) (LC(n) + 1)
#define CNT(ind) (ll)(R[ind] - L[ind] + 1)
ll tree[N * 4], add[N * 4], a[N];
int n, m, L[N * 4], R[N * 4];

inline void up(int ind) {
    tree[ind] = tree[LC(ind)] + tree[RC(ind)];
}
//重要操作
inline void putdown(int ind) {
    if(add[ind]) {
        add[LC(ind)] += add[ind];
        add[RC(ind)] += add[ind];
        tree[LC(ind)] += add[ind] * CNT(LC(ind));//值得注意
        tree[RC(ind)] += add[ind] * CNT(RC(ind));
        add[ind] = 0;
    }
}

void build(int ind, int l, int r) {
    if(l > r) return;
    L[ind] = l;
    R[ind] = r;
    add[ind] = 0;
    if (r == l) {
        tree[ind] = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(LC(ind), l, mid);
    build(RC(ind), mid + 1, r);
    up(ind);
}


void mod(int ind, int x, int y, int z) {
    if (x <= L[ind] && R[ind] <= y) {
        add[ind] += z;
        tree[ind] += CNT(ind) * z;
        return ;
    }
    int mid = (R[ind] + L[ind]) / 2;
    putdown(ind);
    if (mid >= x) mod(LC(ind), x, y, z);
    if (y > mid) mod(RC(ind), x, y, z);
    up(ind);
}

ll ask(int ind, int x, int y ) {
    ll ans = 0;
    putdown(ind);
    if (x <= L[ind] && R[ind] <= y) {
       return tree[ind];
    }
    int mid = (L[ind] + R[ind]) / 2;
    if (x <= mid) ans += ask(LC(ind), x, y);
    if (y > mid) ans += ask(RC(ind), x, y);
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 0, a, b, c, d; i < m; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            cin >> d;
            if(b <= c) mod(1, b - 1, c - 1, d);
        } else {
            if(b <= c) cout << ask(1, b - 1, c - 1) << '\n';
            else cout << "0\n";
        }
    }
}
