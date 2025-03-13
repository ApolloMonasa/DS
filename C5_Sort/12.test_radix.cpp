/*************************************************************************
	> File Name: 12.test_radix.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 13 Mar 2025 07:09:54 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"0.sort_test.h"

void radix(int *arr, int l, int r) {
    #define K 65536
    int *cnt = (int *)malloc(sizeof(int) * K);
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] % K] +=1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));

    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] / K] +=1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] / K]] = arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));
    return ;
}
int main() {
    //printf("%d", 1 << 16);65536
    int *arr = getRandomData(BIG_DATA_N);
    TEST(radix, arr, BIG_DATA_N);
    return 0;
}
