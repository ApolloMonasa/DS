/*************************************************************************
	> File Name: 6.HZOJ-372.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 09 Jul 2025 10:52:43 PM CST
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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    deque<int>  aq, bq;
    int p;
    for (p = 0; p < n; p++) {
        while (!aq.empty() && a[aq.back()] > a[p]) aq.pop_back();
        while (!bq.empty() && b[bq.back()] > b[p]) bq.pop_back();
        aq.push_back(p); bq.push_back(p);
        if(aq.size() != bq.size()) break;
    }
    cout << p << endl;;
    return 0;
}
