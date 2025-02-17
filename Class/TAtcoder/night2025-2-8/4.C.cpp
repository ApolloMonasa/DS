#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int Q[N + 1], P[N + 1], pos[N + 1];
    
    for (int i = 1; i <= N; i++) scanf("%d", &P[i]);
    getchar();
    for (int i = 1; i <= N; i++) {
        scanf("%d", &Q[i]);
        pos[Q[i]] = i;  // 预处理，记录每个值在 Q 中的位置
    }
    
    for (int i = 1; i <= N; i++) {
        if (i > 1) printf(" ");
        printf("%d", Q[P[pos[i]]]);  // 直接通过 pos 数组找到 j
    }
    printf("\n");
    
    return 0;
}
