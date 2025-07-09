/*************************************************************************
	> File Name: 3.HZOJ-271.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 09 Jul 2025 04:03:07 PM CST
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
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        while(!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i - dq.front() == k) dq.pop_front();
        if(i < k - 1) continue;
        if(i >= k) cout << ' ';
        cout << arr[dq.front()];
    }
    cout << '\n';
    dq.clear();
    for (int i = 0; i < n; i++) {
        while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i - dq.front() == k) dq.pop_front();
        if(i < k - 1) continue;
        if(i >= k) cout << ' ';
        cout << arr[dq.front()];
    }
    cout << '\n';
    return 0;
}
