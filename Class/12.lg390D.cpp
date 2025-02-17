#include <stdio.h>
#include <stdlib.h>

void print_partitions(int *arr, int n, int *partitions, int partition_count) {
    // 打印当前的划分
    for (int i = 0; i < partition_count; i++) {
        printf("Partition %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            if (partitions[j] == i) {
                printf("%d ", arr[j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void find_partitions(int *arr, int n, int *partitions, int index, int partition_count) {
    if (index == n) {
        print_partitions(arr, n, partitions, partition_count);
        return;
    }

    for (int i = 0; i < partition_count; i++) {
        partitions[index] = i;  // 将当前元素加入到第 i 组
        find_partitions(arr, n, partitions, index + 1, partition_count);
    }

    // 或者创建一个新分组
    partitions[index] = partition_count;
    find_partitions(arr, n, partitions, index + 1, partition_count + 1);
}

int main() {
    int arr[] = {1, 2, 3};  // 要划分的集合
    int n = sizeof(arr) / sizeof(arr[0]);

    // 存储每个元素的分组
    int partitions[n];
    find_partitions(arr, n, partitions, 0, 0);
    return 0;
}

