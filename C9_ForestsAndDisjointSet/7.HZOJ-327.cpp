/*************************************************************************
	> File Name: 7.HZOJ-327.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 22 Apr 2025 11:59:03 AM CST
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

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;//0-same 1-diff
        }
    }

    int find(int x) {
        if (fa[x] == x) return x;
        int root = find(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }

    void merge(int a, int b, int t) {
        int aa = find(a), bb = find(b);
        if (aa == bb) return ;
        val[aa] = (t - val[a] + val[b] + 2) % 2;
        fa[aa] = bb;
    }
    vector<int> fa, val;
};

struct Data {
    int a, b, c;
};

int main() {
    int n, m;
    scanf("%d%d", &n,&m);
    UnionSet u(n);
    vector<Data> arr(m);
    for (int i = 0; i < m; i++) {
        Data &x = arr[i];
        scanf("%d%d%d", &x.a, &x.b, &x.c);
    }
    sort(arr.begin(), arr.end(), [&](const Data &a, const Data &b){return a.c > b.c;});
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int a = arr[i].a, b = arr[i].b, c = arr[i].c;
        if (u.find(a) == u.find(b)) {
            if ((u.val[a] + u.val[b]) % 2 == 0) {
                ans = c;
                break;
            }
        } else {
            u.merge(a, b, 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
