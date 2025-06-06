/*************************************************************************
	> File Name: 2.insertion_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 11:09:43 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"0.sort_test.h"
using namespace std;

void insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (j > l && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return ;
}

int main() {
    int *arr = getRandomData(BIG_DATA_N);
    TEST(insert_sort, arr, BIG_DATA_N);
    free(arr);
    return 0;
}

