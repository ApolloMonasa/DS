/*************************************************************************
	> File Name: 6.lgP1962.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 10:45:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
#define MOD 1000000007
long long n;
int main() {
    cin >> n;
    long long f[n];
    f[1] = 1;
    f[2] = 1;
    for(long long i = 3; i <= n; i++){
        f[i] = (f[i - 1] + f[i - 2]) % MOD; 
    }
    cout << f[n] << endl;
    return 0;
}
