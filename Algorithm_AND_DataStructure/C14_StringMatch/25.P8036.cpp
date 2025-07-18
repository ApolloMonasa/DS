/*************************************************************************
	> File Name: 25.P8036.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 04:10:45 PM CST
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
#define MAXN 2000000
int ch[MAXN][62];
int pas[MAXN];
int ncnt = 1;

void init() {
    memset(ch, 0, sizeof(ch));
    for (int i = 0; i < ncnt; i++) {
        pas[i] = 0;
    }
    ncnt = 1;
}

int get(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    else if(c >='a' && c <= 'z') return c - 'a' + 26;
    else return c - '0' + 52;
}

void insert(const string &s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int ind = get(s[i]);
        if (ch[p][ind] == 0) ch[p][ind] = ++ncnt;
        p = ch[p][ind];
        pas[p]++;
    }
}

void query(string &s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int ind = get(s[i]);
        p = ch[p][ind];
        if(p == 0 || pas[p] == 0) break;
    }
    cout << pas[p] << '\n';
}

void slv() {
    int n, q;
    cin >> n >> q;
    string t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        insert(t);
    }
    for (int i = 0; i < q; i++) {
        cin >> t;
        query(t);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) slv();
    return 0;
}
