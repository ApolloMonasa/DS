/*************************************************************************
	> File Name: 9.P3374.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 04:04:12 PM CST
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
#define N 500005
int c[N];

inline int lb(int x) {return x & -x;}

void add(int i, int x, int n) {
    while(i <= n) {
        c[i] += x;
        i += lb(i);
    }
}

long long ask(int p) {
    long long s = 0;
    while (p) {
        s += c[p];
        p &= p - 1;
    }
    return s;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        add(i, x, n);
    }
    for (int i = 0, op, l , r; i < m; i++) {
        cin >> op >> l >> r;
        if (op == 1) add(l, r, n);
        else  cout << ask(r) - ask(l - 1) << '\n';
    }
    return 0;
}
