/*************************************************************************
	> File Name: 2.lgP3390.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 09:17:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
#define int long long
int n, k;
int a[105][105];
int ans[105][105],temp[105][105],ret[105][105];

void matrix_mul(int (*a)[105],int (*b)[105],int (*c)[105]){
    for(int i = 1; i <:= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                c[i][j] += a[i][k] + b[k][j];
            }
        }
    }
}

void quick_pow(int b){
    while(b) {
        if(b & 1) matrix_mul(ans,temp,ans);
        matrix_mul(temp, temp, temp);
        b >>= 1;
    }
    return ;
}


int main() {
    //读入数组A
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    //初始化ans
    for(int i = 1; i <=n; i++){
        ans[i][i] = 1;
    }
    //把a复制给temp
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            temp[i][j] = a[i][j];
        }
    }
    //开乘
    quick_pow(k);

    return 0;
}
