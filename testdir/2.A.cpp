/*************************************************************************
	> File Name: 2.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 01:50:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <limits.h>

// 计算分组后的最大值
int calculate_max(int N, int K[], int mask) {
    int sumA = 0, sumB = 0;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            sumA += K[i];  // 分到组 A
        } else {
            sumB += K[i];  // 分到组 B
        }
    }
    return (sumA > sumB) ? sumA : sumB;
}

int min_max_lunch_time(int N, int K[]) {
    int min_max = INT_MAX;  // 初始化为最大值
    int total_cases = 1 << N;  // 总分组情况数：2^N

    // 遍历所有分组情况
    for (int mask = 0; mask < total_cases; mask++) {
        int current_max = calculate_max(N, K, mask);
        if (current_max < min_max) {
            min_max = current_max;  // 更新最小值
        }
    }

    return min_max;
}

int main() {
    int N;
    scanf("%d", &N);

    int K[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }

    int result = min_max_lunch_time(N, K);
    printf("%d\n", result);

    return 0;
}
