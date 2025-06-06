/*************************************************************************
	> File Name: 4.lgB2064.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 10:19:31 AM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;

int fib(int i){
    if (i == 1 || i == 2) return 1;
    return fib(i - 1) + fib(i - 2);
}

int main() {
    int n, a;
    cin >> n;
    while(~scanf(" %d",&a)){
        int ret = fib(a);
        cout << ret << endl;
    }
    return 0;
}
