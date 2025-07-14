/*************************************************************************
	> File Name: 1.brute_force.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 13 Jul 2025 06:38:39 PM CST
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
#include<unordered_map>
using namespace std;


#define MOD 9973
#define BASE 131

int H(string s) {
    int h = 0;
    int n = s.size();
    for (int i = n - 1, kbase = 1; i >= 0; i--) {
        h = (h + s[i] * kbase) % MOD;
        kbase = kbase * BASE % MOD;
    }
    return h;
}

int RK(string &s, vector<string> &t) {
    unordered_map<int, vector<int>> thash;
    for (int i = 0; i < t.size(); i++) thash[H(t[i])].push_back(i);
    int nbase = 1, tlen;
    for (tlen = 0; t[0][tlen];tlen++) nbase = nbase * BASE % MOD;
    for (int i = 0, h = 0; s[i]; i++) {
        h = h * BASE + s[i];
        if (i >= tlen) h = (h - s[i - tlen] * nbase % MOD + MOD) % MOD;
        if(i + 1 < tlen) continue;
        if(thash.find(h) == thash.end()) continue;
        for (int j = 0; j < thash[h].size(); j++) {
            if(strncmp(s.c_str()+i-tlen+1,t[thash[h][j]].c_str(), tlen) == 0) {
                printf("pos %d : %s\n", i - tlen + 1, t[thash[h][j]].c_str());
            }
        }
    }
    return -1;
}

int main() {
    int n;
    string s;
    vector<string> t(100);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    while (cin >> s) {
        RK(s, t);
    }
    return 0;
}
