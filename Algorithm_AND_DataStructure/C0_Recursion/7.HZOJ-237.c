/*************************************************************************
	> File Name: 7.HZOJ-237.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 05:17:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void f(int i, int n, int *a, int *used){
    if(i == n) {
        for(int k = 0; k < n; k++){
            if(k) printf(" ");
            printf("%d", a[k]);
        }
        printf("\n");
        return ;
    }
    for(int k = 0; k < n; k++){
        if(!used[k]){
            a[i] = k+1;
            used[k] = 1;
            f(i+1,n, a,used);
            used[k] = 0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *used = (int *)calloc(n, sizeof(int)); // 使用 calloc 初始化数组为 0
    int a[n];
    f(0, n, a, used);
    return 0;
}
