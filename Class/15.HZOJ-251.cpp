/*************************************************************************
	> File Name: 15.HZOJ-251.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 09:46:58 AM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
using namespace std;

int n;
int x[10005], y[10005];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    sort(y, y + n);
    sort(x, x + n);
    for(int i = 0; i < n; i++) x[i] -= i;
    sort(x, x + n);
    int Y = y[n/2];
    int X = x[n/2];
    for(int i = 0; i < n; i++) {
        ans += abs(x[i] - X) + abs(y[i] - Y);
    }
    cout << ans << endl;

    return 0;
}
