/*************************************************************************
	> File Name: 3.C.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 01 Mar 2025 08:24:28 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits> 
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, vector<int>> pos; 
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }

    int min_len = INT_MAX; // 初始化为最大值

    for (const auto& entry : pos) {
        const vector<int>& indices = entry.second;
        if (indices.size() >= 2) { 
            for (size_t i = 1; i < indices.size(); ++i) {
                int current_len = indices[i] - indices[i - 1] + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                }
            }
        }
    }

    if (min_len != INT_MAX) {
        cout << min_len << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
