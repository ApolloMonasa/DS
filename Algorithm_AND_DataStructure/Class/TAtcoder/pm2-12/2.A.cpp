/*************************************************************************
	> File Name: 2.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 01:47:06 PM CST
 ************************************************************************/

#include<vector>
#include<iostream>
using namespace std;

int main() {
    int T, n, m, k, x0, y0, d0, ans;
    cin >> T;
    while (T--) {
        ans = 1;
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        char a[n+5][m+5];
        int vis[n+5][m+5] = {0};
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }

        for(int i = 0; i < k; i++) {
            int x = x0, y = y0;
            vis[x][y] = 1;
            switch(d0) {
                case '0' : y0++;break;
                case '1' : x0++;break;
                case '2' : y0--;break;
                case '3' : x0--;break;
            }
            ans++;
            vis[x0][y0] = 1;
            if(1 <= x0 && x0 <= n && 1 <= y0 && y0 <= m && a[x0][y0] =='.' && vis[x0][y0] == 0) ;
            else {
                vis[x0][y0] = 0;
                ans--;
                x0 = x;
                y0 = y;
                d0 = (d0 + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
