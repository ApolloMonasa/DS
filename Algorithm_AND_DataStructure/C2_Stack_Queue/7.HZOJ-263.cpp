/*************************************************************************
	> File Name: 7.HZOJ-263.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 04:41:34 PM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsValid(vector<int> &arr, int n){
    stack<int> s;
    int x = 1;//模拟入栈
    for(int i = 0; i < n; i++) {
        if(s.empty() || s.top() < arr[i]) {
            while(x <= arr[i]) {
                s.push(x);
                x++;
            }
        }
        if(s.empty() || s.top() != arr[i]) return false;
        s.pop();
    }
    return true;
}

int main(){
    int n, cnt = 20;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) arr[i] = i + 1;
    do{
        if(IsValid(arr, n)){
            for(int i = 0; i < n; i++){
                cout << arr[i];
            }
            cout << endl;
            cnt--;
        }
    } while(next_permutation(arr.begin(),arr.end()) && cnt);
    return 0;
}

