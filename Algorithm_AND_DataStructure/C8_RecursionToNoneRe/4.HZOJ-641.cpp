/*************************************************************************
	> File Name: 4.HZOJ-641.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 12 Apr 2025 10:52:25 PM CST
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

#define MAX_N 2000
int indeg[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N + 5);
vector<int> ans;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        indeg[b] += 1;
        g[a].push_back(b);
    }
    set<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.insert(i);
    }
    while(!q.empty()) {
        int now = *q.begin();
        ans.push_back(now);
        q.erase(q.begin());
        for (int i = 0, I = g[now].size(); i < I; i++) {
            int t = g[now][i];
            indeg[t] -= 1;
            if(indeg[t] == 0) {
                q.insert(t);
            } 
        }
    }
    for (int i = 0, I = ans.size(); i < I; i++) {
        if(i) cout << " ";
        cout << ans.at(i);
    }
    return 0;
}
