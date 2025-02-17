/*************************************************************************
	> File Name: 1.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 07:51:21 PM CST
 ************************************************************************/

#include<stdlib.h>
#include<iostream>
using namespace std;

int main () {
    int A[3];
    scanf("%d %d %d", &A[0], &A[1], &A[2]);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2 - i; j++) {
            if(A[j] > A[j+1]){
                A[j] ^= A[j+1];
                A[j+1] ^= A[j];
                A[j] ^= A[j+1];
            }
        }
    }
    if(A[0]*A[1]==A[2]) printf("Yes\n");
    else printf("No\n");
    return 0;
}
