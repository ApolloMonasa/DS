/*************************************************************************
	> File Name: 8.E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 10:15:55 PM CST
 ************************************************************************/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
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

// 获取一个数的所有因子
set<int> get_factors(int x) {
    set<int> factors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factors.insert(i);
            factors.insert(x / i);
        }
    }
    return factors;
}

// 递归函数，枚举所有组合
void enumerateCombinations(const vector<set<int>>& factor_sets, int n, int k, int index, int start, vector<int>& result, set<int>& current_intersection, int& max_gcd) {
    if (index == k) {
        // 计算当前组合的因子交集
        set<int> intersection = current_intersection;
        for (int i = 0; i < k; i++) {
            set<int> new_intersection;
            set_intersection(
                intersection.begin(), intersection.end(),
                factor_sets[result[i]].begin(), factor_sets[result[i]].end(),
                inserter(new_intersection, new_intersection.begin())
            );
            intersection = new_intersection;
            if (intersection.empty()) break;  // 提前剪枝
        }
        // 更新最大 GCD
        if (!intersection.empty()) {
            int current_gcd = *intersection.rbegin();  // 取最大的因子
            if (current_gcd > max_gcd) {
                max_gcd = current_gcd;
            }
        }
        return;
    }

    for (int i = start; i < n; i++) {
        result[index] = i;  // 记录当前组合
        // 更新当前交集
        set<int> new_intersection;
        if (index == 0) {
            new_intersection = factor_sets[i];
        } else {
            set_intersection(
                current_intersection.begin(), current_intersection.end(),
                factor_sets[i].begin(), factor_sets[i].end(),
                inserter(new_intersection, new_intersection.begin())
            );
        }
        // 提前剪枝
        if (!new_intersection.empty() && (index == 0 || *new_intersection.rbegin() > max_gcd)) {
            enumerateCombinations(factor_sets, n, k, index + 1, i + 1, result, new_intersection, max_gcd);
        }
    }
}

int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 预处理所有数的因子
    vector<set<int>> factor_sets(n);
    for (int i = 0; i < n; i++) {
        factor_sets[i] = get_factors(a[i]);
    }

    // 枚举所有组合
    int max_gcd = 1;
    vector<int> result(k);
    set<int> current_intersection;
    enumerateCombinations(factor_sets, n, k, 0, 0, result, current_intersection, max_gcd);

    cout << max_gcd << endl;

    return 0;
}
