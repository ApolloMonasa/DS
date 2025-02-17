/*************************************************************************
	> File Name: 3.G.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 03:00:35 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1, 0); // 前缀和数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1]; // 计算前缀和
    }

    // 如果总和不能被 3 整除，直接输出 0
    if (a[n] % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long target = a[n] / 3; // 目标值
    long long count = 0; // 满足 a[i] == target 的位置数量
    long long ans = 0; // 最终结果

    // 遍历数组，统计满足条件的三元组
    for (int i = 1; i < n; i++) {
        if (a[i] == 2 * target) {
            ans += count; // 如果 a[i] == 2 * target，累加满足 a[j] == target 的数量
        }
        if (a[i] == target) {
            count++; // 如果 a[i] == target，增加满足条件的位置数量
        }
    }

    cout << ans << endl;
    return 0;
}
