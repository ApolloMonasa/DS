/*************************************************************************
	> File Name: 14-HZOJ-251.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 09:37:00 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // 找到目标行（y的中位数）
    qsort(y, n, sizeof(int), compare);
    int target_y = y[n / 2];

    // 计算所有士兵移动到目标行的步数
    int total_steps = 0;
    for (int i = 0; i < n; i++) {
        total_steps += abs(y[i] - target_y);
    }

    // 找到目标列（x的中位数）
    qsort(x, n, sizeof(int), compare);
    int target_x = x[n / 2];

    // 计算所有士兵在目标行上连续排列的步数
    for (int i = 0; i < n; i++) {
        total_steps += abs(x[i] - (target_x + i - n / 2));
    }

    printf("%d\n", total_steps);

    return 0;
}
