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

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if(s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1) return i;
    }
    return -1;
}


int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(brute_force, s, t);
    }
    return 0;
}
