/*************************************************************************
	> File Name: 11.HZOJ-222.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 19 Jul 2025 11:25:42 AM CST
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
#define N 10005
int num[N], n, m;

int tree[N * 4];

inline void update(int ind) {
    tree[ind] = max(tree[ind * 2 + 1], tree[ind * 2 + 2]);
}

void build(int ind, int l, int r) {
    if(l == r) {
        tree[ind] = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(ind * 2 + 1, l, mid);
    build(ind * 2 + 2, mid + 1, r);
    update(ind);
}

void mod(int ind, int l, int r, int x, int y) {
    if(r == l) {
        tree[ind] = y;
        return ;
    } 
    int mid = (l + r) / 2;
    if (mid >= x) mod(ind * 2 + 1, l, mid, x, y);
    else mod(ind * 2 + 2, mid + 1, r, x, y);
    update(ind);
}

int ask(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[ind];
    int mid = (l + r) / 2;
    int ans = INT_MIN;
    if(mid >= x) ans = max(ans, ask(ind * 2 + 1, l, mid, x, y));
    if(mid + 1 <= y) ans = max(ans, ask(ind * 2 + 2, mid + 1, r, x, y));
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    build(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            if (b <= c) mod(0, 0, n - 1, b - 1, c);
        } else {
            if (b > c) cout << "-2147483648\n";
            else cout << ask(0, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}
