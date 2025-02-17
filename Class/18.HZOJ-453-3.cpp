/*************************************************************************
	> File Name: 18.HZOJ-453-3.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 10:22:45 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> uniqueNums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        uniqueNums.insert(num);
    }

    // 判断是否有第 k 个最小整数
    if (k > uniqueNums.size()) {
        cout << "NO RESULT" << endl;
    } else {
        auto it = uniqueNums.begin();
        advance(it, k - 1); // 移动到第 k 个元素
        cout << *it << endl;
    }

    return 0;
}

