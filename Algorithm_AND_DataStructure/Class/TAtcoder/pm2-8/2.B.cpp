/*************************************************************************
	> File Name: 2.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 01:52:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;

int is_valid_11_22_substring(char *S, int start, int end) {
    int len = end - start + 1;
    //must odd
    if(len % 2 == 0) return 0;

    int mid = (start + end) / 2;
    //check 1s-string
    for (int i = start; i < mid; i++) {
        if (S[i] != '1') {
            return 0;
        }
    }
    //check /
    if (S[mid] != '/') return 0;
    //check 2s-string
    for (int i = mid + 1; i <= end; i++) {
        if (S[i] != '2') return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    char S[N + 1];
    scanf("%s", S);
    if(N == 1 && S[0] == '/') {
        printf("1\n");
        return 0;
    }

    int max_len = 0;
    int flag = 0;
    //run all might sons
    for (int start = 0; start < N; start++) {
        if(S[start] == '/') flag = 1;
        for (int end = start + 1; end < N; end++) {
            if (is_valid_11_22_substring(S, start, end)) {
                int len = end - start + 1;
                if(len > max_len) {
                    max_len = len;
                }
            }
        }
    }
    if(!max_len && flag) {
        printf("1\n");
        return 0;
    }
    printf("%d\n", max_len);
    return 0;
}
