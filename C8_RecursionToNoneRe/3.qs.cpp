/*************************************************************************
	> File Name: 6.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 08:37:22 PM CST
 ************************************************************************/

#include"0.sort_test.h"
using namespace std;
void quick_sort(int *arr, int l, int r) {
    if(r - l <= 2) {//code = 0
        if(r - l <= 1) return ;
        if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    //partation //code = 1
    int x = l, y = r - 1, z = arr[x];
    while (x < y) {
        while(x < y && z <= arr[y]) --y;
        if(x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    //code = 2
    quick_sort(arr, l, x);
    //code = 3
    quick_sort(arr, x + 1, r);
    //code = 4
    return ;
}

struct Data {
    int *arr, l, r;
    int x;
    int code;
    Data(int *arr, int l, int r)
    : arr(arr), l(l), r(r), code(0) {}
};

void unrecursion_qs(int *arr, int l, int r) {
    stack<Data> s;
    Data d(arr, l, r);
    s.push(d);
    while (!s.empty()) {
        Data& cur = s.top();
        switch (cur.code) {
            case 0 : {
                if(cur.r - cur.l <= 2) {//code = 0
                    if(cur.r - cur.l <= 1) cur.code = 4;
                    if(cur.arr[cur.l] > cur.arr[cur.l + 1]) {swap(cur.arr[cur.l], cur.arr[cur.l + 1]);}
                    cur.code = 4;
                } else {
                    cur.code = 1;
                }
            } break;
            case 1 : {
                int x = cur.l, y = cur.r, z = cur.arr[cur.l];
                while (x < y) {
                    while (x < y && z <= cur.arr[y]) --y;
                    if (x < y) cur.arr[x++] = cur.arr[y];
                    while (x < y && cur.arr[x] <= z) ++x;
                    if (x < y) cur.arr[y--] = cur.arr[x];
                }
                cur.arr[x] = z;
                cur.x = x;
                cur.code = 2;
            } break;
            case 2 : {
                Data d(cur.arr, cur.l, cur.x);
                cur.code = 3;
                s.push(d);
            } break;
            case 3 : {
                Data d(cur.arr, cur.x + 1, cur.r);
                cur.code = 4;
                s.push(d);
            } break;
            case 4 : {s.pop();} break;
        }
    }
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
    TEST(unrecursion_qs, arr_b,    BIG_DATA_N);
    TEST(quick_sort_v1, arr_b, BIG_DATA_N);
    TEST(quick_sort_v2, arr_b, BIG_DATA_N);
    TEST(quick_sort_v3, arr_b, BIG_DATA_N);
    TEST(quick_sort_v4, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
