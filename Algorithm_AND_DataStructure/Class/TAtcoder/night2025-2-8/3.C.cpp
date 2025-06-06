/*************************************************************************
	> File Name: 3.C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:20:23 PM CST
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main () {
    int N;
    scanf("%d", &N);
    int Q[N + 1], P[N + 1];
    for (int i = 1; i <= N; i++) scanf("%d", &P[i]);
    getchar();
    for (int i = 1; i <= N; i++) scanf("%d", &Q[i]);
    for (int i = 1; i <= N; i++) {
        if(i > 1) printf(" ");
        for(int j = 1; j <= N; j++){
            if(Q[j] == i) printf("%d", Q[P[j]]);
        }
    }
    printf("\n");
    return 0;
}
