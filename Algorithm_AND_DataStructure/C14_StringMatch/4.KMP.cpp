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

int sunday(const char *s, const char *t) {
    int len[256] = {0}, n = strlen(s), m = strlen(t);
    for (int i = 0; i < 256; i++) len[i] = m + 1;
    for (int i = 0; t[i]; i++) len[t[i]] = m - i;
    for (int i = 0; i + m <= n; i += len[s[i + m]]) {
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

int *getD1(const char *t) {
    int *delta1 = (int *)malloc(sizeof(int) * 256);
    for (int i = 0; i < 256; i++) delta1[i] = -1;//取max所以初始化成-1
    for (int i = 0; t[i]; i++) delta1[t[i]] = i;
    return delta1;
}

int *getSuf(const char *t) {
    int tlen = strlen(t);
    int *suff = (int *)malloc(sizeof(int) * tlen);
    suff[tlen - 1] = tlen;
    for (int i = 0; i < tlen - 1; i++) {
        int j = 0;
        while(j <= i && t[tlen - j - 1] == t[i - j]) j++;
        suff[i] = j;
    }
    return suff;
}

int *getD2(const char *t) {
    int *suff = getSuf(t);
    int tlen = strlen(t), lastInd = tlen - 1;
    int *delta2 = new int[tlen];
    for (int i = 0; t[i]; i++) delta2[i] = tlen;
    //部分匹配
    for (int i = 0; i < tlen; i++) {
        if(suff[i] != i + 1) continue;
        for (int j = 0; j <= lastInd - suff[i]; j++) delta2[j] = lastInd - i;//tlen - 1 - i
    }
    //完全匹配
    for (int i = 0; i < lastInd; i++) {
        delta2[lastInd - suff[i]] = lastInd - i;
    }
    return delta2;

}

int BM(const char *s, const char *t) {
    int *delta1 = getD1(t);
    int *delta2 = getD1(t);
    int slen = strlen(s), tlen = strlen(t);
    for (int j = 0; j + tlen <= slen; ) {
        int i = tlen - 1;
        while (i >= 0 && t[i] == s[j + i]) i--;
        if(i == -1) return j;
        j += max(i - delta1[s[j + i]], delta2[i]);
    }
    return -1;
}

int *getNext(const char *t) {
    int tlen = strlen(t);
    int *next = new int[tlen];
    next[0] = -1;
    int j = -1;
    for (int i = 1; t[i]; i++) {
        while(j != -1 && t[i] != t[j + 1]) j = next[j];
        if (t[i] == t[j + 1]) j += 1;
        next[i] = j;
    }
    return next;
}

int KMP(const char *s, const char *t) {
    int tlen = strlen(t);
    int *next = getNext(t);
    int j = -1;//指向当前匹配区的最后一位
    for (int i = 0; s[i]; i++) {
        while (j != -1 && s[i] != t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j++;
        if (t[j + 1] == 0) return i - tlen + 1;
    }

    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(brute_force, s, t);
        TEST(sunday, s, t);
        TEST(BM, s, t);
        TEST(KMP, s, t);
    }
    return 0;
}
