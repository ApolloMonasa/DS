/*************************************************************************
	> File Name: 26.lgP1024.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 06:10:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip> // 用于控制输出格式
#include <algorithm> // 用于排序

using namespace std;

// 卡尔丹公式求解一元三次方程的三个实根
void solve_cubic_real_roots(double a, double b, double c, double d) {
    // 将方程转化为简化形式 y^3 + py + q = 0
    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

    // 计算 theta
    double theta = acos(-q / 2 / sqrt(-pow(p / 3, 3)));

    // 计算三个实根
    double root1 = 2 * sqrt(-p / 3) * cos(theta / 3) - b / (3 * a);
    double root2 = 2 * sqrt(-p / 3) * cos((theta + 2 * M_PI) / 3) - b / (3 * a);
    double root3 = 2 * sqrt(-p / 3) * cos((theta + 4 * M_PI) / 3) - b / (3 * a);

    // 将根存储到数组中
    double roots[3] = {root1, root2, root3};

    // 对根进行排序
    sort(roots, roots + 3);

    // 输出结果，保留两位小数
    printf("%.2lf %.2lf %.2lf\n", roots[0], roots[1], roots[2]);
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    solve_cubic_real_roots(a, b, c, d);

    return 0;
}
