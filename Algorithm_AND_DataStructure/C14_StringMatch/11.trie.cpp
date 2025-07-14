/*************************************************************************
	> File Name: 11.trie.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 14 Jul 2025 09:36:21 PM CST
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
#define MAXN 10000
#define BASE 26
int rt[MAXN + 5] = {0};
int ch[MAXN * 30][BASE] = {0};//length 30
int val[MAXN * 30] = {0};//length 30
int ch_cnt = 0;//used node
void insert(int o, int lst, const char *s) {
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        ch[o][ind] = ++ch_cnt;
        for (int j = 0; j < BASE; j++) {
            if(ch[o][j]) continue;
            ch[o][j] = ch[lst][j];
        }
        o = ch[o][ind];
        lst = ch[lst][ind];
        val[o] = val[lst];
    }
    val[o] += 1;
    return ;
}

int find_once(int a, const char *s) {
    int p = rt[a];
    for (int i = 0; s[i]; i++) {
        p = ch[p][s[i] - 'a'];
    }
    return val[p];
}

int Find(int a, int b, const char *s) {
    int x1 = find_once(b, s);
    int x2 = find_once(a - 1, s);
    return x1 - x2;
}

int main() {
    int n;
    char s[50];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        rt[i] = ++ch_cnt;
        insert(rt[i], rt[i - 1], s);
    }
    int a, b;
    while (~scanf("%d%d%s", &a, &b, s)) {
        printf("From %d to %d : find(%s) = %d\n", a, b, s, Find(a, b, s));
    }
    return 0;
}
