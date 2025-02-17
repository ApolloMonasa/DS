/*************************************************************************
	> File Name: 47.lgP3368.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 02:53:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define int long long
struct FenwickTree {
    int c[500005];
    int lowbit(int x) {return -x&x;}
    void add(int i ,int val, int n){
        while(i <= n) {
            c[i] += val;
            i += lowbit(i);
        }
        return ;
    }
    int query(int i) {
        if(i == 0) return 0;
        return c[i] + query(i - lowbit(i));
    }
};


int n, m;
int a[500005];
FenwickTree cx, cy;
int S(int k) {
    return k * cx.query(k) - cy.query(k);
}
int32_t main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cx.add(i, a[i]-a[i-1], n);
        cy.add(i, (i-1) * (a[i] - a[i-1]), n);
    }
    char op;
    for(int i = 1, a, b, c; i<= m; i++) {
        cin >> op;
        switch(op) {
            case 'C' :{
                cin >> a >> b >> c;
                cx.add(a, c, n);
                cx.add(b + 1, -c, n);
                cy.add(a, (a - 1) * c, n);
                cy.add(b + 1, b * c, n);
            } break;
            case 'Q' :{
                cin >> a >> b;
                cout << S(b) - S(a - 1) << endl;
            }
        }
    }

    return 0;
}
