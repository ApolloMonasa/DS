/*************************************************************************
	> File Name: 38.lgP1115.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:42:16 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
int a[200005];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    int pre = 0 , ans = a[1];
    for(int j = 1; j <= n; j++) {
        ans = max(a[j] - pre, ans);
        pre = min(a[j], pre);
    }
    cout << ans << endl;
    return 0;
}
