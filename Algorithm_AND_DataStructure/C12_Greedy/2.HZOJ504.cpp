/*
 @Author:      ApolloMonasa
 @Date:        2025-07-23 20:21:32
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
char s[250];
int k;
int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);std::cout.tie(nullptr);
    cin >> s >> k;
    for (int i = 0; i < k; i++) {
        int j = 0;
        while (s[j + 1] && s[j + 1] >= s[j]) j++;
        while (s[j]) s[j] = s[j + 1], j++;
    }

    for (int i = 0, fg = 1; s[i]; i++) {
        if (fg && s[i] == '0') continue;
        cout << s[i];
        fg = 0;
    }
    cout << '\n';
}