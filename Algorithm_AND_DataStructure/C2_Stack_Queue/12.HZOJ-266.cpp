/*************************************************************************
	> File Name: 12.HZOJ-266.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 03:13:22 PM CST
 ************************************************************************/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 全局变量：当前解析的位置
size_t pos = 0;
void skipSpaces(const string& expr);
int parseFactor(const string& expr);
int parseTerm(const string& expr);
int parseExpression(const string& expr);
// 辅助函数：跳过空格
void skipSpaces(const string& expr) {
    while (pos < expr.length() && isspace(expr[pos])) {
        pos++;
    }
}

// 解析因子（数字或括号表达式）
int parseFactor(const string& expr) {
    skipSpaces(expr);

    if (expr[pos] == '(') {
        pos++;  // 跳过 '('
        int result = parseExpression(expr);  // 递归解析括号内的表达式
        pos++;  // 跳过 ')'
        return result;
    }

    // 解析数字
    int num = 0;
    while (pos < expr.length() && isdigit(expr[pos])) {
        num = num * 10 + (expr[pos] - '0');
        pos++;
    }
    return num;
}

// 解析项（乘除法）
int parseTerm(const string& expr) {
    int result = parseFactor(expr);  // 解析第一个因子

    while (pos < expr.length()) {
        skipSpaces(expr);

        char op = expr[pos];
        if (op == '*' || op == '/') {
            pos++;  // 跳过操作符
            int nextFactor = parseFactor(expr);  // 解析下一个因子
            if (op == '*') {
                result *= nextFactor;
            } else {
                result /= nextFactor;
            }
        } else {
            break;  // 如果不是乘除法，退出循环
        }
    }

    return result;
}

// 解析表达式（加减法）
int parseExpression(const string& expr) {
    int result = parseTerm(expr);  // 解析第一个项

    while (pos < expr.length()) {
        skipSpaces(expr);

        char op = expr[pos];
        if (op == '+' || op == '-') {
            pos++;  // 跳过操作符
            int nextTerm = parseTerm(expr);  // 解析下一个项
            if (op == '+') {
                result += nextTerm;
            } else {
                result -= nextTerm;
            }
        } else {
            break;  // 如果不是加减法，退出循环
        }
    }

    return result;
}

// 主函数
int main() {
    string expression;
    cout << "请输入表达式: ";
    getline(cin, expression);

    int result = parseExpression(expression);
    cout << "表达式的结果是: " << result << endl;

    return 0;
}

