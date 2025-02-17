/*************************************************************************
	> File Name: 3.C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:24:18 PM CST
 ************************************************************************/

#include<set>
#include<iostream>
using namespace std;
#define swap(a, b) {\
    __typeof(a) __c = (a);\
    (a) = (b), (b) = (__c);\
}
typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0,a, b; i < m; i++) {
        cin >> a >> b;
        if(a < b) swap(a, b); 
        if(a != b) s.insert(PII(a,b));
    }
    cout << m-s.size() << endl;
    return 0;
}
