/*************************************************************************
	> File Name: 19.HZOJ-691.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 20 Jul 2025 08:09:39 PM CST
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
#define N 100005
int n;
int a[N];

int main() {
    int n, ans;
    cin >> n;
    cin >> a[1];
    ans = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i - 1]) ans += (a[i] - a[i - 1]);
    }
    cout << ans << '\n';

    return 0;
}
