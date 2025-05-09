/*************************************************************************
	> File Name: Pro DSU 按秩优化
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 20 Apr 2025 10:05:46 PM CST
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
int fa[MAX_N + 5];
int size[MAX_N + 5];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    return ;
}

int find(int x) {
    while(fa[x] != x) x = fa[x];
    return x;
}

int merge(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return 0;
    if (size[aa] < size[bb]) {
        fa[aa] = bb;
        size[bb] += size[aa];
    } else {
        fa[bb] = aa;
        size[aa] += size[bb];
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
        printf("%3d", fa[i]);
    }
    printf("\n");
    for (int  i = 0; i <= n; i++) {
        printf("%3d", size[i]);
    }
    printf("\n");
    printf("\n");
    return ;
}


int main() {
    int n, a, b;
    cin >> n;
    init(n);
    while (cin >> a >> b) {
        printf("merge %d with %d : %d\n", a, b, merge(a, b));
        output(n);
    }
    return 0;
}
