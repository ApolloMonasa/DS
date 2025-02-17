#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // 计算 
    int count1 = 0;
    int m = n;
    while (m) {
        count1++;
        m = m - ((m - 1) / 3 + 1);// 1 | 0 0 1 | 0 0 1 懂？
    }

    // 计算 c2：找到满足 n % 3 == 1 的最小 c2
    int count2 = 1;
    while (n % 3 != 1) {
        n = n - ((n - 1) / 3 + 1);// 1 | 0 0 1 | 0 0 1 懂？
        count2++;
    }

    // 输出结果
    printf("%d %d\n", count1, count2);

    return 0;
}
