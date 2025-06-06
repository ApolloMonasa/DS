/*************************************************************************
	> File Name: 5.HZOJ-244.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 29 Mar 2025 12:08:55 PM CST
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
#define MAX_N 500

struct Point {
    int x, y;
} arr[MAX_N + 5];
int tmp[MAX_N + 5];
bool cmp(const Point &a, const Point &b) {
    if(a.x != b.x)return a.x < b.x;
    return a.y < b.y;
}

bool check_y(Point *arr, int n, int c, int b, int e, int l) {
    int cnt = 0;
    for (int i = b; i <= e; i++) {
        tmp[cnt++] = arr[i].y;
    }
    sort(tmp, tmp + cnt);
    for (int i = c - 1; i < cnt; i++) {
        if(tmp[i] - tmp[i - c + 1] < l) return 1;
    }
    return 0;
}

bool check(Point *arr, int n, int C, int L) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (arr[i].x - arr[j].x >= L) j += 1;
        if(i - j + 1 < C) continue;
        if(check_y(arr, n, C, j, i, L)) return 1;
    }
    return 0;
}

int bs(int l, int r, Point *arr, int n, int C) {
    int L;
    while (l != r - 1) {
        L = (l + r) / 2;
        if (check(arr, n, C, L)) r = L;
        else l = L;
    }
    return r;
}


int main() {
    int C, n;
    cin >> C >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    cout << bs(0, 10000, arr, n, C) << endl;
    return 0;
}
