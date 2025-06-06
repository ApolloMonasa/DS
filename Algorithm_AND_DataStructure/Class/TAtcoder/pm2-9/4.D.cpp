/*************************************************************************
	> File Name: 4.D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 02:43:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX_FLOWER_POT 100

int q, t, h, op, index = 0;
int POTS[MAX_FLOWER_POT] = {0};
int main(){
    cin >> q;
    while(q--) {
        cin >> op;
        if(op == 1){
            POTS[index] = 1;
            index++;
        } else if(op == 2){
            cin >> t;
            for(int i = 0; i < index; i++) {
                POTS[i] += t;
            }
        } else if(op == 3){
            cin >> h;
            int count = 0;
            for(int i = 0; i < index; i++) {
                if(POTS[i] - 1 >= h){
                    POTS[i] = 0;
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}

