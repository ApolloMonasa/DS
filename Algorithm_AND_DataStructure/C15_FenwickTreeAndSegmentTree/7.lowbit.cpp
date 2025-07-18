/*************************************************************************
	> File Name: 7.lowbit.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Jul 2025 03:20:44 PM CST
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

//#define lowbit(x) ((x) & (-x))

inline int lowbit(int x) { return x & -x; }

int main() {
    int x;
    cin >> x;
    cout << x  << " = ";
    while(x) {
        cout << lowbit(x);
        x = x & x - 1;
        if (x) cout << " + ";
    }
    cout << '\n';
    return 0;
}
