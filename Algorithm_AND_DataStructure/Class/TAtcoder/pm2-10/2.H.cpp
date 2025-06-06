/*************************************************************************
	> File Name: 2.H.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 02:18:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
typedef struct Dot {
    long long x, y;
} Dot;

Dot dots[700];

int check_dots(long long x1, long long y1,long long x2, long y2) {
    int cnt = 0;
    for(int i = 0; i < n; i++){
        //(y-y1)/(x-x1) == (y - y2)/(x - x2)
        //(y-y1)*(x-x2) == (y-y2)*(x-x1)
        long long x = dots[i].x;
        long long y = dots[i].y;
        if((y-y1)*(x-x2)==(y-y2)*(x-x1)) cnt++;
    }
    return cnt;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dots[i].x >> dots[i].y;
    }

    int max_dots_num = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int ret = check_dots(dots[i].x, dots[i].y, dots[j].x, dots[j].y);
            if(ret > max_dots_num) max_dots_num = ret;
        }
    }
    cout << max_dots_num << endl;
    
    return 0;
}

