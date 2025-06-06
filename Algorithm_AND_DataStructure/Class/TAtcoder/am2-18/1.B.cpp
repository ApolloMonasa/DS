/*************************************************************************
	> File Name: 1.B.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 10:44:42 AM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long mergeAndCount(vector<pair<int, int>>& arr, int left, int mid, int right) {
    vector<pair<int, int>> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].second <= arr[j].second) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }

    return invCount;
}

long long countInversions(vector<pair<int, int>>& arr, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += countInversions(arr, left, mid);
        invCount += countInversions(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

long long countContainedPairs(vector<pair<int, int>>& arr) {
    long long count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int low = i + 1, high = n - 1;
        int target = arr[i].second;
        int result = i;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].second < target) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        count += (result - i);
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> people(n);
        for (int i = 0; i < n; i++) {
            cin >> people[i].first >> people[i].second;
        }

        // 按照起点排序
        sort(people.begin(), people.end());

        // 计算反向移动的相遇
        long long reverseGreetings = countInversions(people, 0, n - 1);

        // 计算同向移动但路径包含的相遇
        long long containedGreetings = countContainedPairs(people);

        // 总相遇次数
        long long totalGreetings = reverseGreetings + containedGreetings;

        cout << totalGreetings << '\n';
    }

    return 0;
}
