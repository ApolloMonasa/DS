/*************************************************************************
	> File Name: 9.test_shell.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 13 Mar 2025 02:21:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>
#include"0.sort_test.h"

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
void unguarded_insert_sort(int *arr, int l, int r, int step) {
    int ind = l;
    for (int i = ind + step; i < r; i += step) {
        if(arr[i] < arr[ind]) ind = i;
    }
    while(ind > l) {
        swap(arr[ind], arr[ind - step]);
        ind -= step;
    }
    for (int i = l + 2 * step; i < r; i += step) {
        int j = i;
        while(arr[j] < arr[j - step]){
            swap(arr[j], arr[j - step]);
            j -= step;
        }
    }
    return ;
}

void shell_sort(int *arr, int l, int r) {
    int n = r - l, step = n / 2 == 0 ? 1 : n / 2;
    do {
        for (int i = l , I = l + step; i < I; i++) {
            unguarded_insert_sort(arr, i, r, step);
        }
        step /= 2;
    } while(step);
    return ;
}

void hibbard_shell_sort(int *arr, int l, int r) {
    int step = 1, n = r - l;
    while(step * 2 + 1 <= n / 2) step = step * 2 + 1;

    do {
        for (int i = l, I = l + step; i < I; i++) {
            unguarded_insert_sort(arr, i, r, step);
        }
        step /= 2;
    } while(step);
    return ;
}

int main() {
    int *arr = getRandomData(BIG_DATA_N);
    TEST(insert_sort,    arr, SMALL_DATA_N);
    TEST(shell_sort,         arr, BIG_DATA_N);
    TEST(hibbard_shell_sort, arr, BIG_DATA_N);
    return 0;
}
