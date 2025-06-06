/*************************************************************************
	> File Name: 20.lg376E.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 01:35:25 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<Pair> pairs(N);
        for (int i = 0; i < N; i++) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> pairs[i].second;
        }

        // 按照 A_i 排序
        sort(pairs.begin(), pairs.end());

        // 滑动窗口
        ll minResult = 1LL << 60;
        ll sumB = 0;
        vector<int> window;
        int left = 0;

        for (int right = 0; right < N; right++) {
            sumB += pairs[right].second;
            window.push_back(pairs[right].second);

            if (window.size() > K) {
                sumB -= window[left++];
            }

            if (window.size() == K) {
                ll current = (ll)pairs[right].first * sumB;
                if (current < minResult) {
                    minResult = current;
                }
            }
        }

        cout << minResult << "\n";
    }

    return 0;
}
