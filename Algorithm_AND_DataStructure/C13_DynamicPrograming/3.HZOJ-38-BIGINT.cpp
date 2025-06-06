/*************************************************************************
	> File Name: 2.HZOJ-38-2.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Feb 2025 04:53:11 PM CST
 ************************************************************************/

#include<vector>
#include<iostream>
using namespace std;

class BIGINT : public vector<int> {
public :
    BIGINT() { push_back(0); }
    BIGINT(int x) {
        this->push_back(x);
        process_digit();
    }

    BIGINT &operator+=(const BIGINT &a) {
        for(int i = 0; i < a.size(); i++) {
            if(i + 1 > size()) push_back(a[i]);
            else at(i) += a[i];
        }
        process_digit();
        return *this;
    }

    BIGINT operator+(const BIGINT &a) {
        BIGINT ret(*this);
        ret += a;
        return ret;
    }

    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if(at(i) < 10) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};


BIGINT f[105] = {0};

ostream &operator<<(ostream &out, const BIGINT &a) {
    for(int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
