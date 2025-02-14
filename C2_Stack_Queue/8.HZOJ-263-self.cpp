/*************************************************************************
	> File Name: 8.HZOJ-263-self.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 05:05:10 PM CST
 ************************************************************************/

#include<stack>
#include<iostream>
using namespace std;

int result[20] = {0};
int cnt = 20;

bool IsValid(int *arr, int n) {
    stack<int> s;
    int x = 1; // 初始化x为1
    for(int i = 0; i < n; i++) {
        // 模拟入栈操作
        if(s.empty() || s.top() < arr[i]) {
            while(x <= arr[i]) {
                s.push(x);
                x++;
            }
        }
        // 检查栈顶元素是否与当前元素匹配
        if(s.empty() || s.top() != arr[i]) return false;
        s.pop(); // 出栈
    }
    return true;
}

void f(int index, int n, int *used, int *arr, int *result) {
    if(!cnt) return;
    if(index == n){
        if(IsValid(result, n)){
            for(int i = 0; i < n; i++){
                cout << result[i];
            }
            cout << endl;
            cnt--;
        }
        return ;
    }
    for(int i = 0; i < n; i++){
        if (!used[i]) {
            result[index] = arr[i];
            used[i] = 1;
            f(index + 1, n, used, arr, result);
            used[i] = 0;
        }
    }
    return ;
}
int main(){
    int n, cnt = 20;
    cin >> n;
    int arr[n], used[n];
    for(int i = 0; i < n; i++) arr[i] = i + 1, used[i] = 0;
    f(0, n, used, arr, result);
    return 0;
}
