/*************************************************************************
	> File Name: 14.HZOJ-248.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 14 Mar 2025 09:02:42 PM CST
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
using namespace std;
#define MAX_N 500000
int arr[MAX_N + 5], temp[MAX_N + 5];

long long merge_sort(int *arr, int l, int r) {
    if(r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long a = merge_sort(arr, l, mid);
    long long b = merge_sort(arr, mid, r);
    long long inter = 0;
    int p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r) {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
            inter += (mid - p1);
        }
    }
    for (int i = l; i < r; i++) arr[i] = temp[i - l];
    return a + b +inter;
}

void solve(int n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
    printf("%lld\n", merge_sort(arr, 0, n));
    return ;
}

int main() {
    int n;
    while(1) {
        cin >> n;
        if(!n) return 0;
        solve(n);
    }
    return 0;
}
