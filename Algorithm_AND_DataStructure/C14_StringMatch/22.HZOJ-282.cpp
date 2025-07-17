/*************************************************************************
	> File Name: 22.HZOJ-282.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Jul 2025 02:56:47 PM CST
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
#define MAXN 3100005
int ch[MAXN + 5][2];
int ncnt = 1;

void insert(int x) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int ind = (x >> i) & 1;
        if (ch[p][ind] == 0) ch[p][ind] = ++ncnt;
        p = ch[p][ind];
    }
}

int query(int x) {
    int ans = 0;
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int id = (x >> i) & 1;
        if (ch[p][!id] == 0) p = ch[p][id];
        else {
            p = ch[p][!id];
            ans |= (1 << i);
        }
    }
    return ans;

}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        insert(x);
        ans = max(ans, query(x));
    }
    cout << ans << '\n';
    return 0;
}
