/*************************************************************************
	> File Name: 39.lg379E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:56:20 AM CST
 ************************************************************************/
 #include<iostream>
using namespace std;
#define int long long
int32_t main() {
    int n;
    char s[200005];
    int a[200005];
    cin >> n;
    cin >> (s + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = (s[i] - '0') * i;
        a[i] += a[i - 1];
    }
    for(int i = 1, j = n; i < j; i++, j--) swap(a[i], a[j]);
    int cnt = n;
    for(int i = 1; i <= cnt; i++) {
        if (a[i] < 10) continue;
        if (i == cnt) a[++cnt] = 0;
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    for(int i = cnt; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
