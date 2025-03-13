/*************************************************************************
	> File Name: 13.sort.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 13 Mar 2025 11:16:40 PM CST
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
#include "0.sort_test.h"

void output(int *arr, int n);
template<typename T>
int test_array() {
    printf("test array:\n");
    //sort array
    int *arr = getRandomData(10);
    output(arr, 10);
    sort(arr, arr + 10);//[)
    output(arr, 10);
    sort(arr, arr + 10, greater<int>());   
    output(arr, 10);
    return 0;
}

void output(vector<T> &arr);

int test_vector() {
    printf("test vector :\n");
    //sort vector
    vector<int> arr;
    for (int i = 0; i < 10; i++) arr.push_back(rand() % 10000);
    output(arr);
    sort(arr.begin(), arr.end());
    output(arr);
    sort(arr.begin(), arr.end(), greater<int>());
    output(arr);
    return 0;
}

struct Data {
    int x;
    int y;
};

ostream &operator<<(ostream &out, const Data &d) {
    out << "(" << d.x << "," << d.y << ")";
    return out;
}

void test_self() {
    printf("test self : \n");
    vector<Data>arr;
    for (int i = 0; i < 10; i++) {
        Data d;
        d.x = rand() % 10, d.y = rand() % 10;
        arr.push_back(d);
    }
    output(arr);
    return ;
}


int main() {
    test_array();
    test_vector();
    return 0;
}

template<typename T>
void output(vector<T> &arr) {
    printf("arr[%lu] = ", arr.size());
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

void output(int *arr, int n) {
    printf("arr[%d] = ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}
