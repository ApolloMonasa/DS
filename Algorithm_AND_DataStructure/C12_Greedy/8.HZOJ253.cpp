/*
 @Author:      ApolloMonasa
 @Date:        2025-07-24 09:46:06
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

#define N 2505
struct Data {
    int a, b;
} Cow[N], Item[N];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int C, L;
    cin >> C >> L;
    for (int i = 0; i < C; i++) {
        cin >> Cow[i].a >> Cow[i].b;
    }
    for (int i = 0; i < L; i++) {
        cin >> Item[i].b >> Item[i].a;
    }
    auto cmp = [](Data &x, Data &y) -> bool {
        return x.b < y.b || x.b == y.b && x.a < y.a;
    };
    sort(Item, Item + L, cmp);
    sort(Cow, Cow + C, cmp);
    ll ans  = 0;
    for (int i = 0; i < C; i++) {
        int fg = 0;
        for (int j  = 0; j < L; j++) {
            if (Item[j].a == 0) continue;
            if (Item[j].b <= Cow[i].b && Item[j].b >= Cow[i].a) {fg = 1, Item[j].a -= 1;break;}
        }
        ans += fg;
    }
    cout << ans << '\n';
}