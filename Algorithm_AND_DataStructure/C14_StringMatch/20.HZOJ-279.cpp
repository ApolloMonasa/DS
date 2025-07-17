/*************************************************************************
	> File Name: 20.HZOJ-279.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 02:24:04 PM CST
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
#define MAXN 1000005
char s[MAXN], t[MAXN];


int string_min(char *s) {
    int n = strlen(s), i = 0, j = 1, k = 0;
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) k++;
        else if (s[(i + k) % n] > s[(j + k) % n]) i = (i + k + 1) % n, k = 0;
        else j = (j + k + 1) % n, k = 0;\
        if(i == j) i++;
    }
    return min(i, j);
}

int main() {
    int sm, tm;
    scanf("%s%s", s, t);
    sm = string_min(s);
    tm = string_min(t);
    int n = strlen(s);
    int fg = 1;
    for (int i = 0; i < n; i++) {
        if (s[(sm + i) % n] != t[(tm + i) % n]){
            fg = 0;
            break;
        }
    }
    printf("%s", fg ? "Yes\n" : "No\n");
    if(fg) {
        for (int i = 0; i < n; i++) {
            printf("%c", s[(i + sm) % n]);
        }
        printf("\n");
    }
    return 0;
}
