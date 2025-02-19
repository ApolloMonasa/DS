/*************************************************************************
	> File Name: 6.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 08:37:22 PM CST
 ************************************************************************/

#include"0.sort_test.h"

void quick_sort(int *arr, int l, int r) {
    if(r - l <= 2) {
        if(r - l <= 1) return ;
        if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    //partation
    int x = l, y = r - 1, z = arr[x];
    while (x < y) {
        while(x < y && z <= arr[y]) --y;
        if(x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
    return ;
}

void quick_sort_v1(int *arr, int l, int r) {
    if(r - l <= 2) {
        if(r - l <= 1) return ;
        if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    //partation
    int x = l, y = r - 1, z = arr[l];
    do {
        while(arr[x] < z) ++x;
        while(arr[y] > z) --y;
        if(x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while(x <= y);
    quick_sort_v1(arr, l, x);
    quick_sort_v1(arr, x, r);
    return ;
}

int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b ,c);
    return b;
}

void quick_sort_v2(int *arr, int l, int r) {
    if(r - l <= 2) {
        if(r - l <= 1) return ;
        if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    //partation
    int x = l, y = r - 1, z = three_point_select(
        arr[l],
        arr[r - 1],
        arr[(l + r) / 2]
        );
    do {
        while(arr[x] < z) ++x;
        while(arr[y] > z) --y;
        if(x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while(x <= y);
    quick_sort_v2(arr, l, x);
    quick_sort_v2(arr, x, r);
    return ;
}

void quick_sort_v3(int *arr, int l, int r) {
    if(r - l <= 2) {
        if(r - l <= 1) return ;
        if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    while(l < r) {
        //partation
        int x = l, y = r - 1, z = three_point_select(
            arr[l],
            arr[r - 1],
            arr[(l + r) / 2]
            );
        do {
            while(arr[x] < z) ++x;
            while(arr[y] > z) --y;
            if(x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while(x <= y);
        quick_sort_v3(arr, l, x);//left
        l = x;
    }
    return ;
}

#define threthhold 16

void __quick_sort_v4(int *arr, int l, int r) {
    //if(r - l <= 2) {
    //    if(r - l <= 1) return ;
    //    if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
    //    return ;
    //}
    while(r - l > threthhold) {
        //partation
        int x = l, y = r - 1, z = three_point_select(
            arr[l],
            arr[r - 1],
            arr[(l + r) / 2]
            );
        do {
            while(arr[x] < z) ++x;
            while(arr[y] > z) --y;
            if(x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while(x <= y);
        __quick_sort_v4(arr, l, x);//left
        l = x;
    }
    return ;
}


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

void quick_sort_v4(int *arr, int l, int r) {
    __quick_sort_v4(arr, l, r);
    insert_sort(arr, l, r);
    return ;
}

int main() {
    int *arr_s = getRandomData(SMALL_DATA_N);
    int *arr_b = getRandomData(BIG_DATA_N);
    TEST(quick_sort, arr_s,    SMALL_DATA_N);
    TEST(quick_sort, arr_b,    BIG_DATA_N);
    TEST(quick_sort_v1, arr_b, BIG_DATA_N);
    TEST(quick_sort_v2, arr_b, BIG_DATA_N);
    TEST(quick_sort_v3, arr_b, BIG_DATA_N);
    TEST(quick_sort_v4, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
