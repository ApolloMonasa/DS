/*************************************************************************
	> File Name: 7.random_data.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 02:55:07 PM CST
 ************************************************************************/

#include<time.h>
#include<iostream>
using namespace std;


int main() {
    printf("26\n");
    srand(time(0));
    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", 'a' + i, rand() % 100000);
    }
    return 0;
}
