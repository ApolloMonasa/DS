/*************************************************************************
	> File Name: 7.I.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 08:01:35 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

const int MAXN = 5005;
const int INF = INT_MAX;

vector<int> adj[MAXN];
vector<int> dist[MAXN];

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    dist[start][start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[start][v] == INF) {
                dist[start][v] = dist[start][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        dist[i].resize(n + 1, INF);
        bfs(i, n);
    }

    int w;
    cin >> w;
    vector<tuple<int, int, int>> stores(w);
    for (int i = 0; i < w; ++i) {
        int c, k, p;
        cin >> c >> k >> p;
        stores[i] = make_tuple(c, k, p);
    }

    int q;
    cin >> q;
    while (q--) {
        int g, r, a;
        cin >> g >> r >> a;

        vector<pair<int, pair<int, int>>> candidates;
        for (auto& store : stores) {
            int c = get<0>(store);
            int k = get<1>(store);
            int p = get<2>(store);
            if (dist[c][g] != INF && p <= a) {
                candidates.push_back({dist[c][g], {k, p}});
            }
        }

        sort(candidates.begin(), candidates.end());

        int low = 0, high = INF;
        int answer = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long total_cost = 0;
            long long total_shovels = 0;
            for (auto& cand : candidates) {
                if (cand.first > mid) break;
                int k = cand.second.first;
                int p = cand.second.second;
                long long available = min((long long)k, (a - total_cost) / p);
                if (available <= 0) continue;
                total_cost += available * p;
                total_shovels += available;
                if (total_shovels >= r) break;
            }
            if (total_shovels >= r && total_cost <= a) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
