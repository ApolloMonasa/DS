/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 17:00:24
 @Description: AtCoder template
 @Mail:        apollomonasa@gmail.com
*/
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
using i128 = __int128;
using u128 = __uint128_t;
#define N 25
#define MX 1205
int s[10], sum[10];
int t[10][N];

int slv(int ind) {
    int T = (1 << s[ind]);
    int ans = 1205;
    
    for (int i = 0; i < T; i++) {
        int cnt = 0;
        for (int j = 0; j < s[ind]; j++) {
            if (i >> j & 1) cnt += t[ind][j];
        }
        ans = min(ans, max(cnt, sum[ind] - cnt));
    }

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
            sum[i] += t[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += slv(i);
    }
    cout << ans << '\n';

}