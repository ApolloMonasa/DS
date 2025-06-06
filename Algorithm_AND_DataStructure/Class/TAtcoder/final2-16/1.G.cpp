/*************************************************************************
	> File Name: 1.G.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 02:05:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, ans = 0, flag = 0;
int a[500000];

void recur(int index,int th, int n, int *a, int target) {
    if(th == 3) {
        if(flag) ans++;
        return;
    }
    for(int i = index; i < n; i++) {
        if(a[i] == target*(th)) {
            if(th == 2) flag = 1;
            recur(i+1, th+1,n,a,target);
        }
    }
    flag = 0;
    return ;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int target = a[n] / 3;
    recur(1,1, n, a, target);
    cout << ans << endl;
    return 0;
}
