/*************************************************************************
	> File Name: 3.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 02:11:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cmath>

int n, k, cnt = 0;
int arr[20];
int result[20];

int IsPrime(int k){
    int c = 0;
    for(int i = 1; i <= sqrt(k); i++){
        if(k % i == 0) c++;
    }
    if(c > 1) return 0;
    else return 1;
}

void recur(int index, int n, int k, int start, int *arr, int *result) {
    if(index == k) {
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += result[i];
        }
        if(IsPrime(sum)) cnt++;
    }
    for(int i = start; i < n; i++) {
        result[index] = arr[i];
        recur(index+1,n, k, i + 1, arr, result);
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    recur(0, n , k, 0, arr, result);
    cout << cnt << endl;
    return 0;
}
