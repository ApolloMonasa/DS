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
using namespace std;

#define TEST(func, s, t) {\
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t));\
}

#define MOD 9973
#define BASE 131

int H(const char *s) {
    int h = 0;
    int n = strlen(s);
    for (int i = n - 1, kbase = 1; i >= 0; i--) {
        h = (h + s[i] * kbase) % MOD;
        kbase = kbase * BASE % MOD;
    }
    return h;
}

int RK(const char *s, const char *t) {
    int thash = H(t);
    int nbase = 1, tlen;
    for (tlen = 0; t[tlen];tlen++) nbase = nbase * BASE % MOD;
    for (int i = 0, h = 0; s[i]; i++) {
        h = h * BASE + s[i];
        if (i >= tlen) h = (h - s[i - tlen] * nbase % MOD + MOD) % MOD;
        if(i + 1 < tlen) continue;
        if(h != thash) continue;
        if(strncmp(s + i - tlen + 1, t, tlen) == 0) {
            return i - tlen + 1;
        }
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(RK, s, t);
    }
    return 0;
}
