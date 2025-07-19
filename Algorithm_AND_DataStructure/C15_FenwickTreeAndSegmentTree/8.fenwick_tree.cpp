/*************************************************************************
	> File Name: 8.fenwick_tree.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 03:42:18 PM CST
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

int a[10000];
int c[10000];
inline int lowbit(int x) {return x & -x;}

int ask(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i = i & i - 1;
    }
    return sum;
}

void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }

}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = rand() % 10 + 1;
        add(i, a[i], n);
    }
    int len = 0;
    len += printf("  ");
    for (int i = 1; i <= n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i <= len + 1; i++) printf("=");
    printf("\na:");
    for (int i = 1; i <= n; i++) {
        len += printf("%3d", a[i]);
    }
    printf("\nc:");
    for (int i = 1; i <= n; i++) {
        len += printf("%3d", c[i]);
    }
    printf("\ns:");
    for (int i = 1; i <= n; i++) {
        len += printf("%3d", ask(i));
    }
    printf("\n");
    
    return 0;
}
__attribute__((constructor)) void
init() {
    srand(time(0));
}
