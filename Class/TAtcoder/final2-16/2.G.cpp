/*************************************************************************
	> File Name: 2.G.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 02:55:30 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

int n;
long long a[500000];

// 递归函数，计算满足条件的三元组数量
long long recur(int index, int th, long long target) {
    if (th == 3) {
        return 1; // 找到一个满足条件的三元组
    }
    long long count = 0;
    for (int i = index; i < n; i++) {
        if (a[i] == target * th) {
            count += recur(i + 1, th + 1, target);
        }
    }
    return count;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1]; // 计算前缀和
    }
    
    if (a[n] % 3 != 0) {
        cout << 0 << endl; // 如果总和不能被3整除，直接输出0
        return 0;
    }
    
    long long target = a[n] / 3;
    long long ans = recur(1, 1, target);
    cout << ans << endl;
    
    return 0;
}
