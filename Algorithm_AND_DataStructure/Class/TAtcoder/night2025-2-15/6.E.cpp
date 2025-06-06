/*************************************************************************
	> File Name: 6.E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 09:48:09 PM CST
 ************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void enumerateCombinations(const vector<int>& arr, int k, int index, int start, vector<int>& result, int must, int& max_gcd) {
    if (index == k) {
        int tgcd = must;
        for (int i = 0; i < k; i++) {
            tgcd = gcd(tgcd, result[i]);
            if (tgcd <= max_gcd) break;  // 提前剪枝
        }
        if (tgcd > max_gcd) max_gcd = tgcd;
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        result[index] = arr[i];
        if (gcd(must, result[index]) <= max_gcd) continue;  // 提前剪枝
        enumerateCombinations(arr, k, index + 1, i + 1, result, must, max_gcd);
    }
}

int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        vector<int> b;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            b.push_back(a[j]);
        }

        int max_gcd = 0;
        vector<int> result(k - 1);
        enumerateCombinations(b, k - 1, 0, 0, result, a[i], max_gcd);

        cout << max_gcd << endl;
    }

    return 0;
}
