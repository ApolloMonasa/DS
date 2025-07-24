/*
 @Author:      ApolloMonasa
 @Date:        2025-07-24 10:43:24
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

#define N 100005
struct Data {
    int x, y;
};

int cnt[105];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Data> t(m), ma(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ma[i].x, &ma[i].y);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &t[i].x, &t[i].y);
    }
    auto cmp = [](Data &a, Data &b) -> bool {
        return a.x > b.x || a.x == b.x && a.y > b.y;
    };
    sort(ma.begin(), ma.end(), cmp);
    sort(t.begin(), t.end(), cmp);
    ll ans2 = 0, ans1 = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && ma[j].x >= t[i].x) {
            cnt[ma[j].y] += 1;
            j += 1;
        }
        for (int y = t[i].y; y <= 100; y++) {
            if (cnt[y] == 0) continue;
            cnt[y]--;
            ans2 += 500 * t[i].x + 2 * t[i].y;
            ans1++;
            break;
        }
    }
    // cout << ans1 << ' ' << ans2 << '\n';
    printf("%lld %lld\n", ans1, ans2);
}