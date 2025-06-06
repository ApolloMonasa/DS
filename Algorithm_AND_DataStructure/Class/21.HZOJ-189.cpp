/*************************************************************************
	> File Name: 21.HZOJ-189.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 09:54:56 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, k;
int find(int i, int *a, int n){
    int l = 1, r = n;
    while(r - l >= 0){
        int mid = (r + l) / 2;
        if(a[mid]>i) r = mid - 1;
        if(a[mid]<i) l = mid + 1;
        if(a[mid] == i) return mid;
    }
    return 0;
}

int main(){
    cin >> n >> k;
    int arr1[n + 1];
    int arr2[k + 1];
    for(int i = 1; i <= n; i++) {
        cin >> arr1[i];
    }
    for(int i = 1; i <= k; i++) {
        cin >> arr2[i];
    }
    for(int i = 1; i <= k; i++) {
        if(i > 1) cout << " ";
        cout << find(arr2[i], arr1, n);
    }
    cout << endl;

}
