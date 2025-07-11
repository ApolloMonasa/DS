/*************************************************************************
	> File Name: 1.P1219.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 11 Jul 2025 04:04:27 PM CST
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
#include<unordered_map>
using namespace std;
#define MakeMASK(n) ((1 << (n) + 1) - 2)
int n, MUSK;
int anscnt = 3;
int arr[20];
unordered_map<int, int> ind;


void Print() {
    //TODO
    anscnt--;
    for (int i = 1; i <= n; i++) {
        if(i > 1) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
}

int dfs(int i, int t1, int t2, int t3) {
    if(i > n) {
        if(anscnt) Print();
        return 1;
    }
    int ans = 0;
    for (int t= t1; t; t -= -t & t) {
        int j = ind[-t & t];
        //(i, j);
        if((t2 & (1 << i + j - 1)) && (t3 & (1 << i - j + n))) {
            arr[i] = j;
            ans += dfs(i + 1, t1 ^ 1 << j, t2 ^ 1 << i + j - 1, t3 ^ 1 << i - j + n);
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0, I = 2 * n; i < I; i++) ind[1 << i] = i;
    //for example : n = 6, we need "1111110"
    int ans = dfs(1, MakeMASK(n), MakeMASK(2 * n - 1), MakeMASK(2 * n - 1));
    //dfs(i, A, B, C) means i rows settled, A for column, B and C for diag_lines;
    cout << ans << endl;
    return 0;
}
