/*************************************************************************
	> File Name: 17.HZOJ-331.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 20 Jul 2025 04:38:19 PM CST
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
inline int lb(int x) {return x & -x;}
ll c[80005], a[80005];
int n;
void add(int i, int v) {
    while(i <= n) c[i] += v, i += lb(i);
}
ll ask(int i) {
    ll ans = 0;
    while (i) ans += c[i], i &= i - 1;
    return ans;
}

int bs(int x) {
    int l = 0, r = n + 1, mid;
    while (l + 1 != r) {
        mid = (l + r) / 2;
        if (ask(mid) < x) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    cin >> n;
    a[1] = 0;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }
    for (int i = n; i >= 1; i--) {
        a[i] = bs(a[i] + 1);
        add(a[i], -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
