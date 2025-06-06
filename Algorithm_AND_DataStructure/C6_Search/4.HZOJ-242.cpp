/*************************************************************************
	> File Name: 4.HZOJ-242.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 29 Mar 2025 11:04:22 AM CST
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

#define MAX_N 100000
long long a[MAX_N + 5], b[MAX_N + 5] = {0};

int check(long long *a, int n, int M, int A) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - A;
        b[i] += b[i-1];
    }
    long long pre = 0;
    for (int i = M; i <= n; i++) {
        pre = min(pre, b[i-M]);
        if(b[i]-pre >= 0)  return 1;
    }
    return 0;
    
}

int solve(long long *a, int n, int M, int max_num) {
    int head = -1, tail = max_num + 1, mid;
    while(head + 1 != tail) {
        mid = (head + tail) / 2;
        if (check(a, n, M, mid)) head = mid;
        else tail = mid;
    }
    return head;
}



int main() {
    int n, m, max_num = 0;
    scanf("%d%d", &n, &m);
    for (int  i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        x *= 1000;
        a[i] = x;
        max_num = max(max_num, x);
    }

    printf("%d\n", solve(a, n, m, max_num));

    return 0;
}
