/*************************************************************************
	> File Name: 25.lgB3629.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 11:03:49 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long n;
//1 2 3 4 5 6 7 买
//1 2 4 5 7 8  吃
long long f(long long x) {
    long long ans = x;
    while(x>=3){
        long long temp = x/3;
        ans += temp;
        x %= 3;
        x += temp;
    }
    return ans;
}
int main() {
    cin >> n;
    long long l = 1, r = 100000000, mid;
    while(1){
        mid = (l + r) / 2;
        if(f(mid)<n) {
            l = mid + 1;
        } else{
            r = mid;
        }
        if(l == r) break;
    }
    cout << l << endl;
    return 0;
}

