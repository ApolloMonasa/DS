/*************************************************************************
	> File Name: 46.lgP3374.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 02:32:32 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

int c[500000];
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
    int n, m;
    cin >> n >> m;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        add(i, a, n);
    }
    int op, x, y;
    for(int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if(op == 1){
            add(x, y, n);
        } else {
            cout << query(y) - query(x-1) << endl;
        }
    }
    return 0;
}
