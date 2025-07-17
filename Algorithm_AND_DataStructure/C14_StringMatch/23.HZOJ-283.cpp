/*************************************************************************
	> File Name: 23.HZOJ-283.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 03:09:13 PM CST
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
#define MAXN 100000
int ch[MAXN][10];
int v[MAXN], chc[MAXN];//孩子数量
int ncnt = 1;
bool insert(const string &s) {
    int p = 1, fg = 0;
    for (int i = 0; s[i]; i++) {
        int id = s[i] - '0';
        if (ch[p][id] == 0) {
            ch[p][id] = ++ncnt;
            chc[p]++;
        }
        p = ch[p][id];
        if(v[p]) fg = 1;
    }
    v[p]++;
    if(chc[p]) fg = 1;
    return fg == 0;
}

int main() {
    int n, ans = 1;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ans &= insert(s);
    }
    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}
