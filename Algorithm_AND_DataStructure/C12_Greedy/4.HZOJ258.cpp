/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 21:14:33
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
#define N 105
int arr[N][N];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int S = 0;
            for (int k = 1; k <= n; k++) {
                int a = arr[j][k] - arr[i - 1][k];
                if (S >= 0) S += a;
                else S = a;
                ans = max(S, ans);
            }
        }
    }
    cout << ans << '\n';
}