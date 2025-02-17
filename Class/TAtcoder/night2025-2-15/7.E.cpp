/*************************************************************************
	> File Name: 7.E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 10:03:54 PM CST
 ************************************************************************/

 #include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define int long long

// 计算 GCD
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 获取一个数的所有因数
vector<int> get_factors(int x) {
    vector<int> factors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factors.push_back(i);
            if (i != x / i) {
                factors.push_back(x / i);
            }
        }
    }
    sort(factors.rbegin(), factors.rend());  // 从大到小排序
    return factors;
}

int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 预处理每个数的倍数
    unordered_map<int, int> count;
    for (int x : a) {
        for (int f : get_factors(x)) {
            count[f]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];
        vector<int> factors = get_factors(x);
        int max_gcd = 1;

        // 遍历所有因数，从大到小
        for (int g : factors) {
            // 检查是否有至少 k-1 个数是 g 的倍数（不包括 a[i]）
            int cnt = count[g];
            if (x % g == 0) cnt--;  // 排除 a[i] 本身
            if (cnt >= k - 1) {
                max_gcd = g;
                break;
            }
        }

        cout << max_gcd << endl;
    }

    return 0;
}
