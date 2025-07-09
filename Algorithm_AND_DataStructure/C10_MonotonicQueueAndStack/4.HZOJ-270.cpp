/*************************************************************************
	> File Name: 4.HZOJ-270.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 09 Jul 2025 04:21:31 PM CST
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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n+1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    deque<int> dq;
    int ans = INT_MIN;
    dq.push_back(0);
    //0 1 -2 3 4 2 5
    for (int i = 1; i <= n; i++) {
        while(!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
        if(i - dq.front() == m + 1) dq.pop_front();
        ans = max(ans, arr[i] - arr[dq.front()]);
        dq.push_back(i);
    }
    cout << ans << endl;
    return 0;
}
