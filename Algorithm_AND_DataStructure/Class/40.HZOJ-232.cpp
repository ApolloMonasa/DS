/*************************************************************************
	> File Name: 40.HZOJ-232.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 09:43:14 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int s[5005][5005] = {0};

int VAL(int i, int j, int k, int l) {
    return s[k][l] - s[i-1][l] - s[k][j-1]+s[i-1][j-1];
}

int main() {
    int n ,r;
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x+1][y+1] = w;
    }
    //initial s
    for(int i = 1; i <= 5001; i++) {
        for(int j = 1; j <= 5001; j++) {
            s[i][j] += s[i-1][j] + s[i][j-1] -s[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i = r; i <= 5001;i++) {
        for(int j = r; j <= 5001; j++) {
           ans = max(ans, VAL(i - r+1, j - r+1, i, j));            
        }
    }
    cout << ans << endl;
    return 0;
}
