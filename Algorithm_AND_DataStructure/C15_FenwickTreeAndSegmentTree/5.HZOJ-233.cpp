/*************************************************************************
	> File Name: 5.HZOJ-233.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 02:11:32 PM CST
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
    int n, p, h, m;
    set<pair<int, int>> s;
    cin >> n >> p >> h >> m;
    x[1] = h;
    for (int i = 0, A, B; i < m; i++) {
        cin >> A >> B;
        int a = min(A, B);
        int b = max(A, B);
        if(s.count(make_pair(a, b))) continue;
        x[a + 1] -= 1;
        x[b] += 1;
        s.insert({a, b});
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x[i];
        cout << sum << '\n';
    }
    return 0;
}
