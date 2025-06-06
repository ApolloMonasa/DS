/*************************************************************************
	> File Name: 2.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 02:20:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

long long find_cubed(long long n){
    long long l = 0, r = 100001, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(mid*mid*mid < n) l = mid + 1;
        else {
            r--;
        }
    }
    if(l*l*l==n) return l;
    return l-1;
}

int main() {
    long long n;
    cin >> n;
    cout << find_cubed(n) << endl;
    return 0;
}
