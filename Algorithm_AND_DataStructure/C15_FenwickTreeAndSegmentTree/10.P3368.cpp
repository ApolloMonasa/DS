/*************************************************************************
	> File Name: 10.P3368.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 04:14:56 PM CST
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
    int n, m; cin >> n >> m;
    int pre = 0, cur;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        add(i, cur - pre, n);
        pre = cur;
    }
    int a, b, c, d;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            //[b, c]+d
            add(b, d, n);
            add(c + 1, -d, n);
        } else {
            cin >> b;
            cout << ask(b) << '\n';
        }
    }
    return 0;
}
