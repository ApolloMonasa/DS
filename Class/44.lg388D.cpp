/*************************************************************************
	> File Name: 44.lg388D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 11:20:28 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n,a[500005], x[500005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = a[i] - a[i-1];
    }
    int s = 0;
    for(int i = 1; i <= n; i++) {
        s += x[i];
        int cnt = min(s, n - i);
        a[i] = s - cnt;
        x[i + 1] += 1;
        x[i + cnt + 1] -= 1;
    }
    for(int i = 1; i <= n; i++) {
        if(i > 1) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
