/*************************************************************************
	> File Name: 8.radix_sort.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 19 Feb 2025 08:09:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include"0.sort_test.h"

void radix_sort(int *arr, int l, int r) {//稍微改进一下：扩大基数的表示范围//2^32--->x^16 == 65536
    #define K 65536
    int *cnt  = (int *)malloc(sizeof(int) * K);
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    //round 1
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));
    //round 2
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] / K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));
    return ;
}

int main() {
    int *arr_s = getRandomData(SMALL_DATA_N);
    int *arr_b = getRandomData(BIG_DATA_N);
    TEST(radix_sort, arr_s, SMALL_DATA_N);
    TEST(radix_sort, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
