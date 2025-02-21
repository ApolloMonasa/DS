/*************************************************************************
	> File Name: 6.binary_search.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 21 Feb 2025 07:55:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int arr[10] = {0};
    srand(time(0));
    for (int i = 1; i < 10; i++) {
        arr[i] = arr[i - 1] + rand() % 10;
    }
    int len = 0;
    for (int i = 0; i < 10; i++) {
        len += printf("%4d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
    int x;
    while (~scanf("%d", &x)) {
        int cnt1 = 0, cnt2 = 0, flag1 = 0, flag2 = 0;
        for (int i = 0; i < 10; i++) {
            cnt1++;
            if (arr[i] != x) continue;
            flag1 = 1;
            break;
        }
        
        int l = 0, r = 9, mid;
        while (l <= r) {
            cnt2++;
            mid = (r + l) / 2;
            if (arr[mid] == x) {
                printf("(%d) arr[%d] = %d, find %d\n", cnt2, mid, arr[mid], x);
                flag2 = 1;
                break;
            }
            if(arr[mid] > x) {
                printf("(%d) arr[%d] = %d > %d, change[%d, %d] to [%d, %d ]\n", cnt2, mid, arr[mid], x, l, r, l ,mid - 1);
                r = mid - 1;
            }
            else {
                printf("(%d) arr[%d] = %d < %d, change[%d, %d] to [%d, %d ]\n", cnt2, mid, arr[mid], x, l, r, mid + 1 ,r);
                l = mid + 1;
            }
        }
        printf("flag1 = %d, cnt1 = %d\n", flag1, cnt1);
        printf("flag2 = %d, cnt2 = %d\n", flag2, cnt2);
    }
    return 0;
}
