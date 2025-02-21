/*************************************************************************
	> File Name: 2.hex.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 03:56:50 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a = 0x6A;
    printf("a(10) = %d\n", a);
    printf("a(16) = %x\n", a);
    printf("a(16) = %X\n", a);
    int b = 0x7fffffff;
    printf("MAX_INT: %d\n", b);
    int c = 0x80000000;
    printf("MIN_INT: %d\n", c);
    printf("Input hex:\n");
    scanf("%x", &a);
    printf("a(10) = %d\n", a);
    printf("a(16) = %x\n", a);
    printf("a(16) = %X\n", a);
    return 0;
}
