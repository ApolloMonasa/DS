/*************************************************************************
	> File Name: 5.Dfinal.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 03:07:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_FLOWER_POT 100

int q, t, h, op, index = 0;
int total_add = 0;  // 记录所有花盆的累加增量
vector<int> POTS(MAX_FLOWER_POT, 0);

int main() {
    cin >> q;
    while(q--) {
        cin >> op;
        if(op == 1) {
            POTS[index] = 1;  // 新建一个花盆
            index++;
        } else if(op == 2) {
            cin >> t;
            total_add += t;  // 直接更新总增量
        } else if(op == 3) {
            cin >> h;
            int count = 0;
            for(int i = 0; i < index; i++) {
                // 检查是否符合删除条件，考虑增量
                if(POTS[i] + total_add >= h + 1) {
                    POTS[i] = 0;  // 删除该花盆
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}

