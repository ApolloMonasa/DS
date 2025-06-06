/*************************************************************************
	> File Name: 6.HZOJ-322.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 22 Apr 2025 11:39:00 AM CST
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

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }

    void merge(int a, int b) {
        fa[find(a)] = find(b);
        return ;
    }
    vector<int> fa;
};

struct Data {
    int i, j, e;
};

void solve() {
    int n;
    int cnt = 0;
    scanf("%d", &n);
    vector<Data> arr(n);
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++) {
        Data &x = arr[i];
        scanf("%d%d%d", &x.i, &x.j, &x.e);
        if (h.find(x.i) == h.end()) h[x.i] = cnt++;
        if (h.find(x.j) == h.end()) h[x.j] = cnt++;
    }
    UnionSet u(2 * n);
    for (int i = 0; i < n; i++) {
        if (arr[i].e == 0) continue;
        u.merge(h[arr[i].i], h[arr[i].j]);
    }
    int flag = 1;
    for (int i = 0; i < n && flag; i++) {
        if (arr[i].e == 1) continue;
        if (u.find(h[arr[i].i]) == u.find(h[arr[i].j])) {
            flag = 0;
            break;
        }
    }
    printf("%s\n", flag ? "YES" : "NO");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
