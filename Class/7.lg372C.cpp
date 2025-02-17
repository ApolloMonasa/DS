/*#include<stdio.h>
#include<iostream>
using namespace std;

int get_substr_num(char *S, int N) {
    int count = 0;
    for(int i = 1; i < N-1; i++) {
        if(S[i]=='B'&&S[i-1]=='A'&&S[i+1]=='C') count++;
    }
    return count;
}

int main () {
    int N, Q, pos;
    scanf("%d %d", &N, &Q);
    char S[N+1], val;
    scanf("%s", S);
    for(int i = 0; i < Q; i++) {  // 修正循环条件
        scanf("%d %c", &pos, &val);  // 移除 getchar()
        S[pos-1] = val;
        int ret = get_substr_num(S, N);
        printf("%d\n", ret);
    }
    return 0;
}*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int N, Q, pos;
    char val;
    scanf("%d %d", &N, &Q);
    char S[N + 1];
    scanf("%s", S);

    // 预处理初始匹配数
    int count = 0;
    for (int i = 1; i < N - 1; i++) {
        if (S[i - 1] == 'A' && S[i] == 'B' && S[i + 1] == 'C') {
            count++;
        }
    }

    // 处理每次修改
    for (int i = 0; i < Q; i++) {
        scanf("%d %c", &pos, &val);
        pos--; // 转换为 0-based 索引

        // 检查修改位置及其前后是否影响匹配数
        for (int j = max(1, pos - 1); j <= min(N - 2, pos + 1); j++) {
            if (S[j - 1] == 'A' && S[j] == 'B' && S[j + 1] == 'C') {
                count--; // 移除旧的匹配
            }
        }

        // 修改字符
        S[pos] = val;

        // 重新检查修改位置及其前后是否新增匹配
        for (int j = max(1, pos - 1); j <= min(N - 2, pos + 1); j++) {
            if (S[j - 1] == 'A' && S[j] == 'B' && S[j + 1] == 'C') {
                count++; // 新增匹配
            }
        }

        // 输出当前匹配数
        printf("%d\n", count);
    }

    return 0;
}
