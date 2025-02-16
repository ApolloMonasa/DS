/*************************************************************************
	> File Name: 18.HZOJ-245.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 08:13:01 PM CST
 ************************************************************************/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int p = arr[n / 2], ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(p-arr[i]);
    }
    cout << ans << endl;
    return 0;
}
