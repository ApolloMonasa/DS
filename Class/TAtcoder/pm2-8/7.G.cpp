/*************************************************************************
	> File Name: 7.G.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 07:07:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
int can_be_cut(int x, int y, int z);

int main () {
    static int n, m, k;
    cin >> n >> m >> k;
    static int cub[n][m][k] = {0};
    //init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                if(i == 0 || j == 0 || x == 0) cub[i][j][x] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                if (i == 0 && j == 0 && x == 0 && can_be_cut(i, j, x)) cub[i][j][x] = 0;
            }
        }
    }
    printf("%d\n", n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                if (i == 0 && j == 0 && x == 0 && cub[i][j][x]) printf("%d %d %d\n", i, j, x);
            }
        }
    }

    return 0;
}
int can_be_cut(int x, int y, int z) {
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < n; i++) {
        s1 += cub[i][y][z];
    }
    for (int i = 0; i < m; i++) {
        s2 += cub[x][i][z];
    }
    for (int i = 0; i < k; i++) {
        s3 += cub[x][y][i];
    }
    int ret = s1 && s2 && s3;
    return ret;

}
