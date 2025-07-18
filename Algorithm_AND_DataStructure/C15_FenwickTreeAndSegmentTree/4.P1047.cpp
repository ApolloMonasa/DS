/*************************************************************************
	> File Name: 4.P1047.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 01:59:00 PM CST
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

int x[10005];

int main() {
    int l, m;
    cin >> l >> m;
    x[0] = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        x[u] -= 1;
        x[v + 1] += 1;
    }
    int a = 0, sum = 0;
    for (int i = 0; i <= l; i++) {
        a += x[i];
        if(a == 1) sum++;
    }
    cout << sum << '\n';
    return 0;
}
