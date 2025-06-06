/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 19 Mar 2025 02:58:41 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;

void output(int *arr, int n, int ind = -1) {
    int len = 0;
    for (int i = 0; i < n; i++) len += printf("%4d", i);
    printf("\n");
    for (int i = 0; i < len; i++) printf("=");
    printf("\n");
    for (int i = 0; i < n; i++) {
        if(i == ind) printf("\033[1;32m");
        printf("%4d", arr[i]);
        if(i == ind) printf("\033[0m");
    }
    printf("\n");
    return ;
}

/*int binary_search(int *arr, int n, int x) {
    int head = -1, tail = n, mid;
    while(head + 1 != tail) {
        mid = (head + tail) / 2;
        if(arr[mid] <= x) head = mid;
        else tail = mid;
    }
    return head;
}*/

int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (arr[mid] == x) return mid;
        if(arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

void test_binary_search(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++) arr[i] = arr[i - 1] +rand() % 10;
    output(arr, n);
    int x;
    while(~scanf("%d", &x)) {
        if(x == -1) break;
        int ind = binary_search(arr, n , x);
        if(ind != -1) output(arr, n, ind);
        else printf("Not Found\n");
    }
}

#define min(a, b) ((a) < (b) ? (a) : (b))

double f(double x) {
    if (x >= 0) x -= min(x, 3000) * 0.03;
    if (x > 3000) x  -=(min(x, 12000) - 3000) * 0.1;
    if (x > 12000) x -=(min(x, 25000) - 12000) * 0.2;
    if (x > 25000) x -=(min(x, 35000) - 25000) * 0.25;
    if (x > 35000) x -=(min(x, 55000) - 35000) * 0.3;
    if (x > 55000) x -=(min(x, 80000) - 55000) * 0.35;
    if (x > 80000) x -=(x - 80000) * 0.45;
    return x;
}

double binary_algorithm(double y) {
    double head = 0, tail = 1e8, mid;
    while (tail - head > 1e-3) {
        mid = (head + tail) / 2.0;
        if(f(mid) <= y) head = mid;
        else tail = mid;
    }
    mid = (tail + head) / 2.0;
    return mid;
}

void test_binary_algorithm() {
    double y;
    printf("max pre_tax_monney : %.2lf\n", 1e8);
    while (~scanf("%lf", &y)) {
        if(y < 0) break;
        double x = binary_algorithm(y);
        printf("f(%.2lf) = %.2lf\n", x, y);
    }
}

int main() {
    #define MAX_N 10
    test_binary_search(MAX_N);
    test_binary_algorithm();
    return 0;
}

__attribute__((constructor))
void _init_rand_(){
    srand(time(0));
}
