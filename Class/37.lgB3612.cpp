/*************************************************************************
	> File Name: 37.lgB3612.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:37:01 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int n, a[100005];
int sum[100005] = {0};

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) sum[i] += a[i]+sum[i-1];
    int m, l, r;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << endl;
    }
    return 0;
}
