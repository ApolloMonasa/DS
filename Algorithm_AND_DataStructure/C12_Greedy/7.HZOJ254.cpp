/*
 @Author:      ApolloMonasa
 @Date:        2025-07-24 09:17:46
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

#define N 50005
struct Data {
    int l, r, id;
};
int endTime[N];
int ncnt = 0;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int n; cin >> n;
    vector<Data> arr(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].l >> arr[i].r;
        arr[i].id = i;
    }
    sort(arr.begin(), arr.end(), [](Data &a, Data &b) -> bool {
        return a.l < b.l || a.l == b.l && a.id < b.id;
    });
    //debug
    // for (auto x : arr) std::cout << "[" << x.l << ", " << x.r << "]" << std::endl;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < ncnt; j++) {
            if (endTime[j] < arr[i].l) {
                pos = j; 
                break;
            }
        }
        if (pos == -1) pos = ncnt++;    
        endTime[pos] = arr[i].r;

        ans[arr[i].id] = pos + 1;
    }
    cout << ncnt << '\n';
    for (auto &x : ans) cout << x << '\n';
}