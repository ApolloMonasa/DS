/*************************************************************************
	> File Name: 3.HZOJ-232.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 01:32:49 PM CST
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

int g[5005][5005];

int main() {
    int n, R, W, H;
    cin >> n >> R;
    W = H = R;
    for (int i = 0, x, y, w; i < n; i++) {
        cin >> x >> y >> w;
        g[x + 1][y + 1] = w;
        W = max(x + 1, W);
        H = max(y + 1, H);
    }
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < W - R + 1; i++) {
        for (int j = 0; j < H - R + 1; j++) {
            int k = i + R, l = j + R;
            int val = g[k][l] + g[i][j] - g[i][l] - g[k][j];
            ans = max(ans, val);
        }
    }
    cout << ans << '\n';
    return 0;
}
