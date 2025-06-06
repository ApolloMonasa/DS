/*************************************************************************
	> File Name: 2.B.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 01 Mar 2025 08:11:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>

int N;
char arr[55][55];
int main() {
    cin >> N;
    for(int i = 1, j; i <= N; i++) {
        j = N + 1 - i;
        if(i > j) break;
        for (int x = i; x <= j; x++){
            for (int y = i; y <= j; y++) {
                arr[x][y] = (i % 2) ? '#' : '.';
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
