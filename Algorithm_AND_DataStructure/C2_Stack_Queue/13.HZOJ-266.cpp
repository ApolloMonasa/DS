/*************************************************************************
	> File Name: 13.HZOJ-266.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 03:16:57 PM CST
 ************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <memory>

using namespace std;

void skipSpaces(const string& expr, int& pos);
// 表达式树的节点结构
struct TreeNode {
    string value;  // 节点值（操作数或操作符）
    shared_ptr<TreeNode> left;  // 左子节点
    shared_ptr<TreeNode> right; // 右子节点

    TreeNode(const string& val) : value(val), left(nullptr), right(nullptr) {}
};

// 判断是否为操作符
bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// 构建表达式树
shared_ptr<TreeNode> buildExpressionTree(const string& expr, int& pos) {
    skipSpaces(expr, pos);

    if (expr[pos] == '(') {
        pos++;  // 跳过 '('
        auto node = buildExpressionTree(expr, pos);  // 递归构建子树
        pos++;  // 跳过 ')'
        return node;
    }

    // 解析数字
    string num;
    while (pos < expr.length() && (isdigit(expr[pos]) || expr[pos] == '-')) {
        num += expr[pos];
        pos++;
    }

    auto node = make_shared<TreeNode>(num);  // 创建操作数节点
    skipSpaces(expr, pos);

    // 如果后面是操作符，继续构建右子树
    if (pos < expr.length() && isOperator(string(1, expr[pos]))) {
        string op(1, expr[pos]);
        pos++;
        auto opNode = make_shared<TreeNode>(op);  // 创建操作符节点
        opNode->left = node;
        opNode->right = buildExpressionTree(expr, pos);
        return opNode;
    }

    return node;
}

// 计算表达式树的值
int evaluateExpressionTree(const shared_ptr<TreeNode>& root) {
    if (!root) return 0;

    // 如果是操作数，直接返回其值
    if (!isOperator(root->value)) {
        return stoi(root->value);
    }

    // 递归计算左右子树
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // 根据操作符计算结果
    if (root->value == "+") return leftValue + rightValue;
    if (root->value == "-") return leftValue - rightValue;
    if (root->value == "*") return leftValue * rightValue;
    if (root->value == "/") return leftValue / rightValue;

    return 0;  // 默认返回0
}

// 辅助函数：跳过空格
void skipSpaces(const string& expr, int& pos) {
    while (pos < expr.length() && isspace(expr[pos])) {
        pos++;
    }
}

int main() {
    string expression;
    cout << "请输入表达式: ";
    getline(cin, expression);

    int pos = 0;
    auto root = buildExpressionTree(expression, pos);  // 构建表达式树
    int result = evaluateExpressionTree(root);         // 计算表达式树的值

    cout << "表达式的结果是: " << result << endl;

    return 0;
}

