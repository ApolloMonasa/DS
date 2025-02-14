/*************************************************************************
	> File Name: 14.HZOJ-266.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 03:19:46 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>

using namespace std;

// 全局变量：当前解析的位置
size_t pos = 0;
int parseExpression(const string& expr);

// 辅助函数：跳过空格
void skipSpaces(const string& expr) {
    while (pos < expr.length() && isspace(expr[pos])) {
        pos++;
    }
}

// 解析数字或括号表达式（基础元素）
int parsePrimary(const string& expr) {
    skipSpaces(expr);

    if (pos >= expr.length()) {
        throw invalid_argument("意外的表达式结尾");
    }

    char c = expr[pos];
    if (isdigit(c)) {
        // 解析整数
        int num = 0;
        while (pos < expr.length() && isdigit(expr[pos])) {
            num = num * 10 + (expr[pos] - '0');
            pos++;
        }
        return num;
    }

    // 处理负号（负数）
    if (c == '-') {
        pos++;  // 跳过负号
        return -parsePrimary(expr);  // 递归解析负数
    }

    // 处理括号：支持 ()、[]、{}
    if (c == '(' || c == '[' || c == '{') {
        char closing;
        switch (c) {
            case '(': closing = ')'; break;
            case '[': closing = ']'; break;
            case '{': closing = '}'; break;
            default: throw invalid_argument("未知的括号");
        }

        pos++;  // 跳过左括号
        int result = parseExpression(expr);  // 递归解析括号内的表达式
        skipSpaces(expr);

        if (pos >= expr.length() || expr[pos] != closing) {
            throw invalid_argument("括号不匹配");
        }
        pos++;  // 跳过右括号
        return result;
    }

    throw invalid_argument("无效的字符: " + string(1, c));
}

// 解析幂运算（右结合）
int parsePower(const string& expr) {
    int left = parsePrimary(expr);
    skipSpaces(expr);

    if (pos < expr.length() && expr[pos] == '^') {
        pos++;  // 跳过 '^'
        int right = parsePower(expr);  // 右结合：递归调用 parsePower
        return pow(left, right);
    }
    return left;
}

// 解析乘、除、取模运算（左结合）
int parseTerm(const string& expr) {
    int result = parsePower(expr);  // 解析左侧的幂运算结果
    skipSpaces(expr);

    while (pos < expr.length()) {
        char op = expr[pos];
        if (op == '*' || op == '/' || op == '%') {
            pos++;  // 跳过操作符
            int next = parsePower(expr);  // 解析右侧的幂运算结果
            switch (op) {
                case '*': result *= next; break;
                case '/':
                    if (next == 0) throw invalid_argument("除零错误");
                    result /= next;
                    break;
                case '%':
                    if (next == 0) throw invalid_argument("模零错误");
                    result %= next;
                    break;
            }
        } else {
            break;
        }
        skipSpaces(expr);
    }
    return result;
}

// 解析加减运算（左结合）
int parseExpression(const string& expr) {
    int result = parseTerm(expr);  // 解析左侧的项
    skipSpaces(expr);

    while (pos < expr.length()) {
        char op = expr[pos];
        if (op == '+' || op == '-') {
            pos++;  // 跳过操作符
            int next = parseTerm(expr);  // 解析右侧的项
            switch (op) {
                case '+': result += next; break;
                case '-': result -= next; break;
            }
        } else {
            break;
        }
        skipSpaces(expr);
    }
    return result;
}

int main() {
    string expression;
    cout << "请输入表达式: ";
    getline(cin, expression);

    try {
        pos = 0;
        int result = parseExpression(expression);
        cout << "表达式的结果是: " << result << endl;
    } catch (const invalid_argument& e) {
        cerr << "错误: " << e.what() << endl;
    }

    return 0;
}

