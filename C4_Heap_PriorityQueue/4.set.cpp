/*************************************************************************
	> File Name: 4.set.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 05:28:25 PM CST
 ************************************************************************/

#include<time.h>
#include<set>
#include<iostream>
using namespace std;

void test1() {
    cout << "set base usage\n";
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);//[3]
    cout << s.size() << endl;
    s.insert(4);//[3, 4]
    cout << s.size() << endl;
    s.insert(2);//[2, 3, 4]
    cout << s.size() << endl;
}

void test2() {
    cout << "唯一性测试" << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);//[3]
    cout << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
    
}

void test3() {
    cout << "规避唯一性" << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot++));//[3]
    cout << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4 : " << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4 : " << s.size() << endl;
    
}

void test4() {
    cout << "foreach set item" << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    s.insert(PII(4, tot++));
    s.insert(PII(3, tot++));//[3]
    s.insert(PII(4, tot++));
    for(auto x : s) {
        cout << "(" << x.first << "," << x.second << ")" << endl;
    }
    
}

void test5() {
    cout << "set replace heap : " << endl;
    typedef pair<int, int> PII;
    int tot = 0;
    set<PII> s;
    for(int i = 0; i < 10; i++) {
        s.insert(PII(rand() % 20, tot++));//push
    }
    for(int i = 0; i < 4; i++) {
        cout << "s.begin() = " << s.begin()->first << endl;
        s.erase(s.begin());//pop
    }
    return ;
}

int main(){
    srand(time(0));
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
