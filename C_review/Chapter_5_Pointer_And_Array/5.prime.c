/*************************************************************************
	> File Name: 5.prime.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 21 Feb 2025 07:28:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int prime[100] = {0};

void init_prime(int n) {
    prime[0] = prime[1] = 1;
    for(int i = 2; i * i <= n; i++) {
        if (prime[i]) continue;
        printf("%d is prime : ", i);
        for (int j = i * i; j <= n; j += i) {
            prime[j] = 1;
            printf(" %d", j);
        }
        printf("\n");
    }
}

int main() {
    init_prime(50);
    int x;
    while(~scanf("%d", &x)) {
        printf("prime[%d] = %d\n", x, prime[x]);
    }
    return 0;
}
