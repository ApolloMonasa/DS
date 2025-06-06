/*************************************************************************
	> File Name: 5.lgP1255.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 10:26:54 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stdio.h>
//必须封装大整数了

class BigInt : vector<int> {
public:
    void operator=(int x) {
        push_back(x);
        proccess_digit();
        return ;
    }
    void operator+=(BigInt)
    BigInt operator+(BigInt &a) {
        BigInt ret = (*this);
        ret += a;
        return ret;
    }
}

int N;
BigInt f[5005];

ostream &
int main() {
    cin >> N;
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << end;
    return 0;
}
