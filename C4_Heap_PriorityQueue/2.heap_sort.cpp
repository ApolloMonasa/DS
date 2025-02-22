/*************************************************************************
	> File Name: 2.heap_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 03:43:29 PM CST
 ************************************************************************/
//线性建堆法和普通建堆法
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define cmp >
#define ROOT 1
#define FATHER(i) ((i)/2)
#define LEFT(i)   ((i)*2)
#define RIGHT(i)  ((i)*2+1)

#define swap(a, b) {\
    __typeof(a) __c = (a);\
    (a) = (b), (b) = __c;\
}

#define TEST(func, arr, n) {\
    printf("TEST : %s ", #func);\
    int *temp = (int *)malloc(sizeof(int) * n);\
    memcpy(temp, arr, sizeof(int) * n);\
    long long b = clock();\
    func(temp, n);\
    long long e = clock();\
    if (check(temp, n)) {\
        printf("OK\t");\
    } else {\
        printf("FAIL\t");\
    }\
    printf("%lld ms\n", 1000 * (e - b)/ CLOCKS_PER_SEC);\
    free(temp);\
}

int *getRandomData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) arr[i] = rand() % 100000;
    return arr;
}

bool check(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

inline void up_updata(int *data, int i){
    while (i > 1 && data[i] cmp data[FATHER(i)]) {
        swap(data[i], data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

inline void down_updata(int *data, int i, int n){
    while (LEFT(i) <= n) {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if(data[l] cmp data[ind]) ind = l;
        if(r <= n && data[r] cmp data[ind]) ind = r;
        if(ind == i) return ;
        swap(data[ind], data[i]);
    }
    return ;
}

inline void normal_heap_build(int *data, int n) {
    for(int i = 2; i <= n; i++) {
        up_updata(data, i);
    }
    return ;
}

inline void linear_heap_build(int *data, int n) {
    for(int i = n / 2; i >= 1; i--) {
        down_updata(data, i, n);
    }
    return ;
}

void heap_sort_final(int *data, int n) {
    for (int i = n; i >= 2; i--) {
        swap(data[i], data[1]);
        down_updata(data, 1, i - 1);
    }
    return ;
}

void noraml_heap(int *arr, int n) {
    int *data = arr - 1;
    normal_heap_build(arr, n);
    heap_sort_final(data, n);
    return ;
}

void linear_heap(int *arr, int n) {
    int *data = arr - 1;
    linear_heap_build(arr, n);
    heap_sort_final(data, n);
    return ;
}
int main(){
    srand(time(0));
    #define MAX_N 100000000
    int *arr = getRandomData(MAX_N);
    TEST(noraml_heap, arr, MAX_N);
    TEST(linear_heap, arr, MAX_N);
    return 0;
}
