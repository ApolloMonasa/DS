/*************************************************************************
	> File Name: 11.HZOJ-285.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Feb 2025 12:37:35 PM CST
 ************************************************************************/

#include<set>
#include<vector>
#include<iostream>
using namespace std;

typedef pair<int, int> PII;

int main() {
    int n, m, t = 0;
    cin >> n >> m;
    set<PII> s;//big root stack
    s.insert(PII(0, t++));
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (auto x:s) {
            temp.push_back(x.first);
        }
        s.clear();
        for (int j = 0, a; j < m; j++) {
            cin >> a;
            for(auto x : temp) {
                if (s.size() < m ||
                    s.begin()->first < x - a
                ) {
                    s.insert(PII(x - a, t++));
                }
                if (s.size() > m) s.erase(s.begin());
            }
        }
    }
    int flag = 0;
    for (auto iter = s.rbegin(); iter != s.rend();iter++) {
        if(flag) cout << " ";
        cout << -iter->first;
        flag = 1;
    }
    cout << endl;
    return 0;
}
