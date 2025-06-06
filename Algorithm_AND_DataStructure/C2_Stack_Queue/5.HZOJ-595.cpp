/*************************************************************************
	> File Name: 5.HZOJ-595.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 12:18:15 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, flag = 0;
    cin >> n;
    vector<string> ops(n), s;
    string target;
    for(int i = 0; i < n; i++) cin >> ops[i];
    cin >> target;
    for(int i = 0; i < n; i++) {
        if(target == ops[i]) {
            flag = 1;
            s.push_back(ops[i]);
            break;
        }
        if(ops[i] == "return") s.pop_back();
        else s.push_back(ops[i]);
    }
    if(flag) {
        for(int i = 0; i < s.size(); i++) {
            if(i) cout << "->";
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << "NOT REFERENCED" << endl;
    }
    return 0;
}
