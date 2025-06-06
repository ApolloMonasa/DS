/*************************************************************************
	> File Name: 10.lg374D.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 10:17:25 AM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// 定义点的结构体
typedef struct {
    double x, y;
} Point;

// 定义线段的结构体
typedef struct {
    Point p1, p2;
} Segment;

// 计算两点之间的距离
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// 计算打印一条线段的时间
double print_time(Point start, Segment seg, double S, double T) {
    // 选择从 p1 开始
    double time1 = distance(start, seg.p1) / S + distance(seg.p1, seg.p2) / T;
    // 选择从 p2 开始
    double time2 = distance(start, seg.p2) / S + distance(seg.p2, seg.p1) / T;
    // 返回较小的时间
    return (time1 < time2) ? time1 : time2;
}

// 枚举所有排列和选择，计算最小时间
double min_print_time(Segment segments[], int N, double S, double T) {
    // 初始化最小时间为最大值
    double min_time = DBL_MAX;

    // 生成所有排列
    int indices[N];
    for (int i = 0; i < N; i++) indices[i] = i;

    do {
        // 枚举所有端点的选择（2^N 种）
        for (int mask = 0; mask < (1 << N); mask++) {
            double total_time = 0;
            Point current = {0, 0}; // 初始位置

            // 按照排列顺序处理每条线段
            for (int i = 0; i < N; i++) {
                int idx = indices[i];
                Segment seg = segments[idx];

                // 根据 mask 决定从哪个端点开始
                Point start = (mask & (1 << idx)) ? seg.p2 : seg.p1;
                Point end = (mask & (1 << idx)) ? seg.p1 : seg.p2;

                // 计算时间
                total_time += distance(current, start) / S; // 移动到起点
                total_time += distance(start, end) / T;     // 打印线段
                current = end; // 更新当前位置
            }

            // 更新最小时间
            if (total_time < min_time) {
                min_time = total_time;
            }
        }
    } while (next_permutation(indices, N)); // 生成下一个排列

    return min_time;
}

// 生成下一个排列
int next_permutation(int arr[], int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return 0; // 没有下一个排列

    int j = n - 1;
    while (arr[j] <= arr[i]) j--;
    swap(&arr[i], &arr[j]);

    reverse(arr + i + 1, n - i - 1);
    return 1;
}

// 交换两个整数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 反转数组
void reverse(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&arr[i], &arr[n - 1 - i]);
    }
}

int main() {
    int N;
    double S, T;
    scanf("%d %lf %lf", &N, &S, &T);

    Segment segments[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf %lf %lf", &segments[i].p1.x, &segments[i].p1.y,
              &segments[i].p2.x, &segments[i].p2.y);
    }

    double result = min_print_time(segments, N, S, T);
    printf("%.20lf\n", result);

    return 0;
}
