/*************************************************************************
	> File Name: 23.lgP1102.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 10:29:29 AM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
using namespace std;

long long n, c, ans = 0;
long long a[200005];

long long f2(long long x) {//查找最后一个
    long long l = 0, r = n, mid;
    while(l < r) {
        mid =(l + r + 1) / 2;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

long long f1(long long x) {//查找第一个x
    long long l = 1, r = n + 1, mid;//r往后+1是为了防止要查找的x位于下标n处
    while(l < r) {
        mid =(l + r) / 2;
        if(a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}
int main() {
    cin >> n >> c;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //遍历每一个数作为A，查找B的范围;B = A - C
    sort(a+1,a+n+1);
    for (long long i = 1; i <= n; i++) {
        long long pos1 = f1(a[i] - c);
        long long pos2 = f2(a[i] - c);
        ans += pos2 - pos1 + 1;
    }
    cout << ans << endl;
    return 0;
}
