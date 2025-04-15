/*************************************************************************
	> File Name: 1.factorial.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 10 Apr 2025 02:39:42 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;//0
    return n * factorial(n - 1);//1
}

struct Data {
    int n;
    int code, ret, *pre_ret;
    Data(int n, int *pre_ret) : n(n), pre_ret(pre_ret) {
        code = 0;
    }
};

int UNRECUR_f(int n) {
    stack<Data> s;
    int ans;
    Data d(n, &ans);

    s.push(d);
    while (!s.empty()) {
        Data &cur = s.top();
        switch (cur.code) {
            case 0 : {
                if (cur.n <= 1) {
                    *cur.pre_ret = 1;
                    s.pop();
                } else {
                    cur.code = 1;
                }
            } break;
            case 1 : {
                Data d(cur.n-1, &cur.ret);
                cur.code = 2;
                s.push(d);
            } break;
            case 2 : {
                //n * f(n-1)
                *(cur.pre_ret) = cur.ret * cur.n;
                s.pop();
            } break;
        } 
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        cout << factorial(n) << endl;
        cout << UNRECUR_f(n) << endl;
    }
    return 0;
}
