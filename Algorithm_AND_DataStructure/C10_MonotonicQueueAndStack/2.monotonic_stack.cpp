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
    int n; cin >> n;
    stack<int> s;
    vector<int> arr;
    arr.push_back(-1);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    arr.push_back(-1);
    output(arr);
    
    //求左右两侧离某元素最近的小于的元素
    vector<int> l(arr.size() + 1), r(arr.size() + 1);
    //r
    for (int i = 0, I = arr.size(); i < I; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    //l
    while(!s.empty()) s.pop();
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    //output
    for (int i = 1; i <= n; i++) {
        printf("arr[%d] = %d, right: arr[%d] = %d, left: arr[%d] = %d\n", i, arr[i], r[i], arr[r[i]], l[i], arr[l[i]]);

    }
    return 0;
}
