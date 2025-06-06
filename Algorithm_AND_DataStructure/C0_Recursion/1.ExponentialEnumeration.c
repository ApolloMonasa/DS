/*************************************************************************
	> File Name: 1.ExponentialEnumeration.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 12:18:02 PM CST
 ************************************************************************/
//指数型递归：每次递归决定是否选择当前元素
#include <stdio.h>
#include <stdlib.h>

// 递归函数，用于枚举所有子集
void enumerateSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    // 如果已经处理完所有元素，打印当前子集
    if (index == n) {
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // 不选择当前元素，继续递归
    enumerateSubsets(arr, n, index + 1, subset, subsetSize);

    // 选择当前元素，继续递归
    subset[subsetSize] = arr[index];
    enumerateSubsets(arr, n, index + 1, subset, subsetSize + 1);
}

int main() {
    int n;

    // 输入集合的大小
    printf("请输入集合的大小 N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N 必须大于 0。\n");
        return 1;
    }

    // 动态分配数组内存
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 输入 N 个数字
    printf("请输入 %d 个数字:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 用于存储当前子集的数组
    int *subset = (int *)malloc(n * sizeof(int));
    if (subset == NULL) {
        printf("内存分配失败！\n");
        free(arr);
        return 1;
    }

    // 调用递归函数
    printf("所有可能的子集:\n");
    enumerateSubsets(arr, n, 0, subset, 0);

    // 释放动态分配的内存
    free(arr);
    free(subset);

    return 0;
}
