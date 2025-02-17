/*************************************************************************
	> File Name: 2.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:13:43 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[M];
    int flag[1001] = {0};
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
        flag[A[i]] = 1;  //make signs
    }

    // 找出缺失的整数
    int missing[N-M];  // 存储缺失的整数
    int count = 0;  // 计数缺失的整数

    for (int i = 1; i <= N; i++) {
        if (flag[i] == 0) {
            missing[count++] = i;  // 如果 i 没有出现，添加到 missing 数组
        }
    }

    // 输出结果
    printf("%d\n", count);  // 输出缺失的整数个数
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("%d ", missing[i]);  // 输出所有缺失的整数
        }
        printf("\n");
    }

    return 0;
}

