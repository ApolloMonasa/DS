/*************************************************************************
	> File Name: 42.HZOJ-233.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 10:21:10 AM CST
 ************************************************************************/


#include<set>
#include<iostream>
using namespace std;

set<pair<int, int>> vis;
int n, p, h, m;
int X[10000];
int main() {
    cin >> n >> p >> h >> m;
    X[1] = h;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        if(a>b) swap(a,b);
        //check
        if(vis.find(pair<int,int>(a,b)) != vis.end()) continue;
        X[a + 1] -= 1;
        X[b] += 1;
        vis.insert({a,b});
    }
    for(int i = 1; i <= n; i++) {
        X[i] += X[i-1];
        cout << X[i] << endl;
    }
    return 0;
}
