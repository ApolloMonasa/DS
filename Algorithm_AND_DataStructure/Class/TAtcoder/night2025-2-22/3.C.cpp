/*************************************************************************
	> File Name: 3.C.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 22 Feb 2025 08:35:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<string>

int main() {
    string str;
    cin >> str;
    int len = str.size();
    for (int i = 0; i < len - 1; i++) {
        if(str[i] == 'W' && str[i + 1] == 'A') {
            str[i] = 'A';
            str[i + 1] = 'C';
            i -= 2;
        }
    }
    cout << str << endl;
    return 0;
}
