/*************************************************************************
	> File Name: 5.bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 06:45:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"0.sort_test.h"

void bubble_sort(int *arr, int l, int r) {
    for (int i = r - 1, I = l + 1, cnt; i >= I; i--) {
        cnt = 0;
        for (int j = l; j < i; j++) {
            if(arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            cnt++;
        }
        if(!cnt) break;
    }
    return ;
}

int main() {
    int *arr = getRandomData(SMALL_DATA_N);
    TEST(bubble_sort, arr,   SMALL_DATA_N);
    free(arr);
    return 0;
}
