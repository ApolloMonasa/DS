/*************************************************************************
	> File Name: 43.lgP1083.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 11:03:24 AM CST
 ************************************************************************/

#include<iostream>
#define int long long
using namespace std;

struct Data {
    int s, t, d;
};

int n, m;
int a[1000005], x[1000005];
Data order[1000005];

int check(int k) {
    for(int i = 1; i <= n; i++) x[i] = a[i] - a[i - 1];
    for(int i = 1; i <= k; i++) {
        int s = order[i].s, t = order[i].t, d = order[i].d;
        x[s] -= d;
        x[t+1] += d;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += x[i];
        if(s<0)  return 0;
    }
    return 1;
}

int erfen() {
    int l = 1, r = m + 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if(check(mid)) l  = mid + 1;
        else r = mid;
    }
    return l;
}

int32_t main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> order[i].d >> order[i].s >> order[i].t;
    }
    int p = erfen();
    if(p == m + 1) cout << "0" << endl;
    else cout << -1 << endl <<  p << endl;
    return 0;
}
