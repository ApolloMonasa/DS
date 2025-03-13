/*************************************************************************
	> File Name: 11.test_merge.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 13 Mar 2025 06:41:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"0.sort_test.h"
void merge(int *arr, int l, int r) {
    if(r - l <= 1) return;
    int mid = (l + r) / 2;
    merge(arr, l, mid);
    merge(arr, mid, r);
    int p1 = l, p2 = mid, k = 0, n = r - l;
    int *temp = (int *)malloc(sizeof(int) * n);
    while(p1 < mid || p2 < r) {
        if(p2 == r ||(p1 < mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else /*if(p1 == mid || (p2 < r && arr[p2] <= arr[p1]))*/{
            temp[k++] = arr[p2++];
        }
    }
    for (int i = l; i < r; i++) arr[i] = temp[i - l];
    free(temp);
    return ;
}

int main() {
    int *arr = getRandomData(BIG_DATA_N);
    TEST(merge,arr,BIG_DATA_N);
    return 0;
}
