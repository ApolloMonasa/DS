/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 01:39:17 PM CST
 ************************************************************************/

#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
    char S[101];
    int count[26];

    //read string
    scanf(" %s", S);

    int len = strlen(S);

    //odd
    if (len % 2) {
        printf("No\n");
        return 0;
    }
    //calculat the characters
    for (int i = 0; i < len; i++) {
        count[S[i] - 'a']++;
    }

    //check the quantity of every single character
    for(int i = 0; i < 26; i++) {
        if(count[i] && count[i] != 2) {
            printf("No\n");
            return 0;
        }
    }

    //check nearest two characters is or not the same
    for(int i = 0; i < len; i+=2) {
        if (S[i] != S[i + 1]) {
            printf("No\n");
            return 0;
        }
    }
    //if OK Yes
    printf("Yes\n");
    return 0;
}
