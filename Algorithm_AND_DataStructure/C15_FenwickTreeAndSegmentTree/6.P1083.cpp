/*************************************************************************
	> File Name: 6.P1083.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 02:38:22 PM CST
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

struct Data {
    int d, s, t;
    Data() {}
    Data(int d, int s, int t) : d(d), s(s), t(t) {}
} ods[1000005];
int n, m;
int a[1000005];
int x[1000005];
int check(int k) {
    x[1] = a[1];
    for (int i = 2; i <= n; i++) x[i] = a[i] - a[i - 1];
    for (int i = 1; i <= k; i++) {
        int d = ods[i].d, s = ods[i].s, t = ods[i].t;
        x[s] -= d;
        x[t + 1] += d;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x[i];
        if(sum < 0) return 0;
    }
    return 1;
}

int bs() {
    int l = 0, r = m + 1, mid;
    while (l + 1!= r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &ods[i].d, &ods[i].s, &ods[i].t);
    }
    int ind = bs();
    if (ind == m + 1) printf("0\n");
    else {
        printf("-1\n%d\n", ind);
    }
    return 0;
}
