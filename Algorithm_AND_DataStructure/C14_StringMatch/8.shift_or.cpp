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

int shift_or(const char *s, const char *t) {
    int code[256] = {0}, n = 0;
    for (; t[n]; n++) code[t[n]] |= (1 << n);
    for (int i = 0; i < 256; i++) code[i] = ~code[i];
    int p = ~0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1) | code[s[i]];
        if (p & (1 << (n - 1))) continue;
        return i - n + 1;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(shift_or, s, t);
    }
    return 0;
}
