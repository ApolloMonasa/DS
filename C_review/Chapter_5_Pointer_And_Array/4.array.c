/*************************************************************************
	> File Name: 4.array.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 21 Feb 2025 09:18:11 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void test1() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = 2 * i;
    }
    for (int i = 0; i < 10; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return ;
}

void test2() {
    int n;
    printf("input a number:\n");
    scanf("%d", &n);
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        a[i] = 3  * i;
    }
    for (int i = 0; i < 2 * n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return ;
}

void test3() {
    int a[5] = {1};//初始化后：不确定的数据为0
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }//局部数组不初始化值随机
    return ;
}

void test4() {
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return ;
    
}

void test5() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    size_t size = sizeof(a) / sizeof(int);
    printf("sizeof(a) / sizeof(int) = %lu\n", size);
    printf("a = %p\n", a);
    for (int i = 0; i < size; i++) {
        printf("&a[%d] = %p\n", i, &a[i]);
    }
    return ;
}

int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}
