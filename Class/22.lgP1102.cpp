/*************************************************************************
	> File Name: 22.lgP1102.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 10:11:22 AM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
long long n, c, cnt = 0;
long long a[200000];
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if((a[i]-a[j]>0)?(a[i]-a[j]):(a[j]-a[i] == c)) {
                cnt++;
                printf("|%lld - %lld| == %lld\n", a[i], a[j], c);

            }
        }
    }
    cout << cnt << endl;
    return 0;
}
