/*************************************************************************
	> File Name: 2.HZOJ-38-2.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 04:53:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long f[105] = {0};

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
