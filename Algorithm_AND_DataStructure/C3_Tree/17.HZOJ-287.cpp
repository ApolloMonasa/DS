/*************************************************************************
	> File Name: 17.HZOJ-287.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 07:09:45 PM CST
 ************************************************************************/

#include<set>
#include<iostream>
using namespace std;

int n;
typedef pair<int, int> PII;

int main() {
    cin >> n;
    set<PII> s;//自动升序排列,并且自动去重
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        s.insert(PII(a,i));
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        ans += a+b;
        s.insert(PII(a+b, n+i));
    }
    cout << ans << endl;
    return 0;
}
