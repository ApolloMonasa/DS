#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Edge {
    double a, b, c, d, len;
} Edge;

int n, s, t;
vector<Edge> arr;
int aa[10];
double vail = 0, ans = -1;

double S(double x) { return x * x; }

double dis(double a, double b, double c, double d) {
    return sqrt(S(a - c) + S(b - d));
}

void solve() {
    double cnt = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        double x = 0, y = 0; // 初始位置
        cnt = 0;

        for (int i = 0; i < n; i++) {
            int idx = aa[i];
            if (mask & (1 << i)) {
                // 选择从 (c, d) 开始
                cnt += dis(x, y, arr[idx].c, arr[idx].d) / s; // 移动到起点
                cnt += arr[idx].len / t; // 打印线段
                x = arr[idx].a; // 更新当前位置
                y = arr[idx].b;
            } else {
                // 选择从 (a, b) 开始
                cnt += dis(x, y, arr[idx].a, arr[idx].b) / s; // 移动到起点
                cnt += arr[idx].len / t; // 打印线段
                x = arr[idx].c; // 更新当前位置
                y = arr[idx].d;
            }
        }

        // 更新最小时间
        if (ans < 0 || cnt < ans) {
            ans = cnt;
        }
    }
}

int main() {
    cin >> n >> s >> t;
    for (int i = 0, a, b, c, d; i < n; i++) {
        cin >> a >> b >> c >> d;
        double len = dis(a, b, c, d);
        arr.push_back({a, b, c, d, len});
        aa[i] = i;
        vail += len / t; // 累加所有线段的打印时间
    }

    // 枚举所有排列
    do {
        solve();
    } while (next_permutation(aa, aa + n));

    // 输出最小时间，保留 20 位小数
    printf("%.20lf\n", ans);

    return 0;
}
