/*************************************************************************
	> File Name: 16.HZOJ-453-1.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 09:55:07 AM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
using namespace std;

int n, k;
int arr[10000];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int c = 1,f = 0;
    for(int i = 0; 1 ; i++){
        if(arr[i] != arr[i+1]) c++;
        if(c == k) {
               f =i+1;
               break;
           }
    }
    cout << arr[f] << endl;

    return 0;
}
