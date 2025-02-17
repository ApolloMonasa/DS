/*************************************************************************
	> File Name: 4.D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:32:31 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#define int long long
using namespace std;
int vis[500000];

int32_t main() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == '1') vis[cnt++] = i;
    }
    if(cnt == 1) cout << 0 << endl;
    else{
        int ans = 0;
        int mid = (cnt - 1) / 2;
        for(int i = 0; i < cnt; i++) {
            ans += abs(vis[mid] - vis[i]);
        }
        int l = mid, r = cnt - l - 1;
        int ds = (1 + l) * l / 2 + (1 + r) * r / 2;
        ans = ans - ds;
        cout << ans << endl;
    }
    return 0;
}
