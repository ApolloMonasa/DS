/*************************************************************************
	> File Name: 27.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 06:39:49 PM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

// 定义函数 f(x) = ax^3 + bx^2 + cx + d
double f(double a, double b, double c, double d, double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

// 定义导数 f'(x) = 3ax^2 + 2bx + c
double f_prime(double a, double b, double c, double x) {
    return 3 * a * x * x + 2 * b * x + c;
}

// 牛顿迭代法求解
double newton_raphson(double a, double b, double c, double d, double initial_guess, double tolerance = 1e-7, int max_iterations = 1000) {
    double x = initial_guess;
    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(a, b, c, d, x);
        double fpx = f_prime(a, b, c, x);

        if (fabs(fpx) < tolerance) {
            break; // 导数为0，无法继续迭代
        }

        double x_new = x - fx / fpx;

        if (fabs(x_new - x) < tolerance) {
            return x_new; // 收敛到根
        }

        x = x_new;
    }
    return x; // 返回近似根
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    // 动态选择初始猜测值
    double initial_guess = d/a/2.0; // 可以根据实际情况调整
    double r[3];
    r[0] = newton_raphson(a, b, c, d, initial_guess);

    // 求解二次方程：x^2 + Bx + C = 0
    double A = 1.0, B = r[0] + b / a, C = -d / a / r[0];
    double delt = B * B - 4 * A * C;

    r[1] = (-B - sqrt(delt)) / (2 * A);
    r[2] = (-B + sqrt(delt)) / (2 * A);

    // 排序并输出
    sort(r, r + 3);
    printf("%.2lf %.2lf %.2lf\n", r[0], r[1], r[2]);

    return 0;
}
