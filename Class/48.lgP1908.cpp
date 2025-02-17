/*************************************************************************
	> File Name: 48.lgP1908.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 03:23:51 PM CST
 ************************************************************************/

#include<map>
#include<iostream>
#include<set>
#define lowbit(x) (x &(-x))
#define int long long
using namespace std;

int c[500005];
void add(int i, int val, int n){
    while(i <= n) {
        c[i] += val;
        i += lowbit(i);
    }
    return ;
}
int query(int i) {
    if(i == 0) return 0;
    return c[i] + query(i - lowbit(i));
}



int n;
int a[500005];
map<int, int> h;
int32_t main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        h[a[i]] = 0;
    }
    int ind = 1;
    for(auto &x: h) {
        x.second = ind;
        ind += 1;
    }
    for(int i = 1; i <= n; i++) a[i] = h[a[i]];//离散化完成，不影响数字的大小关系
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = query(a[i]);
        ans += i - 1 - cnt;
        add(a[i], 1, n);
    }
    cout << ans << endl;
    return 0;
}
