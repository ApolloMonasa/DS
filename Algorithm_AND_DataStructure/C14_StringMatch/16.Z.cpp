/*************************************************************************
	> File Name: 16.Z.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 16 Jul 2025 01:12:18 PM CST
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
using namespace std;

string s;
int z[10000];

int main() {
    cin >> s;
    int l, r;
    l = r = -1;
    z[0] = s.size();
    for (int i = 1; s[i]; i++) {
        if (r >= i) z[i] = min(z[i - l], r - l + 1);
        while (z[i] < z[0] && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    for (int i = 0; i < z[0]; i++) {
        cout << z[i] << ' ';
    }
    return 0;
}
