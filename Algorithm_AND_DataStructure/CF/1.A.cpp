/*************************************************************************
	> File Name: 37.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 02:29:51 PM CST
 ************************************************************************/

 #include<iostream>
 #include<stdio.h>
 #include<stdlib.h>
using namespace std;
int t;
string str;


int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> str;
        str.erase(str.size() - 2, 2);
        str.push_back('i');
        cout << str << endl;
    }

     return 0;
 }
