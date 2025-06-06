/*************************************************************************
	> File Name: 5.D.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Feb 2025 02:49:04 PM CST
 ************************************************************************/


#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // 用于格式化输出

using namespace std;

// 定义马的可能移动方向
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

vector<vector<int>> minKnightSteps(int n, int m, int x, int y) {
    // 初始化棋盘，-1 表示未访问
    vector<vector<int>> board(n, vector<int>(m, -1));

    // BFS 队列
    queue<pair<int, int>> q;
    q.push({x - 1, y - 1}); // 将起点加入队列（转换为 0-based 索引）
    board[x - 1][y - 1] = 0; // 起点步数为 0

    // BFS 遍历
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int currentX = current.first;
        int currentY = current.second;

        // 遍历所有可能的移动
        for (int i = 0; i < 8; ++i) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            // 检查新位置是否在棋盘内且未被访问
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == -1) {
                board[newX][newY] = board[currentX][currentY] + 1; // 更新步数
                q.push({newX, newY}); // 将新位置加入队列
            }
        }
    }

    return board;
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    // 计算最少步数
    vector<vector<int>> result = minKnightSteps(n, m, x, y);

    // 输出结果，左对齐，宽度为 5
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << left << setw(5) << result[i][j]; // 左对齐，宽度为 5
        }
        cout << endl;
    }

    return 0;
}
