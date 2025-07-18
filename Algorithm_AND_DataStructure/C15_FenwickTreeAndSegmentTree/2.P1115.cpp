/*************************************************************************
	> File Name: 2.P1115.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 01:18:09 PM CST
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

int a[200000];

int main() {
    int n; cin >> n;
    int pre = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        pre = min(a[i - 1], pre);
        ans = max(a[i] - pre, ans);
    }
    cout << ans << '\n';
    return 0;
}
