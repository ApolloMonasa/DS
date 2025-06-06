/*************************************************************************
	> File Name: 1.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 01:44:56 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        set<pair<int, int>> visited;
        visited.insert({x0, y0});
        
        int x = x0, y = y0, d = d0;
        for (int i = 0; i < k; ++i) {
            int nx = x, ny = y;
            if (d == 0) ny++;
            else if (d == 1) nx++;
            else if (d == 2) ny--;
            else if (d == 3) nx--;
            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && grid[nx-1][ny-1] == '.') {
                x = nx;
                y = ny;
                visited.insert({x, y});
            } else {
                d = (d + 1) % 4;
            }
        }
        
        cout << visited.size() << endl;
    }
    return 0;
}
