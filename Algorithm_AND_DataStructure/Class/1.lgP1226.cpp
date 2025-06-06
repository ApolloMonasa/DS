/*************************************************************************
	> File Name: 1.lgP1226.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:45:22 AM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;

long long quick_mul(long long a, long long b, long long p){
    long long ans = 0, temp = a;
    while(b){
        if(b & 1) ans = (ans + temp) % p;
        temp = (temp + temp) % p;
        b >>= 1;
    }
    return ans;
}

long long quick_pow(long long a, long long b, long long p){
    long long ans = 1, temp = a;
    while (b) {
        if(b & 1) ans = ans * temp % p ;
        temp = temp * temp % p;
        b >>= 1;
    }
    return ans;
}

int main(){
    long long a, b, p;
    cin >> a >> b >> p;
    long long ret = quick_pow(a, b, p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p,ret);
    return 0;
}
