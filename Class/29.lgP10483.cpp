/*************************************************************************
	> File Name: 29.lgP10483.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 10:03:40 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, w, s = 0, ans = 0;
int C[20];
int T = 0;
int main() {
    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> C[i];
    sort(C, C+n, greater<int>());

    for(int i = 0; i < n; i++) {
        s += C[i];
        if(s > ans * w) {
            ans++;
            T = w - C[i];
            if(T >= C[i+1]){
                break;
            }
        }

    }
    cout << ans << endl;
    
    return 0;
}
