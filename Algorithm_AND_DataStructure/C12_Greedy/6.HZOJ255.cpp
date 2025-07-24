/*
 @Author:      ApolloMonasa
 @Date:        2025-07-24 08:38:00
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
double d;
struct Edge {
    double l, r;
    Edge(double x, double y) {
        double R = sqrt(d * d - y * y);
        l = x - R, r = x + R;
    }
};

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int n;
    cin >> n >> d;
    std::vector<Edge> e;
    int fg =1;
    for (int i = 0;  i < n; i++) {
        double a, b;
        cin >> a >> b;
        if (b > d) fg = 0;
        e.emplace_back(a, b);
    }
    if(fg == 0) {
        cout << -1 << '\n';
        return 0;
    }
    sort(e.begin(), e.end(), [](Edge &a, Edge &b)->bool {
        return a.r < b.r;
    });
    double pos = -99999999;
    int ans = 0;
    for (auto &[l, r] : e) {
        if (pos < l) ans++, pos = r;
    }
    cout << ans << '\n';


}