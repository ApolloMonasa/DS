/*************************************************************************
	> File Name: 2.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 03:07:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int t;
string str;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> str;
        int cnt = 1;
        int sz = str.size();
        int cp = sz;
        for(int i = 0; i < sz; i++) {
            if(str[i] == str[i+1]) cnt++;
            if(str[i] != str[i+1] && cnt >= 2) {
                cp -= cnt;
                if(cp == 0) cp += 1;
            }
            if(str[i] != str[i+1]) cnt = 1;
        }
        cout << cp << endl;
    }
    return 0;
}
