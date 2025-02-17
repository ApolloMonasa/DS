/*************************************************************************
	> File Name: 5.C.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 02:53:18 PM CST
 ************************************************************************/
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// 使用 typedef 或 using 来定义 ll
typedef long long ll;  // 或者 using ll = long long;

ll n, x, y;
typedef struct Dish {
    ll A, B;
} Dish;

int main() {
    cin >> n >> x >> y;
    Dish dishes[n];
    
    // 输入每个菜肴的 A 值
    for(int i = 0; i < n; i++){
        cin >> dishes[i].A;
    }
    
    // 输入每个菜肴的 B 值
    for(int i = 0; i < n; i++){
        cin >> dishes[i].B;
    }
    
    
    int min_cnt = n;
    for(int j = 0; j < 10; j++){
        int used[n] = {0};
        int cnt = 0;
        ll sa = 0, sb = 0;  // sb 声明为 ll 类型
        for(int i = 0; 1; i = rand() % n){
            srand(time(NULL));
            if(used[i]) continue;
            printf("used[%d] = %d\n", i, used[i]);
            cout << j << "i = " << i << endl;
            sa += dishes[i].A;
            sb += dishes[i].B;  // 正确使用 sb
            cnt++;
            used[i] = 1;
            printf("used[%d] = %d\n", i, used[i]);
            if(sa > x || sb > y) break;
        }
        if(cnt < min_cnt) min_cnt = cnt;
    }
    cout << min_cnt << endl;
    return 0;
}

