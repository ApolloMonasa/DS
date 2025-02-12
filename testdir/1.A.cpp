/*************************************************************************
	> File Name: 1.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 01:35:11 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int min_max_lunch_time(int N, int K[]) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += K[i];
    }
    int half = total / 2;

    // 动态规划数组
    int *dp = (int *)calloc(half + 1, sizeof(int));
    dp[0] = 1;

    // 填充动态规划数组
    for (int i = 0; i < N; i++) {
        int num = K[i];
        for (int j = half; j >= num; j--) {
            if (dp[j - num]) {
                dp[j] = 1;
            }
        }
    }

    // 找到最接近 half 的子集和
    int j;
    for (j = half; j >= 0; j--) {
        if (dp[j]) {
            break;
        }
    }

    // 释放动态规划数组
    free(dp);

    // 返回结果
    return (j > total - j) ? j : (total - j);
}

int main() {
    int N;
    scanf("%d", &N);

    int *K = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }

    int result = min_max_lunch_time(N, K);
    printf("%d\n", result);

    // 释放内存
    free(K);

    return 0;
}
