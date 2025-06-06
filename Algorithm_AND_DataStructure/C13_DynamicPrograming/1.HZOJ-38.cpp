/*************************************************************************
	> File Name: 1.HZOJ-38.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 04:40:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100
long long arr[MAX_N] = {0};
long long f(int n) {
    if(n <= 2) return n;
    if(arr[n]) return arr[n];
    arr[n] = f(n-1) + f(n-2);
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
