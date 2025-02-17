/*************************************************************************
	> File Name: 2.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:12:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    int len = S.length(), ans = 0;

    for (int i = 1; i < len - 1; i++) {
        if(S[i] == 'B'){
            for(int j = 1;i+j<len && i-j>=0 ; j++){
                if(S[i-j] == 'A' && S[i+j] == 'C') ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
