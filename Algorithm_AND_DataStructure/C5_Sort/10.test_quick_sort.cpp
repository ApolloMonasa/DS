/*************************************************************************
	> File Name: 10.test_quick_sort.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 13 Mar 2025 03:37:49 PM CST
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include"0.sort_test.h"
void quick_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if(r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int x = l, y = r - 1, z = arr[l];
    while(x < y) {
        while (x < y && z <=arr[y]) --y;
        if(x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);

    return ;
}


void quick_sort_p1(int *arr, int l, int r) {
    if (r - l <= 2) {
        if(r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int x = l, y = r - 1, z = arr[l];
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) swap(arr[x++], arr[y--]);
    } while(x <= y);
    quick_sort_p1(arr, l, x);
    quick_sort_p1(arr, x, r);

    return ;
}

int three(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b ,c);
    return b;
}
void quick_sort_p2(int *arr, int l, int r) {
    if (r - l <= 2) {
        if(r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    int x = l, y = r - 1, z = three(
        arr[l],
        arr[r - 1],
        arr[(l + r) / 2]
        );
    do {
        while(arr[x] < z) ++x;
        while(arr[y] > z) --y;
        if(x <= y) {
            swap(arr[x], arr[y]);
            ++x,--y;
        }
    } while(x <= y);
    quick_sort_p2(arr, l, x);
    quick_sort_p2(arr, x, r);
    return ;
}
void quick_sort_p3(int *arr, int l, int r) {
    if (r - l <= 2) {
        if(r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    while (l < r) {
        int x = l, y = r - 1, z = three(
            arr[l],
            arr[r - 1],
            arr[(l + r) / 2]
            );
        do {
            while(arr[x] < z) ++x;
            while(arr[y] > z) --y;
            if(x <= y) {
                swap(arr[x], arr[y]);
                ++x,--y;
            }
        } while(x <= y);
        quick_sort_p3(arr, l, x);
        l = x;
    }
    return ;
}

#define threshold 16
void __quick_sort_p4(int *arr, int l, int r) {
    while (r - l > threshold) {
        int x = l, y = r - 1, z = three(
            arr[l],
            arr[r - 1],
            arr[(l + r) / 2]
            );
        do {
            while(arr[x] < z) ++x;
            while(arr[y] > z) --y;
            if(x <= y) {
                swap(arr[x], arr[y]);
                ++x,--y;
            }
        } while(x <= y);
        __quick_sort_p4(arr, l, x);
        l = x;
    }
    return ;
}
void unguarded_insert_sort(int *arr, int l, int r){
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if(arr[i] < arr[ind]) ind = i;
    }
    //不能直接交换
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return ;
}

void quick_sort_p4(int *arr, int l, int r) {
    __quick_sort_p4(arr, l, r);
    unguarded_insert_sort(arr, l, r);  
    return ;
}
int main() {
    int *arr_s = getRandomData(SMALL_DATA_N);
    int *arr_b = getRandomData(BIG_DATA_N);
    TEST(quick_sort, arr_s, SMALL_DATA_N);
    TEST(quick_sort, arr_b, BIG_DATA_N);
    TEST(quick_sort_p1, arr_s, SMALL_DATA_N);
    TEST(quick_sort_p1, arr_b, BIG_DATA_N);
    TEST(quick_sort_p2, arr_s, SMALL_DATA_N);
    TEST(quick_sort_p2, arr_b, BIG_DATA_N);
    TEST(quick_sort_p3, arr_s, SMALL_DATA_N);
    TEST(quick_sort_p3, arr_b, BIG_DATA_N);
    TEST(quick_sort_p4, arr_s, SMALL_DATA_N);
    TEST(quick_sort_p4, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);

    return 0;
}
