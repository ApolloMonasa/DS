/*************************************************************************
	> File Name: 13.HZOJ-245.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 09:08:53 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    vector<int> arr;
    cin >> n;
    for(int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    //sort(arr.begin(), arr.end());
    nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
    int p = arr[n / 2];
    int ans = 0;
    for(int i = 0; i < n; i++) ans += abs(arr[i] - p);
    cout << ans << endl;
    return 0;
}
