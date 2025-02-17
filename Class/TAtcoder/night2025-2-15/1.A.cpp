/*************************************************************************
	> File Name: 1.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:08:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    string S1, S2;
    cin >> S1 >> S2;
    if(S1 == "fine" && S2 == "fine") cout << 4 << endl;
    if(S1 != "fine" && S2 != "fine") cout << 1 << endl;
    if(S1 == "fine" && S2 != "fine") cout << 3 << endl;
    if(S1 != "fine" && S2 == "fine") cout << 2 << endl;
    return 0;
}
