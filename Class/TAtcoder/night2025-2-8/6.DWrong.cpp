#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 100000
#define MAX_A 100000

// 定义骰子的结构体
typedef struct {
    int k;                  // 面数
    int *a;                 // 面上的数字
    int *count;             // 数字出现的次数
} Dice;

// 计算两个骰子的相同数字概率
double calculate_probability(Dice *dice1, Dice *dice2) {
    double prob = 0.0;
    // 遍历骰子1的所有数字
    for (int i = 0; i < dice1->k; i++) {
        int num = dice1->a[i];
        // 检查骰子2是否包含该数字
        for (int j = 0; j < dice2->k; j++) {
            if (dice2->a[j] == num) {
                // 计算概率并累加
                prob += (1.0 / dice1->k) * (1.0 / dice2->k);
                break;
            }
        }
    }
    return prob;
}

int main() {
    int N;
    scanf("%d", &N);

    Dice dice[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &dice[i].k);
        dice[i].a = (int *)malloc(dice[i].k * sizeof(int));
        dice[i].count = (int *)calloc(MAX_A + 1, sizeof(int));
        for (int j = 0; j < dice[i].k; j++) {
            scanf("%d", &dice[i].a[j]);
            dice[i].count[dice[i].a[j]]++;
        }
    }

    double max_prob = 0.0;
    // 遍历所有骰子对
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double prob = calculate_probability(&dice[i], &dice[j]);
            if (prob > max_prob) {
                max_prob = prob;
            }
        }
    }

    // 输出结果，保留12位小数
    printf("%.12lf\n", max_prob);

    // 释放内存
    for (int i = 0; i < N; i++) {
        free(dice[i].a);
        free(dice[i].count);
    }

    return 0;
}
