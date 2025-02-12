/*************************************************************************
	> File Name: 7.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 03:27:55 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    int B[N];
    long long G[N];

    // 输入 G 数组
    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }

    // 使用哈希表记录每个元素最后一次出现的位置
    unordered_map<long long, int> lastIndex;
    for (int i = 0; i < N; i++) {
        if (lastIndex.find(G[i]) != lastIndex.end()) {
            B[i] = lastIndex[G[i]] + 1; // 如果之前出现过，记录最后一次出现的位置 + 1
        } else {
            B[i] = -1; // 如果之前没出现过，设为 -1
        }
        lastIndex[G[i]] = i; // 更新当前元素最后一次出现的位置
    }

    // 输出 B 数组
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ' ';
        cout << B[i];
    }

    return 0;
}
