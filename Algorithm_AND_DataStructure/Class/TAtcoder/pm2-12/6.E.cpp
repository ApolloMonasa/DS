/*************************************************************************
	> File Name: 6.E.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 03:29:07 PM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
using namespace std;

int n, l, r, ans = 0;
long long sum;
int w[40]={0};

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w,w+n,greater<int>());
    for(long long mask = 0; mask <= (1 << n); mask++){
        sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum > r) break;
            if((mask >> i) & 1) sum += w[i];
        }
        if(sum <= r && sum >= l) ans++;
    }
    cout << ans << endl;
    return 0;
}
