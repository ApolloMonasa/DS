/*************************************************************************
	> File Name: 3.A.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 02:35:40 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int chinese, math, english;
    int totalScore, chineseMathSum, chineseMathMax;
    int originalIndex;
    
    Student(int c, int m, int e, int index) {
        chinese = c;
        math = m;
        english = e;
        totalScore = c + m + e;
        chineseMathSum = c + m;
        chineseMathMax = max(c, m);
        originalIndex = index;
    }
};

// 排序规则
bool compare(const Student& a, const Student& b) {
    if (a.totalScore != b.totalScore) return a.totalScore > b.totalScore;
    if (a.chineseMathSum != b.chineseMathSum) return a.chineseMathSum > b.chineseMathSum;
    if (a.chineseMathMax != b.chineseMathMax) return a.chineseMathMax > b.chineseMathMax;
    return false;
}

int main() {
    int N;
    cin >> N;
    
    vector<Student> students;
    
    // 输入学生成绩
    for (int i = 0; i < N; i++) {
        int c, m, e;
        cin >> c >> m >> e;
        students.push_back(Student(c, m, e, i));
    }
    
    // 排序学生
    sort(students.begin(), students.end(), compare);
    
    // 排名结果
    vector<int> ranks(N);
    int currentRank = 1;
    
    for (int i = 0; i < N; i++) {
        if (i > 0 && students[i].totalScore == students[i-1].totalScore &&
            students[i].chineseMathSum == students[i-1].chineseMathSum &&
            students[i].chineseMathMax == students[i-1].chineseMathMax) {
            // 当前学生与前一个学生并列
            ranks[students[i].originalIndex] = ranks[students[i-1].originalIndex];
        } else {
            // 当前学生排名
            ranks[students[i].originalIndex] = currentRank;
        }
        
        // 下一名的排名
        currentRank = (i + 1) + 1;
    }
    
    // 输出排名
    for (int i = 0; i < N; i++) {
        cout << ranks[i] << endl;
    }
    
    return 0;
}

