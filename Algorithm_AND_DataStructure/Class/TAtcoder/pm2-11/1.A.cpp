/*************************************************************************
	> File Name: 1.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 01:48:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m;

int find(int*a, int t){
    int l = 1, r = n + 1,mid;
    while(l < r){
        mid = (l + r) / 2;
        if(a[mid] < t) l = mid + 1;
        else r = mid;
    }
    if(a[l] != t) return -1;
    return l;
}

int main() {
    cin >> n >> m;
    int arr[n+2];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        if(i>1) cout << " ";
        cout << find(arr,t);
    }
    cout << endl;
    return 0;
}

