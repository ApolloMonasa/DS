/*************************************************************************
	> File Name: 3.P1036.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 11 Jul 2025 11:48:30 PM CST
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
#define MAXn 20
int val[MAXn + 5];
int n, k;
long long ans = 0;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int k, int ind, int m, int sum) {
    if (k == m) {
        if(is_prime(sum)) ans++;
        return ;
    }
    for (int i = ind; i <= n; i++) {
        dfs(k + 1, i + 1, m, sum + val[i]);
    }
    return ;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i];
    dfs(0, 1, k, 0);
    cout << ans << endl;
}
