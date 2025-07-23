/*************************************************************************
	> File Name: 9.P1032.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Jul 2025 09:29:38 AM CST
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
using ll = long long;
using ull = unsigned long long;
#define N 100

string a, b;
int tcnt = 0, ans = N, ans_k;
string from[10], to[10];
map<string, int> dp;
inline void change(string &changed, int &pos, int &i) {
    changed.erase(pos, from[i].size());
    changed.insert(pos, to[i]);
}

void dfs(string &now, int step) {
    if (step > ans_k) return;
    if (dp.find(now) != dp.end() && dp[now] <= step + 1) return;
    dp[now] = step;
    if (now == b) {
        ans = step;
        return ;
    }
    for (int i = 0; i < tcnt; i++) {
        int pos = -1;
        pos = now.find(from[i]);
        while (pos != -1) {
            string changed = now;
            change(changed, pos, i);
            dfs(changed, step + 1);
            pos = now.find(from[i], pos + 1);
        }
    }
}

int main() {
    cin >> a >> b;
    while (cin >> from[tcnt] >> to[tcnt++]);
    for (int i = 1; i <= 10; i++) {
        ans_k = i;
        dp.clear();
        dfs(a, 0);
        if(ans != N) {
            cout << ans << '\n';
            return 0;
        }
    }
    std::cout << "NO ANSWER!\n";
    return 0;
}
