/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 19:21:32
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

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // sort(arr.begin(), arr.end(), [&](int i, int j) -> bool {
    //     return arr[i] + arr[j] > arr[j] + arr[i];
    // });
    sort(arr.begin(), arr.end(), [](string a, string b) -> bool {
        return a + b > b + a;
    });
    for (string &s : arr) cout << s;
    cout << '\n';
}