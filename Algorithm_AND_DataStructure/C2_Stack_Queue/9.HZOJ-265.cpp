/*************************************************************************
	> File Name: 9.HZOJ-265.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 09:19:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stack>
#include<iostream>
using namespace std;
#define MAX_N 10000
char str[MAX_N + 5];
int match[MAX_N + 5] = {0};//match[i] == 0没有合法的匹配
//match[i] != 0存匹配括号的位置
stack<int> s;

int main(){
    cin >> (str + 1);//偏移：下标序号化
    //遍历字符窜的每一位
    for (int i = 1; str[i]; i++) {
        switch (str[i]) {
            case '(':
            case '[':
            case '{': s.push(i); break;
            case ')': {
                if (!s.empty() && str[s.top()] == '(') {
                    match[s.top()] = i;
                    match[i] = s.top();//delete
                    s.pop();
                } else {
                    s.push(i);//做信息隔绝，这个右括号代表这个位置及之前已经非法了
                }
            } break;
            case ']': {
                if (!s.empty() && str[s.top()] == '[') {
                    match[s.top()] = i;
                    match[i] = s.top();//delete
                    s.pop();
                } else {
                    s.push(i);//做信息隔绝，这个右括号代表这个位置及之前已经非法了
                }
            } break;
            case '}': {
                if (!s.empty() && str[s.top()] == '{') {
                    match[s.top()] = i;
                    match[i] = s.top();//delete
                    s.pop();
                } else {
                    s.push(i);//做信息隔绝，这个右括号代表这个位置及之前已经非法了
                }
            } break;
        }
    }
    int t_ans = 0, ans = 0, i = 1;
    while (str[i]) {
        if(match[i]) {
            t_ans += (match[i] - i + 1);
            i = match[i] + 1;
        } else {
            i++;
            t_ans = 0;
        }
        if (t_ans > ans) ans = t_ans;
    }
    cout << ans << endl;


    return 0;
}
