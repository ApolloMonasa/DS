/*************************************************************************
	> File Name: 1.A.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 22 Feb 2025 07:53:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
char str[105];
int main() {
    cin >> str;
    int len = strlen(str);
    int cnt = 0;
    for(int i = 0; i < len; i++) if(str[i] == '2') cnt++;
    while(cnt--) cout << 2;
    cout << endl;
    return 0;
}
