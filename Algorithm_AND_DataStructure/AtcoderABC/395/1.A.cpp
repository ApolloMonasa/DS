/*************************************************************************
	> File Name: 1.A.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 01 Mar 2025 08:00:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

int n;
int arr[105];

int main() {
    cin >> n;
    int flag = 1;
    for (int i  = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i  = 0; i < n - 1; i++) {
        if(arr[i] >= arr[i + 1]) {
            flag = 0;
            break;
        }
    }
    if(!flag) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
