/*************************************************************************
	> File Name: 41.lgP1047.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 10:08:37 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int l, m;
int x[10005];//chafenshuzu

int main() {
    cin >> l >> m;
    x[0] = 1;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        x[a]--;
        x[b+1]++;
    }
    int ans = 0, s = 0;
    for (int i = 0; i <= l; i++) {
        s += x[i];
        if(s==1) ans++;
    }
    cout << ans << endl;
    return 0;
}
