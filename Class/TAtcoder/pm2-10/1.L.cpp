/*************************************************************************
	> File Name: 1.L.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 01:45:07 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int main(){
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    sort(strs.begin(),strs.end());
    for(int i = n-1; i >= 0 ; i--) cout << strs[i];
    cout << endl;
    return 0;
}
