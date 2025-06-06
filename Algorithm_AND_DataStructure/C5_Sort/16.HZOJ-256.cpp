/*************************************************************************
	> File Name: 16.HZOJ-256.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 18 Mar 2025 05:42:06 PM CST
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
using namespace std;

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {cin >> a[i] >> b[i]; ind[i] = i;}
    sort(ind + 1, ind + n + 1, [&](int i, int j) {
        return a[i] * b[i] < a[j] * b[j];
    });
    int p = a[0], ans = 0;
    for (int i = 1; i <= n; i++) {
        if(p / b[ind[i]] > ans) ans = p / b[ind[i]];
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
