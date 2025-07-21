/*************************************************************************
	> File Name: 16.HZOJ-330.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 19 Jul 2025 06:46:37 PM CST
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
#define N 140005
int n, m;
ll c1[N], c2[N];
inline int lb(int x) {
    return x & -x;
}

void add(ll pos, ll x) {
    ll p = pos;
    while (pos <= n) {
        c1[pos] += x;
        c2[pos] += p * x;
        pos += lb(pos);
    }  
}

ll ask1(int pos) {
    ll ans = 0;
    while (pos) {
        ans += c1[pos];
        pos &= pos - 1;
    }
    return ans;
}
ll ask2(int pos) {
    ll ans = 0;
    while (pos) {
        ans += c2[pos];
        pos &= pos - 1;
    }
    return ans;
}

ll prefix(int p) {
    ll ans = (p + 1) * ask1(p) - ask2(p);
    return ans;
}

ll rang(int a, int b) {return prefix(b) - prefix(a - 1);}

int main() {
    cin >> n >> m;
    ll pre = 0, cur;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        add(i, cur - pre);
        pre = cur;
    }
    char op;
    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if (op == 'C') {
            cin >> c;
            add(a, c);
            add(b + 1, -c);
        } else {
            cout << rang(a, b) << '\n';
        }
    }
    return 0;
}
