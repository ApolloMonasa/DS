/*************************************************************************
	> File Name: 34.lgP1131.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 08:09:45 PM CST
 ************************************************************************/

 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

vector<pair<int, int>> graph[MAXN];
int maxDist = 0;
int result = 0;

void dfs(int u, int parent, int currentDist) {
    bool isLeaf = true;
    for (auto& edge : graph[u]) {
        int v = edge.first;
        int t = edge.second;
        if (v != parent) {
            isLeaf = false;
            dfs(v, u, currentDist + t);
        }
    }
    if (isLeaf) {
        maxDist = max(maxDist, currentDist);
    }
}

void calculate(int u, int parent, int currentDist) {
    bool isLeaf = true;
    for (auto& edge : graph[u]) {
        int v = edge.first;
        int t = edge.second;
        if (v != parent) {
            isLeaf = false;
            calculate(v, u, currentDist + t);
        }
    }
    if (isLeaf) {
        result += maxDist - currentDist;
    }
}

int main() {
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N - 1; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].emplace_back(b, t);
        graph[b].emplace_back(a, t);
    }

    dfs(S, -1, 0);
    calculate(S, -1, 0);

    cout << result << endl;

    return 0;
}

