/*************************************************************************
	> File Name: 2.ExponentialDictionary.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 12:30:31 PM CST
 ************************************************************************/

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

    // 情况1：选择当前元素
    // 将当前元素 arr[index] 加入 subset 数组
    subset[subsetSize] = arr[index];
    // 递归到下一个元素，subsetSize 增加 1，表示当前子集多了一个元素
    enumerateSubsets(arr, n, index + 1, subset, subsetSize + 1);

    // 情况2：不选择当前元素
    // 直接递归到下一个元素，subset 数组和 subsetSize 不变
    enumerateSubsets(arr, n, index + 1, subset, subsetSize);
}

int main() {
    int n; // 定义变量 n，用于存储集合的大小

    // 提示用户输入集合的大小
    printf("请输入集合的大小 N: ");
    scanf("%d", &n); // 读取用户输入的 N

    // 检查 N 是否合法
    if (n <= 0) {
        printf("N 必须大于 0。\n"); // 如果 N 不合法，提示错误并退出程序
        return 1; // 返回 1 表示程序异常退出
    }

    // 动态分配数组内存，用于存储用户输入的 N 个数字
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) { // 检查内存是否分配成功
        printf("内存分配失败！\n"); // 如果分配失败，提示错误并退出程序
        return 1; // 返回 1 表示程序异常退出
    }

    // 提示用户输入 N 个数字
    printf("请输入 %d 个数字:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // 逐个读取用户输入的数字，并存储到数组 arr 中
    }

    // 动态分配数组内存，用于存储当前子集
    int *subset = (int *)malloc(n * sizeof(int));
    if (subset == NULL) { // 检查内存是否分配成功
        printf("内存分配失败！\n"); // 如果分配失败，提示错误并退出程序
        free(arr); // 释放之前分配的 arr 数组内存
        return 1; // 返回 1 表示程序异常退出
    }

    // 调用递归函数，开始枚举所有子集
    printf("所有可能的子集（按字典顺序）:\n");
    enumerateSubsets(arr, n, 0, subset, 0);

    // 释放动态分配的内存，避免内存泄漏
    free(arr); // 释放 arr 数组的内存
    free(subset); // 释放 subset 数组的内存

    return 0; // 程序正常退出
}
