/*************************************************************************
	> File Name: 45.FenwickTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 02:23:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int c[100];
inline int lowbit(int x) {return -x & x;}
void add(int i, int val, int n) {
    while(i <= n) c[i] += val, i += lowbit(i);
    return ;
}
int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}


int main() {
    int n;
    cin >> n;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        add(i, a, n);
    }
    for (int i = 1; i <= n; i++) {
        cout << query(i) << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++) {
        cout << query(i) - query(i-1) << " ";
    }
    cout << endl;

    return 0;
}
