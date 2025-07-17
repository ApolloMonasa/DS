/*************************************************************************
	> File Name: 19.HZOJ-278.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 02:04:59 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<numeric>
using namespace std;

#define MAXN 1000000

void get(const string &s, vector<int> &next) {
    next.resize(s.size());
    for (int i = 1, j = next[0] = -1; s[i]; i++) {
        while (j != -1 && s[i] != s[j + 1]) j = next[j];
        next[i] = j += s[i] == s[j + 1];
    }
}

int main() {
    int L;
    string s;
    vector<int> next;
    cin >> L >> s;
    get(s, next);
    for (int i = 1; s[i]; i++) {
        int n = i + 1, m = n - next[i] - 1;
        if (n > m && n % m == 0) {
            cout << i + 1 << ' ' << n/m << '\n';
        }
    }
    return 0;
}
