/*************************************************************************
	> File Name: 4.C.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 02:40:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查是否可以通过一次转动从正确密码生成目标状态
bool canGenerate(const vector<int>& correct, const vector<int>& target) {
    int diffCount = 0;
    int diffValue = 0;
    bool isAdjacent = false;

    for (int i = 0; i < 5; ++i) {
        int currentDiff = (target[i] - correct[i] + 10) % 10;
        if (currentDiff != 0) {
            if (diffCount == 0) {
                diffValue = currentDiff;
                diffCount++;
            } else if (diffCount == 1) {
                if (i > 0 && (target[i - 1] - correct[i - 1] + 10) % 10 == currentDiff) {
                    // 两个相邻拨圈转动相同幅度
                    isAdjacent = true;
                    diffCount++;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    // 允许以下情况：
    // 1. 只有一个拨圈转动
    // 2. 两个相邻拨圈转动相同幅度
    return diffCount <= 2;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> states(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> states[i][j];
        }
    }

    int count = 0;
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                for (int d = 0; d < 10; ++d) {
                    for (int e = 0; e < 10; ++e) {
                        vector<int> correct = {a, b, c, d, e};
                        bool valid = true;
                        for (const auto& state : states) {
                            if (!canGenerate(correct, state)) {
                                valid = false;
                                break;
                            }
                        }
                        if (valid) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
