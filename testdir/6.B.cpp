#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int B[N];
    long long G[N];

    // 初始化 B 数组为 -1
    for (int i = 0; i < N; i++) {
        B[i] = -1;
    }

    // 输入 G 数组
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }

    // 计算 B 数组
    for(int i = 1; i < N; i++){
        for(int j = i-1; j >= 0; j--){
            if(G[j] == G[i]) {
                B[i] = j + 1;
                break;  // 找到第一个匹配后立即跳出循环
            }
        }
    }

    // 输出 B 数组
    for(int i = 0; i < N; i++) {
        if(i > 0) cout << ' ';
        cout << B[i];
    }

    return 0;
}
