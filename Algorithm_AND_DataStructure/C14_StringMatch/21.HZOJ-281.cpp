/*************************************************************************
	> File Name: 21.HZOJ-281.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 02:38:23 PM CST
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
int ncnt = 1;
int ch[MAXN][26] = {0};
int val[MAXN] = {0};

void insert(string &s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int ind = s[i]- 'a';
        if (ch[p][ind] == 0) ch[p][ind] = ++ncnt;
        p = ch[p][ind];
    }
    val[p]++;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        int ans = 0;
        int p = 1;
        for (int i = 0; s[i]; i++) {
            int ind = s[i] - 'a';
            if (ch[p][ind] == 0) break;
            p = ch[p][ind];
            ans += val[p];
        }
        cout << ans << '\n';
    }
    return 0;
 }
