/*************************************************************************
	> File Name: 8.C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 03:32:07 PM CST
 ************************************************************************/


#include<iostream>
#include<stdio.h>
using namespace std;

int f(int *A, int pos, int n){
    if(pos == n) return 0;
    int mov = A[pos] - 1;
    A[pos+1] += mov;
    A[pos] = 1;
    int ret = mov + f(A, pos + 1, n);
    return ret;
}


int main(){
    int n, m;
    cin >> n >> m;
    int X[m], A[n+1];
    for(int i = 0; i < m; i++){
        cin >> X[i];
    }
    for(int i = 0; i < m; i++){
        cin >> A[X[i]];
    }
    int sum = 0;
    for(int i = 0; i < m; i++){
        sum += A[X[i]];
    }
    if(sum != n){
        cout << "-1\n";
        return 0;
    } else {
        int ret = f(A, 1, n);
        cout << ret << endl;
    }

    return 0;
}
