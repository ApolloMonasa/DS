/*************************************************************************
	> File Name: 28.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 09:24:42 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int price[200005] = {0};
int q[200005] = {0};
int main() {
    cin >> n >>  m;
    for(int i = 0; i < n; i++) cin >> price[i];
    sort(price, price+n);
    for(int i = 0; i < n; i++){
        int s = 1;
        while(s*price[i] <= price[i+1]){
            s++;
        }
        s--;
        q[i] = s;
    }
    int sum = 0, i;
    for( i = 0; i < n &&  sum <=m; i++){
        sum += q[i]*q[i]*price[i];
    }
    ;
    cout << i << endl;
    return 0;
}
