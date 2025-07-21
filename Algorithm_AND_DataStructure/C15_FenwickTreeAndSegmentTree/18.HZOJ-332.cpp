/*************************************************************************
	> File Name: 18.HZOJ-332.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 20 Jul 2025 05:38:58 PM CST
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
#define N 2000005
int c[N], a[N], b[N], ans[N];
int n;
inline int lb(int x) {return x & -x;}
void add(int i, int v) {
    while (i <= n) c[i] += v, i += lb(i);
}
int ask(int i) {
    int ans = 0;
    while (i) {
        ans += c[i];
        i &= i - 1;
    }
    return ans;
}

int bs(int x) {
    int l = 0, r = n + 1, mid;
    while (l + 1 != r) {
        mid = l + (r - l) / 2;
        if (ask(mid) < x) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }
    for (int i = n; i >= 1; i--) {
        int pos = bs(a[i] + 1);
        ans[pos] = b[i];
        add(pos, -1);
    }
    for (int i = 1; i <= n; i++) {
        if(i >  1) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
