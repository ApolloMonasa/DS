/*************************************************************************
	> File Name: 4.D.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 22 Feb 2025 08:55:25 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> str;

    for (char c : s) {
        if (!str.empty()) {
            if ((c == ')' && str.back() == '(') ||
                (c == ']' && str.back() == '[') ||
                (c == '>' && str.back() == '<')) {
                str.pop_back(); // 匹配成功，弹出栈顶元素
                continue; // 跳过后续逻辑
            }
        }
        // 如果字符是左括号，压入栈中
        if (c == '(' || c == '[' || c == '<') {
            str.push_back(c);
        } else {
            // 如果字符是右括号但无法匹配，直接输出 "No" 并结束程序
            cout << "No\n";
            return 0;
        }
    }

    // 如果栈为空，说明所有括号都匹配成功
    if (str.empty()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
