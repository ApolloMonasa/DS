/*************************************************************************
	> File Name: 5.HZOJ-72.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 22 Apr 2025 10:20:49 AM CST
 ************************************************************************/
//Weighted DUS
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

class WeightedUnionSet {
public:
    WeightedUnionSet(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;//跟父节点对战的结果
        }
    }

    int find(int x) {
        if (fa[x] == x) return x;
        int root = find(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 3;
        return fa[x] = root;
    }

    void merge(int a, int b, int t) {
        int aa = find(a), bb = find(b);//t is bond a to b//1 = lose 2 = win
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = ((t - val[a] + val[b]) % 3 + 3) % 3;
        return ;
    }
    vector<int> fa, val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;WeightedUnionSet u(n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            // b win
            u.merge(b, c, 2);
        } else {
            if (u.find(b) != u.find(c)) {
                printf("Unknown\n");
            } else {
                int t = (u.val[b] - u.val[c] + 3) % 3;
                switch (t) {
                    case 0 : {printf("Tie\n");} break;
                    case 1 : {printf("Loss\n");} break;
                    case 2 : {printf("Win\n");} break;
                }
            }
        }
    }
    return 0;
}
