/*************************************************************************
	> File Name: 17.HZOJ-453-2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 10:10:31 AM CST
 ************************************************************************/

#include<iostream>
#include<inttypes>
using namespace std;

int main() {
    int n, k;    
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int f = 0, min = arr[0];
    for(int j = 0; j < k; j++) {
        for(int i = 0; i < n; i++) {
        if(arr[i] < min) f = i;
        }
    }
}
