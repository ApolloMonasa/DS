/*************************************************************************
	> File Name: 1.monotonic_queue.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 09 Jul 2025 01:32:58 PM CST
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


void output(vector<int> &arr) {
    int n = arr.size(), len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, k; cin >> n >> k;
    deque<int> dq;
    vector<int> arr;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    output(arr);

    for (int i = 0; i < n; i++) {
        while(!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i - dq.front() == k) dq.pop_front();

        printf("gmd[%d, %d] = arr[%d] = %d\n", max(i - k + 1, 0), i, dq.front(), arr[dq.front()]);
    }
    return 0;
}
