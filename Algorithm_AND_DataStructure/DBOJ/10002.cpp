/*************************************************************************
	> File Name: 10002.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 11:27:03 PM CST
 ************************************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double maxExpectedProfit(double x, double p) {
    // 将概率转换为小数
    p /= 100.0;
    x /= 100.0;

    // 定义最大抓娃娃次数，假设最多抓100次
    const int max_tries = 100;
    double dp[max_tries + 1][2];
    for (int i = 0; i <= max_tries; ++i) {
        dp[i][0] = dp[i][1] = -1e9; // 初始化为负无穷
    }

    // 初始状态：0次抓娃娃，未使用返款机会，收益为0
    dp[0][0] = 0;

    double max_profit = 0;

    for (int i = 0; i < max_tries; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (dp[i][j] < 0) continue; // 无效状态

            // 抓到娃娃
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);

            // 没抓到娃娃
            if (j == 0) {
                // 未使用返款机会，可以选择使用
                double refund = (dp[i][0] - 1) * x; // 返款金额
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] - 1 + refund);
            } else {
                // 已经使用返款机会，直接亏损
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] - 1);
            }

            // 更新最大收益
            max_profit = max(max_profit, dp[i + 1][0]);
            max_profit = max(max_profit, dp[i + 1][1]);
        }
    }

    return max_profit;
}

int main() {
    double x, p;
    cin >> x >> p;
    double result = maxExpectedProfit(x, p);
    cout << fixed << setprecision(1) << result << endl;
    return 0;
}
