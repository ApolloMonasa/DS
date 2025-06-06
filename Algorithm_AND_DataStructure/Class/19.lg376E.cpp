/*************************************************************************
	> File Name: 19.lg376E.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 10:38:30 AM CST
 ************************************************************************/
 #include <stdio.h>
#include <stdlib.h>

#define MAX_N 200010

typedef struct {
    int a;
    int b;
} Pair;

int compare(const void *x, const void *y) {
    Pair *p1 = (Pair *)x;
    Pair *p2 = (Pair *)y;
    return p1->a - p2->a;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        Pair pairs[MAX_N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &pairs[i].a);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &pairs[i].b);
        }

        // 按照 A_i 排序
        qsort(pairs, N, sizeof(Pair), compare);

        // 滑动窗口
        long long minResult = 1LL << 60;
        long long sumB = 0;
        int window[MAX_N];
        int left = 0, right = 0;

        for (int i = 0; i < N; i++) {
            sumB += pairs[i].b;
            window[right++] = pairs[i].b;

            if (right - left > K) {
                sumB -= window[left++];
            }

            if (right - left == K) {
                long long current = (long long)pairs[i].a * sumB;
                if (current < minResult) {
                    minResult = current;
                }
            }
        }

        printf("%lld\n", minResult);
    }

    return 0;
}
