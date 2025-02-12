/*************************************************************************
	> File Name: 4.PermutationEnumeration.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 01:02:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 递归函数，用于枚举所有排列
void enumeratePermutations(int arr[], int n, int index, int result[], int used[]) {
    // 如果已经生成了一个完整的排列，打印结果
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    // 遍历所有元素，选择未被使用的元素加入当前排列
    for (int i = 0; i < n; i++) {
        if (!used[i]) { // 如果当前元素未被使用
            result[index] = arr[i]; // 将当前元素加入排列
            used[i] = 1; // 标记当前元素为已使用
            enumeratePermutations(arr, n, index + 1, result, used); // 递归到下一个位置
            used[i] = 0; // 回溯，恢复当前元素为未使用
        }
    }
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

    // 动态分配数组内存，用于存储当前排列
    int *result = (int *)malloc(n * sizeof(int));
    if (result == NULL) { // 检查内存是否分配成功
        printf("内存分配失败！\n"); // 如果分配失败，提示错误并退出程序
        free(arr); // 释放之前分配的 arr 数组内存
        return 1; // 返回 1 表示程序异常退出
    }

    // 动态分配数组内存，用于标记元素是否被使用
    int *used = (int *)calloc(n, sizeof(int)); // 使用 calloc 初始化数组为 0
    if (used == NULL) { // 检查内存是否分配成功
        printf("内存分配失败！\n"); // 如果分配失败，提示错误并退出程序
        free(arr); // 释放 arr 数组的内存
        free(result); // 释放 result 数组的内存
        return 1; // 返回 1 表示程序异常退出
    }

    // 调用递归函数，开始枚举所有排列
    printf("所有可能的排列:\n");
    enumeratePermutations(arr, n, 0, result, used);

    // 释放动态分配的内存，避免内存泄漏
    free(arr); // 释放 arr 数组的内存
    free(result); // 释放 result 数组的内存
    free(used); // 释放 used 数组的内存

    return 0; // 程序正常退出
}
