/*************************************************************************
	> File Name: 15.HZOJ-328.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 19 Jul 2025 04:11:19 PM CST
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
#define lowbit(x) (x & (-x))
int y[200005], l[200005], r[200005], c[200005];
int n;

void init(int n) {
    for (int i = 1; i <= n; i++) c[i] = 0;
}

void add(int i, int v) {
    while(i <= n) c[i] += v, i += lowbit(i);
}
int ask(int i) {
    int sum = 0;
    while(i) sum += c[i], i &= i - 1;
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> y[i];
    for (int i = 1; i <= n; i++) {
        l[i] = ask(y[i]);
        add(y[i], 1);
    }
    init(n);
    for (int i = n; i; i--) {
        r[i] = ask(y[i]);
        add(y[i], 1);
    }
    ll a1 = 0, a2 = 0;
    for (int i = 1; i <= n; i++) {
        ll a = l[i], b = r[i];
        ll c = (i - 1 - a), d = (n - i - b);
        a1 += a * b, a2 += c * d;
    }
    cout << a2 << ' ' << a1 << '\n';
}
