/*************************************************************************
	> File Name: 6.HZOJ-236.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 04:59:43 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

void f(int i, int j, int n, int m, int *a){
    if(i == m){
        for(int k = 0; k < m; k++){
            if(k) printf(" ");
            printf("%d", a[k]);
        }
        printf("\n");
        return ;
    }
    for(int k = j; k <= n && n - k + 1 >= m - i; k++){
        a[i] = k;
        f(i+1, k+1, n, m, a);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int *a = (int*)malloc(m * sizeof(int));
    if(!a){
        printf("Malloc Error\n");
        return 1;
    }
    f(0, 1, n, m, a);
    return 0;
}
