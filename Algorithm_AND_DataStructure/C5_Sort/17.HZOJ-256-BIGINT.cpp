/*************************************************************************
	> File Name: 16.HZOJ-256.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 18 Mar 2025 05:42:06 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;

class BIGINT : public vector<int> {
public :
    BIGINT(int x) {
        this->push_back(x);
        proccess_digit();
        return ;
    }

    void proccess_digit(){
        for (int i = 0; i < size(); i++) {
            if(at(i) < 10) continue;
            if(i + 1 == size()) this->push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && at(size() - 1) == 0) this->pop_back();
        return ;
    }
    void operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        proccess_digit();
        return ;
    }
    bool operator>(const BIGINT &a) const {
        if(size() != a.size()) return size() > a.size();
        for (int i = size() - 1; i >= 0; i--) {
            if(at(i) != a[i]) return at(i) > a[i];
        }
        return false;
    }

    BIGINT operator/(int x) {
        BIGINT ret(*this);
        int y = 0;
        for (int i = size() - 1; i >= 0; i--) {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        ret.proccess_digit();
        return ret;
    }
};

ostream &operator<<(ostream &out, const BIGINT &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {cin >> a[i] >> b[i]; ind[i] = i;}
    sort(ind + 1, ind + n + 1, [&](int i, int j) {
        return a[i] * b[i] < a[j] * b[j];
    });
    //change
    BIGINT p = a[0], ans = 0, temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = p / b[ind[i]];
        if(temp > ans) ans = temp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
