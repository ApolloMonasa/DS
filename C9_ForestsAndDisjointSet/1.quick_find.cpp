/*************************************************************************
	> File Name: 1.quick_find.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 20 Apr 2025 09:35:57 PM CST
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

#define MAX_N 10000
int color[MAX_N + 5];

void init(int n) {
    for (int i = 0; i <= n; i++) color[i] = i;
    return ;
}

int find(int a) {
    return color[a];
}

int merge(int a, int b, int n) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return 0;
    
    for (int i = 0; i <= n; i++) {
        if(color[i] == aa) {
            color[i] = bb;
        }
    }
    return 1;
}

void output(int n) {
    int ret  = 0;
    for (int i = 0; i <= n; i++) {
        ret += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0 ; i <= ret; i++) printf("-");
    printf("\n");
    for (int  i = 0; i <= n; i++) {
        printf("%3d", color[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int n;
    cin >> n;
    init(n);
    int a, b;
    while(cin >> a >> b) {
        printf("merge %d with %d : %d\n", a, b, merge(a, b, n));
        output(n);
    }
    return 0;
}
