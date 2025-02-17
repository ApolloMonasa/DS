/*************************************************************************
	> File Name: 5.E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 09:02:16 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;
#define int long long
int gcd(int, int);
int temp = 0;
// 递归函数，用于枚举所有组合
void enumerateCombinations(int arr[], int n, int k, int index, int start, int result[], int must) {
    if (index == k) {
        int tgcd = must;
        for (int i = 0; i < k; i++) {
            tgcd = gcd(tgcd, result[i]);
        }
        if(tgcd > temp) temp = tgcd;
        return;
    }

    for (int i = start; i < n; i++) {
        result[index] = arr[i];  // 将当前元素加入组合
        enumerateCombinations(arr, n, k, index + 1, i + 1, result,must);  // 递归到下一个位置
    }
}

int a[1200005], result[1200005];

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int32_t main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int b[n], c = 0;
        
        // 生成 b 数组，排除 a[i]
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            b[c++] = a[j];  // 应该是 a[j]，而不是 a[i]
        }
        
        // 在每次调用之前，重置 temp
        temp = 0;  
        
        // 枚举所有组合
        enumerateCombinations(b, n - 1, k - 1, 0, 0, result, a[i]);
        
        // 计算并输出最终的 GCD
        int ans = temp;
        cout << ans << endl;
    }

    return 0;
}

