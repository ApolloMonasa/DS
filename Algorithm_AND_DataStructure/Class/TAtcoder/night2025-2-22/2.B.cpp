/*************************************************************************
	> File Name: 2.B.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: arrat 22 Feb 2025 08:05:45 PM CarrT
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

int main() {
    int n;
    cin >> n;
    int vis[n];
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vis[i] = arr[i].size();
    }
    for(int i = 1; i < 51; i++) {
        for (int j = 0; j < n; j++) {
            if(vis[j] == i) cout << arr[j];
        }
    }
    cout << endl;
    
    return 0;
}
