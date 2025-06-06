/*************************************************************************
	> File Name: 4.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 02:43:47 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Child {
    int g, s, b, index;
    Child(int g, int s, int b, int idx) : g(g), s(s), b(b), index(idx) {}
};

// 比较函数，按照金牌数、银牌数、铜牌数的顺序排序
bool compare_gold(const Child& a, const Child& b) {
    if (a.g != b.g) return a.g > b.g;
    if (a.s != b.s) return a.s > b.s;
    return a.b > b.b;
}

bool compare_silver(const Child& a, const Child& b) {
    if (a.s != b.s) return a.s > b.s;
    if (a.g != b.g) return a.g > b.g;
    return a.b > b.b;
}

bool compare_bronze(const Child& a, const Child& b) {
    if (a.b != b.b) return a.b > b.b;
    if (a.g != b.g) return a.g > b.g;
    return a.s > b.s;
}

int main() {
    int n;
    cin >> n;
    vector<Child> children;

    // 输入每个小朋友的奖牌数
    for (int i = 0; i < n; ++i) {
        int g, s, b;
        cin >> g >> s >> b;
        children.push_back(Child(g, s, b, i));
    }

    // 用于存储每个小朋友的最好排名
    vector<int> bestRank(n);

    // 为每个小朋友计算最好的排名
    for (int i = 0; i < n; ++i) {
        // 复制小朋友数组，分别进行三种排序
        vector<Child> gold_sorted = children;
        vector<Child> silver_sorted = children;
        vector<Child> bronze_sorted = children;

        // 对三种排序进行处理
        sort(gold_sorted.begin(), gold_sorted.end(), compare_gold);
        sort(silver_sorted.begin(), silver_sorted.end(), compare_silver);
        sort(bronze_sorted.begin(), bronze_sorted.end(), compare_bronze);

        // 对每种排序计算排名
        int gold_rank = 1, silver_rank = 1, bronze_rank = 1;

        // 计算金牌排序中的排名
        for (int j = 0; j < n; ++j) {
            if (j > 0 && gold_sorted[j].g == gold_sorted[j - 1].g &&
                gold_sorted[j].s == gold_sorted[j - 1].s && gold_sorted[j].b == gold_sorted[j - 1].b) {
                // 如果当前小朋友和前一个小朋友的奖牌数量相同，他们并列，排名相同
                continue;
            }
            if (gold_sorted[j].index == i) {
                gold_rank = j + 1;
            }
        }

        // 计算银牌排序中的排名
        for (int j = 0; j < n; ++j) {
            if (j > 0 && silver_sorted[j].s == silver_sorted[j - 1].s &&
                silver_sorted[j].g == silver_sorted[j - 1].g && silver_sorted[j].b == silver_sorted[j - 1].b) {
                continue;
            }
            if (silver_sorted[j].index == i) {
                silver_rank = j + 1;
            }
        }

        // 计算铜牌排序中的排名
        for (int j = 0; j < n; ++j) {
            if (j > 0 && bronze_sorted[j].b == bronze_sorted[j - 1].b &&
                bronze_sorted[j].g == bronze_sorted[j - 1].g && bronze_sorted[j].s == bronze_sorted[j - 1].s) {
                continue;
            }
            if (bronze_sorted[j].index == i) {
                bronze_rank = j + 1;
            }
        }

        // 取最好的排名
        bestRank[i] = min({gold_rank, silver_rank, bronze_rank});
    }

    // 输出每个小朋友的最好排名
    for (int i = 0; i < n; ++i) {
        cout << bestRank[i] << endl;
    }

    return 0;
}

