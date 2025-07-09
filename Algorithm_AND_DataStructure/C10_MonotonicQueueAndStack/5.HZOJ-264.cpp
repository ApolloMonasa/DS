/*************************************************************************
	> File Name: 5.HZOJ-264.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 09 Jul 2025 07:29:36 PM CST
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

int main() {
    int n; cin >> n;
    vector<int> arr(n + 2, -1), l(n + 2), r(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    for(int i = 0; i <= n; i++) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i = n + 1; i; i--) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int h = arr[i], w = r[i] - l[i] - 1;
        long long v = (long long)h * w;
        ans = max(ans, v);
    }
    cout << ans << endl;
    return 0;
}
