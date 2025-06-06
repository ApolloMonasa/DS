#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000

// 定义网格
char grid[MAX_N][MAX_N + 1]; // +1 用于存储字符串的结束符 '\0'

int main() {
    int N;
    scanf("%d", &N);

    // 读取网格
    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    // 对每个 i 进行操作
    for (int i = 1; i <= N / 2; i++) {
        int start = i - 1; // 转换为 0-based 索引
        int end = N - i;   // 转换为 0-based 索引

        // 遍历所有 (x, y) 对
        for (int x = start; x <= end; x++) {
            for (int y = start; y <= end; y++) {
                // 交换 (x, y) 和 (y, N-1-x) 的颜色
                char temp = grid[x][y];
                grid[x][y] = grid[y][N - 1 - x];
                grid[y][N - 1 - x] = temp;
            }
        }
    }

    // 输出最终网格
    for (int i = 0; i < N; i++) {
        printf("%s\n", grid[i]);
    }

    return 0;
}
