/*************************************************************************
	> File Name: 15.HZOJ-251.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 15 Mar 2025 08:22:02 AM CST
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
using namespace std;

int main() {
   int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int X, Y, costx = 0, costy = 0;
    sort(y.begin(), y.end());
    Y = y[n / 2];
    for (int i = 0; i < n; i++) costy += abs(y[i] - Y);
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) x[i] -= i;
    sort(x.begin(), x.end());
    X = x[n / 2];
    for (int i = 0; i < n; i++) costx += abs(x[i] - X);
    cout << costx + costy << endl;

    return 0;
}
